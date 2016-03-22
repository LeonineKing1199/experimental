#ifndef VECTORLIST_HPP_
#define VECTORLIST_HPP_

#include "globals.hpp"
#include "../iterator/iterator.hpp"

namespace regulus
{
  template <typename T>
  class vector_list
  {
  private:
    std::size_t size_;
    std::size_t capacity_;
  };  
}

#endif // VECTORLIST_HPP_
