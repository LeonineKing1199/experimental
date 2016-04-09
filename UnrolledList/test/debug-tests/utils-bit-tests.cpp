#include "debug-tests.hpp"

#include "../../helpers/utils.hpp"

void utils_bit_tests(void)
{
  describe("The utility bit-wise functions", []() -> void
  {
    it(
      "should be able to accurately count the number of set bits in a number", 
      []() -> void
    {
      int i = 2;
      assert(regulus::bit_utils::pop_count(i) == 1);
      
      i = 41;
      assert(regulus::bit_utils::pop_count(i) == 3);
      
      i = 0b1110101;
      assert(regulus::bit_utils::pop_count(i) == 5);
    });
    
    it("should be able to find the first set bit", []() -> void
    {      
      for (int i = 0; i < 32; ++i) {
        const uint32_t val = (1 << i) + (i == 31 ? 0 : 1 << (i + 1));
        assert(regulus::bit_utils::find_first_set(val) == i);
      }
    });
  });
}
