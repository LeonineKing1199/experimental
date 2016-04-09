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
      assert(regulus::pop_count(i) == 1);
      
      i = 41;
      assert(regulus::pop_count(i) == 3);
      
      i = 0b1110101;
      assert(regulus::pop_count(i) == 5);
    });
    
    it("should be able to find the first set bit", []() -> void
    {
      int i = 2;
      assert(regulus::ffs(i) == 1);
    });
  });
}
