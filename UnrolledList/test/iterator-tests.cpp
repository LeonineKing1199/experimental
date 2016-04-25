#include <algorithm>
#include <iostream>

#include "test.hpp"

void iterator_tests(void)
{
  describe("The unrolled list iterator", [](void) -> void
  {
    it("should be forward iterable", [](void) -> void
    {
      regulus::unrolled_list<int> list;
      
      auto it = list.emplace(list.begin(), 0);
      int i = 1;
      int const val = 32;
      for (; i < val; ++i) {
        std::cout << "\nInserting " << i << std::endl;
        it = list.emplace(it, i);
        assert(*it == i);
      }
      
      assert(list.size() == val);
            
      for (it = list.begin(); it != list.end(); ++it, --i) {
        std::cout << "\n" << i;
        assert(*it == (i - 1));
      }
    });
    
    it("should allow us to 'hop' from node to node as iterate (forward)", []()
    {
      regulus::unrolled_list<int> list;
      
      auto it = list.emplace(list.begin(), 0);
      
      int const val = 64;
      int i = 1;
      for (; i < val; ++i) {
        it = list.emplace(it, i);
        assert(*it == i);
        assert(*list.begin() == i);
      }
      
      assert(i == val);
      
      for (auto l : list) {
        --i;
        
        std::cout << '\n' << l;
        assert(l == i);
      }
    });
  });
}
