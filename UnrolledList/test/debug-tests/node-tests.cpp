#include <string>

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
    
    it("should be insert-able", []() -> void 
    {
      regulus::node<int> n;
      n.insert(1337);
      assert(n.size() == 1);
    });
    
    it("should call the destructor of its elements", []() -> void
    {
      regulus::node<std::string> n;
      const char* msg = "This is a super secret message";
      n.insert(msg);
      assert(n.size() == 1);
    });
  });
}
