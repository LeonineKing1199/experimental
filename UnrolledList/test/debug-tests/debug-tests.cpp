#include "debug-tests.hpp"

void debug_tests(void)
{
  node_tests();
  utils_bit_tests();
  
  std::cout << num_tests << " tests passed!" << std::endl;
}
