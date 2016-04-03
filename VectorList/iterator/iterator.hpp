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
        
    template <typename F>
    void step(F forward_or_backward)
    {
      const auto state = get_state();
      
      if (state == element_state::boundary) {
        auto next_block = 
          utils::spinlock_exec([this](void) -> typename element<T>::next_type {
            return element_->get_next();
          }, *lock_);
          
          element_ = std::get<decltype(element_)>(next_block);
          lock_ = std::get<decltype(lock_)>(next_block);
          
          if (element_ == nullptr) {
            return;
          }
      }
      
      forward_or_backward();
    }
    
    template <typename F>
    void find_alive_in_direction(F forward_or_backward)
    {
      step(forward_or_backward);
      
      while (get_state() != element_state::alive) {
        step(forward_or_backward);
  
        if (element_ == nullptr) {
          return;
        }
      }      
    }
    
    void find_next_alive(void)
    {
      find_alive_in_direction([this](void) -> void { forward(); });
    }
    
    void find_prev_alive(void)
    {
      find_alive_in_direction([this](void) -> void { backward(); });
    }
    
  public:
    iterator(element<T>* el = nullptr, std::atomic_flag* lock = nullptr)
      : element_{el}
      , lock_{lock}
      {}
    
      element_state get_state(void)
      {
        assert(lock_ != nullptr);
        return utils::spinlock_exec([this](void) -> element_state {
          return element_->get_state();
        }, *lock_);
      }
  
      iterator operator++(void) 
      {
        find_next_alive();
        return *this;
      }
      
      iterator operator--(void) 
      {
        find_prev_alive();
        return *this;
      }
      
      T operator*(void) 
      {
        return utils::spinlock_exec([this](void) {
          return element_->get_data();
        }, *lock_);
      }
      
      bool operator==(const iterator& other) {
        const bool val = (element_ == other.element_);
        if (val) {
          assert(lock_ == other.lock_);
        }
        
        return val;
      }
      
      bool operator!=(const iterator& other) {
        return !(*this == other);
      }
  }; 
}

#endif // VECTORLIST_ITERATOR_HPP_
