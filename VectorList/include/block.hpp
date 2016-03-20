#ifndef VECTORLIST_BLOCK_HPP_
#define VECTORLIST_BLOCK_HPP_

#include "element.hpp"

namespace regulus
{
  template <typename T>
  class block
  {
  public:
    typedef std::unique_ptr<element<T>[]> element_ptr;
    typedef std::unique_ptr<std::atomic_flag[]> lock_ptr;
    
  private:
    element_ptr elements_;
    lock_ptr locks_;
    std::size_t size_; // not the adjusted size
    
  public:
    block(void)
      : elements_{nullptr}
      , locks_{nullptr}
      , size_{0}
    {}
    
    block(const std::size_t n, typename element<T>::next_type& free_list)
      : elements_{new element<T>[n + 2]}
      , locks_{new std::atomic_flag[n + 2]{ATOMIC_FLAG_INIT}}
      , size_{n}
    {
      const auto adjusted_n = size_ + 2;
      
      // the first and last elements are both boundaries
      elements_[0].set_state(element_state::boundary);
      elements_[adjusted_n - 1].set_state(element_state::boundary);
      
      // set the internal free list of the block
      for (decltype(size_) i = 1; i < size_; ++i) {
        const auto idx = i + 1;
        elements_[i].set_next(elements_.get() + idx, locks_.get() + idx);
      }
      
      // link the last element in the free list to the free list
      // that was passed in
      elements_[size_].set_next(free_list);
      
      // the head of the free list is now this one
      free_list = elements_[1].get_next();
    }
  };
}

#endif // VECTORLIST_BLOCK_HPP_
