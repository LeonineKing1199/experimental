#include <cmath>

#include "utils.hpp"

namespace regulus
{
  /*
   * This code was taken directly from:
   * http://stackoverflow.com/questions/109023/how-to-count-the-number-of-set-bits-in-a-32-bit-integer
   * */
  int pop_count(uint32_t i)
  {
    i = i - ((i >> 1) & 0x55555555);
    i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
    return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
  }
  
  int ffs(uint32_t i)
  {
    return std::log2(i & -1) + 1;
  }
}
