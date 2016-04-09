#ifndef REGULUS_UTILS_HPP_
#define REGULUS_UTILS_HPP_

#include <cstdint>

namespace regulus
{
  namespace bit_utils
  {
    int pop_count(uint32_t i);

    /*
     * This code was taken from:
     * http://supertech.csail.mit.edu/papers/debruijn.pdf
     * */
    
    /* debruijn32 = 0000 0111 0111 1100 1011 0101 0011 0001 */  
    #define debruijn32 0x077CB531U
    
    /* table to convert debruijn index to standard index */
    static const int debruijn_index[32] = 
    {
      0, 1, 28, 2, 29, 14, 24, 3, 30, 22, 20, 15, 25, 17, 4, 8, 
      31, 27, 13, 23, 21, 19, 16, 7, 26, 12, 18, 6, 11, 5, 10, 9
    };
    
    void build_debruijn32_table(void);
    int find_first_set(uint32_t b);
  }
}

#endif // REGULUS_UTILS_HPP_
