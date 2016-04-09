#ifndef VECTORLIST_HPP_
#define VECTORLIST_HPP_

#include "globals.hpp"
#include "../helpers/utils.hpp"
#include "../iterator/iterator.hpp"
#include "../helpers/spinlock_exec.hpp"

namespace regulus
{
  // forward declaration
  template <typename T> class element;
  
  /*
   * This is our main class
   * 
   * We manage a doubly-linked list of "blocks" which
   * contain "elements". The container should be 
   * bi-directionally iterable and completely thread-safe.
   * */
  template <typename T>
  class vector_list
  {
  public:
    typedef element<T>* element_ptr;
    typedef std::atomic_flag* lock_ptr;
    typedef std::pair<element_ptr, lock_ptr> next_type;
    typedef std::unordered_map<std::thread::id, next_type> free_lists;
    typedef std::size_t size_type;
    typedef iterator<T> iter;
    
    struct block
    {
      std::unique_ptr<element<T>[]> elements;
      std::unique_ptr<std::atomic_flag[]> locks;
      size_type size;
    };
    
  private:
    std::list<block> blocks_;
    free_lists fl_;
    size_type size_;
    size_type capacity_;
    size_type block_size_;
    std::atomic_flag lock_;
    
    std::thread::id get_tid(void) const
    {
      return std::this_thread::get_id();
    }
    
    void increment_size(size_type n)
    {
      const auto inc_size = [this](auto m) -> void {
        size_ += m;
      };
      
      utils::spinlock_exec(inc_size, lock_, n);
    }
    
    void decrement_size(size_type n)
    {
      utils::spinlock_exec([this](auto m) -> void {
        size_ -= m;
      }, lock_, n);
    }
    
    next_type push_new_block(const size_type size)
    {
      assert(size > 0);
      
      block b = utils::alloc_block<T>(size);
      
      return utils::spinlock_exec([this](block&& blk, size_type sz) -> next_type {
        if (blocks_.size() > 0)
          utils::link_blocks<T>(blocks_.back(), blk);
          
        blocks_.push_back(std::move(blk));
        capacity_ += sz;
        block_size_ += 16;
        
        return next_type{blocks_.back().elements.get(), blocks_.back().locks.get()};
      }, lock_, std::move(b), size);
    }
    
    next_type get_free_list(void)
    {
      return utils::spinlock_exec([this](void) -> next_type {
        return fl_[get_tid()];
      }, lock_);
    }    
    
  public:
    vector_list(void)
      : size_{0}
      , capacity_{0}
      , block_size_{16}
      , lock_{ATOMIC_FLAG_INIT}
    {
      auto nt = push_new_block(block_size_);
      
      assert(nt.first != nullptr);
      assert(nt.second != nullptr);
      assert(nt.first->get_state() == element_state::boundary);
      
      fl_[get_tid()] = next_type{nt.first + 1, nt.second + 1};
    }
    
    size_type size(void) const
    {
      return size_;
    }
    
    size_type capacity(void) const
    {
      return capacity_;
    }
    
    template <typename ...Args>
    iter emplace(Args&&... args)
    {
      next_type nt = get_free_list();
      element_ptr& el = std::get<element_ptr>(nt);
      lock_ptr& l = std::get<lock_ptr>(nt);
            
      if (el == nullptr) {
        auto new_pair = push_new_block(block_size_);
        
//        utils::spinlock_exec([&new_pair](void) -> void {
//          assert(new_pair.first->get_state() == element_state::boundary);
//          assert((new_pair.first + 1)->get_state() == element_state::free);          
//        }, lock_);
        
        nt = next_type{new_pair.first + 1, new_pair.second + 1};
      }
      
      assert(el != nullptr);
      
      //utils::spinlock_exec([this, el, l, &args...](void) -> void {
        //fl_[get_tid()] = utils::spinlock_exec([el, l, &args...](void) -> next_type {
          //assert(el->get_state() != element_state::boundary);
          
          next_type next = el->get_next();
          el->set_data(std::forward<Args>(args)...);
          //return next;
        //}, *l);
        fl_[get_tid()] = next;
        ++size_;
      //}, lock_);
            
      return iter{el, l};
    }
    
    iter begin(void)
    {
      assert(blocks_.size() > 0);
      
      block& b = blocks_.front();
      element_ptr el = b.elements.get();
      lock_ptr l = b.locks.get();
      
      iter it{el + 1, l + 1};
      
      if (it.get_state() != element_state::alive)
        ++it;
      
      return it;
    }
    
    iter end(void) const
    {
      return iter{};
    }
        
    iter rbegin(void)
    {
      assert(blocks_.size() > 0);
      
      block& b = blocks_.back();
      element_ptr el = b.elements.get();
      lock_ptr l = b.locks.get();
      size_type size = b.size;
      
      iter it{el + size, l + size};
      
      if (it.get_state() != element_state::alive) {
        --it;
      }
        
      return it;
    }
    
    iter rend(void) const
    {
      return iter{};
    }
    
    void remove(iter& it)
    {
      it.set_next(get_free_list());
    }
  };  
}

#endif // VECTORLIST_HPP_
