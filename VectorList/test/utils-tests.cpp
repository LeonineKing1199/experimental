#include "test.hpp"

void utils_tests(void)
{
  std::cout << "Running Utils Tests" << std::endl;
  /*
   * We should be able to get a pair of managed pointers
   * to suitable allocations
   * */
  const std::size_t size = 16;
  auto block{regulus::utils::alloc_block<int>(size)};
  
  //TODO: Rewrite these tests with iterators
  const auto elements = block.first.get();
  const auto locks = block.second.get();
  
  const auto adjusted_n = size + 2;
  
  assert(
    elements[0].get_state() == regulus::element_state::boundary);
    
  assert(
    elements[adjusted_n - 1].get_state() == regulus::element_state::boundary);
    
  assert(
    (elements[0].get_next() == 
      decltype(elements[0].get_next()){nullptr, nullptr}));
      
  assert(
    (elements[adjusted_n - 1].get_next() == 
      decltype(elements[0].get_next()){nullptr, nullptr}));
  
  for (std::size_t i = 1; i < size; ++i) {
    assert(elements[i].get_state() == regulus::element_state::free);
    assert(
      (elements[i].get_next() == 
        typename regulus::element<int>::next_type{elements + i + 1, locks + i + 1}));
  }
  
  assert(elements[size].get_state() == regulus::element_state::free);
  assert(
      (elements[size].get_next() == 
        typename regulus::element<int>::next_type{nullptr, nullptr}));
}
