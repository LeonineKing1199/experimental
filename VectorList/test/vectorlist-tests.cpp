#include "test.hpp"

void vectorlist_tests(void)
{
  std::cout << "Running Vector List Tests" << std::endl;
  
  {
    regulus::vector_list<int> vl;
    const int val = 1337;
    auto it = vl.emplace(val);
    assert(*it == val);
    
    assert(vl.capacity() == 16);
    assert(vl.size() == 1);    
  }
  
  {
    regulus::vector_list<int> vl;
    
    for (int i = 0; i < 64; ++i) {
      std::cout << i << std::endl;
      vl.emplace(i);
    }
  }
}
