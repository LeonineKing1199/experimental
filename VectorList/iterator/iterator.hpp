#ifndef VECTORLIST_ITERATOR_HPP_
#define VECTORLIST_ITERATOR_HPP_

#include <atomic>

#include "../helpers/spinlock_exec.hpp"

namespace regulus
{
  template <typename T> class element;

  template <typename T>
  class iterator
  {
  private:
    element<T>* element_;
    std::atomic_flag* lock_;

    void step()
    {
      
    }
    
  public:
    iterator(element<T>* el = nullptr, std::atomic_flag* lock = nullptr)
      : element_{el}
      , lock_{lock}
      {}
      

  }; 
}

#endif // VECTORLIST_ITERATOR_HPP_
