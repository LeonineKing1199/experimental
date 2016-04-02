#ifndef VECTORLIST_UTILS_HPP_
#define VECTORLIST_UTILS_HPP_

#include "../include/element.hpp"

namespace regulus
{
  template <typename T> class vector_list;
  
  namespace utils
  {
    template <typename T>
    auto alloc_block(const std::size_t n) -> typename vector_list<T>::block
    {
      const auto adjusted_n = n + 2;
      
      std::unique_ptr<element<T>[]> elements{new element<T>[adjusted_n]};
      std::unique_ptr<std::atomic_flag[]> locks{new std::atomic_flag[adjusted_n]{ATOMIC_FLAG_INIT}};
      
      // the first and last elements are both boundaries
      elements[0].set_state(element_state::boundary);
      elements[adjusted_n - 1].set_state(element_state::boundary);
      elements[0].set_boundary(nullptr, nullptr);
      elements[adjusted_n - 1].set_boundary(nullptr, nullptr);
      
      // set the internal free list of the block
      for (std::size_t i = 1; i < n; ++i) {
        const auto idx = i + 1;
        elements[i].set_next(elements.get() + idx, locks.get() + idx);
      }
      
      elements[n].set_state(element_state::free);
      
      return std::move(
        typename vector_list<T>::block{
          std::move(elements), std::move(locks), n});
    }
    
    /*
     * Takes block A and links its end
     * to the beginning of block B and
     * vice versa
     * */
    template <typename T>
    void link_blocks(
        typename vector_list<T>::block& a, typename vector_list<T>::block& b)
    {
      a.elements[a.size + 1].set_boundary(b.elements.get(), b.locks.get());
      b.elements[0].set_boundary(
        a.elements.get() + a.size + 1, a.locks.get() + a.size + 1);
    }
  }
}

#endif // VECTORLIST_UTILS_HPP_
