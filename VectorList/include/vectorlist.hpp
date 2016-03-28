#ifndef VECTORLIST_HPP_
#define VECTORLIST_HPP_

#include "globals.hpp"
#include "../helpers/utils.hpp"
#include "../iterator/iterator.hpp"

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
    typedef std::unordered_map<std::thread::id, element_ptr> free_lists;
    
    struct block
    {
      std::unique_ptr<element<T>[]> elements;
      std::unique_ptr<std::atomic_flag[]> locks;
      std::size_t size;
    };
    
    
    
  private:
    std::list<block> blocks_;
    free_lists fl_;
    std::size_t size_;
    std::size_t capacity_;
    std::atomic_flag lock_;
    
    std::thread::id get_tid(void) const
    {
      return std::this_thread::get_id();
    }
    
  public:
    vector_list(void)
      : lock_{ATOMIC_FLAG_INIT}
    {
      block b = utils::alloc_block<T>(16);
      fl_[get_tid()] = b.elements.get() + 1;
      blocks_.push_back(std::move(b));
      size_ = 0;
      capacity_ = 16;
    }
  };  
}

#endif // VECTORLIST_HPP_
