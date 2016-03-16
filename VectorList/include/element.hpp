#ifndef VECTORLIST_ELEMENT_HPP_
#define VECTORLIST_ELEMENT_HPP_

#include "globals.hpp"

namespace regulus
{
  template <typename T>
  class element
  {
  public:
    typedef std::pair<element*, std::atomic_flag*> next_type;
    
  private:
    element_state state_;
    union {
      T data_;
      next_type next_;
    };
    
    void set_state(element_state state)
    {
      if (state_ == element_state::alive)
        data_.~T();
        
      state_ = state;
    }
    
  public:
    element(void) 
      : state_{element_state::undefined}
      , next_{nullptr, nullptr}
    {}
    
    ~element(void)
    {
      if (state_ == element_state::alive) {
        data_.~T();
      }
      
      state_ = undefined; // maybe this is unecessary?
    }
    
    element_state get_state(void) const
    {
      return state_;
    }
    
    T get_data(void) const
    {
      return data_;
    }
    
    next_type get_next(void) const
    {
      return next_;
    }
    
    void set_next(element* next_element, std::atomic_flag* next_lock)
    {
      set_state(element_state::free);
      next_ = {next_element, next_lock};
    }
  };
}

#endif // VECTORLIST_ELEMENT_HPP_
