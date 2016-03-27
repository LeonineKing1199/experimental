#include "test.hpp"

void iterator_tests(void)
{
  std::cout << "Running Iterator Tests" << std::endl;
  
  // initialize a new block of 16 ints
  const int size = 16;
  auto block{regulus::utils::alloc_block<int>(size)};
  
  auto elements = block.first.get();
  auto locks = block.second.get();
    
  for (int i = 0; i < size; ++i) {
    elements[i + 1].set_data(i);
  }

  // declare an iterator to the first element as well as a
  // null iterator
  regulus::iterator<int> it{elements + 1, locks + 1};
  decltype(it) end{nullptr, nullptr};
  
  // the iterator should be forward iterable
  // and comparable
  int i = 0;
  
  if (it != end) assert(!(it == end));
  else assert(!(it != end));
  
  while (it != end) {
    assert(*it == i);
    ++i;
    ++it;
  }
  
  assert(i == size);
  
  // the iterator should be backward iterable
  regulus::iterator<int> bk{elements + size, locks + size};
  
  while (bk != end) {
    assert(*bk == (i - 1));
    --i;
    --bk;
  }
  
  assert(i == 0);
}
