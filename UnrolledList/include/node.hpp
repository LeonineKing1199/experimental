#ifndef REGULUS_NODE_HPP_
#define REGULUS_NODE_HPP_

#include <type_traits>
#include <bitset>

#include "../helpers/utils.hpp"

namespace regulus
{
  static const int node_size = 32;
  
  template <typename T>
  class node
  {
  private:
    typename std::aligned_storage<sizeof(T), alignof(T)>::type data_[node_size];
    uint32_t state_;
    
  public:
    node(void) : state_{0} {}
    
    int size(void) const
    {
      return pop_count(state_);
    }
    
    
  };  
}

#endif // REGULUS_NODE_HPP_
