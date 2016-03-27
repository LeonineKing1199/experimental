#ifndef VECTORLIST_SPINLOCK_EXEC_HPP_
#define VECTORLIST_SPINLOCK_EXEC_HPP_

#include <atomic>

namespace regulus
{
  template <typename T> struct tag {};
  
  template <typename F, typename ...Args>
  void spinlock_helper(F f, std::atomic_flag& lock, tag<void>, Args&&... args)
  {
    while (lock.test_and_set(std::memory_order_acquire)) {
      // spin
    }
    
    f(std::forward<Args>(args)...);
    lock.clear();
  }
  
  template <typename F, typename R, typename ...Args>
  R spinlock_helper(F f, std::atomic_flag& lock, tag<R>, Args&&... args)
  {
    while (lock.test_and_set(std::memory_order_acquire)) {
      // spin
    }
    
    auto&& r = f(std::forward<Args>(args)...);
    lock.clear(std::memory_order_release);
    return r;
  }
  
  template <typename F, typename ...Args>  
  auto spinlock_exec(F f, std::atomic_flag& lock, Args&&... args)
      -> decltype(f())
  {
    return spinlock_helper(f, lock, tag<decltype(f())>{}, std::forward<Args>(args)...);
  }
}

#endif // VECTORLIST_SPINLOCK_EXEC_HPP_