#ifndef VECTORLIST_ITERATOR_HPP_
#define VECTORLIST_ITERATOR_HPP_

#include "../helpers/spinlock_exec.hpp"

namespace regulus
{
  // foward declaration
  template <typename T> class element;

  template <typename T>
  class iterator
  {
  private:
    element<T>* element_;
    std::atomic_flag* lock_;

    void forward(void)
    {
      ++element_;
      ++lock_;
    }
    
    void backward(void)
    {
      --element_;
      --lock_;
    }
    
    element_state get_state(void)
    {
      return spinlock_exec([this](void) -> element_state {
        return element_->get_state();
      }, *lock_);
    }
    
    template <typename F>
    void step(F forward_or_backward)
    {
      const auto state = get_state();
      
      if (state == element_state::boundary) {
        auto next_block = 
          spinlock_exec([this](void) -> typename element<T>::next_type {
            return element_->get_next();
          }, *lock_);
          
          element_ = std::get<decltype(element_)>(next_block);
          lock_ = std::get<decltype(lock_)>(next_block);
      }
      
      forward_or_backward();
    }
    
    void find_next_alive(void)
    {
      const auto step_forward = [this](void) -> void { forward(); };
      step(step_forward);
      
      while (get_state() != element_state::alive) {
        step(step_forward);
      }
    }
    
  public:
    iterator(element<T>* el = nullptr, std::atomic_flag* lock = nullptr)
      : element_{el}
      , lock_{lock}
      {}
      
      void operator++(void) 
      {
        find_next_alive();
      }
      
      T operator*(void) 
      {
        return spinlock_exec([this](void) {
          return element_->get_data();
        }, *lock_);
      }
      
      bool operator==(const iterator& other) {
        const bool val = element_ == other.element_;
        if (val) {
          assert(lock_ == other.lock_);
        }
        
        return val;
      }
      
      bool operator!=(const iterator& other) {
        return *this == other;
      }
  }; 
}

#endif // VECTORLIST_ITERATOR_HPP_
