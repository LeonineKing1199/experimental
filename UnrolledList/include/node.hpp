#ifndef REGULUS_NODE_HPP_
#define REGULUS_NODE_HPP_

#include <type_traits>

#include "../helpers/utils.hpp"

namespace regulus
{
  static const int node_size = 32;
  
  template <typename T>
  class node
  {
  private:
    std::aligned_storage_t<sizeof(T), alignof(T)> data_[node_size];
    uint32_t state_;
    
  public:
    node(void) : state_{0} {}
    
    ~node(void)
    {
      int i = bit_utils::find_first_set(state_);
      
      if (i == -1) {
        return;
      }  
        
      while (i >= 0)
      {
        reinterpret_cast<const T*>(data_ + i)->~T();
        state_ -= (1 << i);
        
        i = bit_utils::find_first_set(state_);
      }
    }
    
    int size(void) const
    {
      return bit_utils::pop_count(state_);
    }
    
    int capacity(void) const
    {
      return node_size;
    }
    
    template <typename ...Args>
    void insert(Args&&... args)
    {
      const int i = bit_utils::find_first_set(~state_);
      new(reinterpret_cast<T*>(data_ + i)) T{std::forward<Args>(args)...};
      state_ |= (1 << i);
    }
    
    T& operator[](const int idx) const
    {
      return *reinterpret_cast<const T*>(data_ + idx);
    }
  };  
}

#endif // REGULUS_NODE_HPP_
