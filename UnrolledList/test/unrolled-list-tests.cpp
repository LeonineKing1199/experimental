#include <iostream>

#include "test.hpp"

void unrolled_list_tests(void)
{
  describe("Regulus' unrolled list implementation", [](void) -> void 
  {
    it("should be constructible", [](void) -> void
    {
      regulus::unrolled_list<int> list;
      
      assert(list.size() == 0);
    });
    
    it("should be insertable", [](void) -> void
    {
      regulus::unrolled_list<int> list;
      auto it = list.begin();
      auto new_it = list.emplace(it, 1337);
      
      assert(new_it == list.begin());
      assert(*new_it == 1337);
      
      new_it = list.emplace(new_it, 0);
      assert(*new_it == 0);
      assert(new_it == list.begin());
      
      for (int i = 0; i < 64; ++i) {
        new_it = list.emplace(new_it, i);
        assert(new_it == list.begin());  
      }
    });
  });
}
