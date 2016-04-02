#include "test.hpp"

void spinlock_tests(void)
{
  std::cout << "Running SpinLock Tests" << std::endl;
  /*
   * We should be able to forward arguments
   * */
   std::atomic_flag l{ATOMIC_FLAG_INIT};
   auto sum = regulus::utils::spinlock_exec([](int a, int b, int c) -> int {
     return a + b + c;
   }, l, 1, 2, 3);
   
   assert(sum == 6);
}
