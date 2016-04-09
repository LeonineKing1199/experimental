#include "utils.hpp"

namespace regulus
{
  namespace bit_utils
  {
    /*
     * This code was taken directly from:
     * http://stackoverflow.com/questions/109023/how-to-count-the-number-of-set-bits-in-a-32-bit-integer
     * 
     * I kind of copy-pasted this without much thought...
     * */
    int pop_count(uint32_t i)
    {
      i = i - ((i >> 1) & 0x55555555);
      i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
      return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
    }
    
    // dummy function used to initialize the table
//    void build_debruijn32_table(void)
//    {
//      for (int i = 0; i < 32; ++i) {
//        debruijn_index[((debruijn32 << i) >> 27)] = i;
//      }
//    }
    
    int find_first_set(uint32_t b)
    {
      if (b == 0)
        return -1;
        
      b &= -b;
      b *= debruijn32;
      b >>= 27;
      return debruijn_index[b];      
    }    
  }
}
