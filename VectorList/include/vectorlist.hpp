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
    std::atomic_flag lock_;
    
    std::thread::id get_tid(void) const
    {
      return std::this_thread::get_id();
    }
    
    void increment_size(int n)
    {
//      const auto inc_size = [this](size_type m) -> void {
//        size_ += m;
//      };
      
      //utils::spinlock_exec(inc_size, lock_, n);
    }
    
//    void decrement_size(size_type n)
//    {
//      utils::spinlock_exec([this](auto m) -> void {
//        size_ -= m;
//      }, lock_, n);
//    }
    
  public:
    vector_list(void)
      : lock_{ATOMIC_FLAG_INIT}
    {
      block b = utils::alloc_block<T>(16);
      fl_[get_tid()] = next_type{b.elements.get() + 1, b.locks.get() + 1};
      blocks_.push_back(std::move(b));
      size_ = 0;
      capacity_ = 16;
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
    void emplace(Args&&... args)
    {
      auto tid = get_tid();
      next_type nt = fl_[tid];
      element_ptr el = std::get<element_ptr>(nt);
      lock_ptr l = std::get<lock_ptr>(nt);
      
      assert(el != nullptr);
      next_type next = el->get_next();
      
      // I'm hoping the reference collapsing on args
      // preserves r-value-ness.
      utils::spinlock_exec([el, l, &args...](void) -> void {
        el->set_data(std::forward<Args>(args)...);
      }, *l);
      
      fl_[tid] = next;
      
      increment_size(1);
    }
  };  
}

#endif // VECTORLIST_HPP_
