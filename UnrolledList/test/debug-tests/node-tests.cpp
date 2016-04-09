#include "debug-tests.hpp"
#include "../helpers/helpers.hpp"
#include "../../include/node.hpp"

void node_tests(void)
{
  describe("The node class", []() -> void 
  {
    it("should default to a size of zero", []() -> void
    {
      regulus::node<int> n;
      assert(n.size() == 0);
    });
    
    
  });
}
