#include "test.hpp"

void test_suite(void)
{
  std::cout << "\nRunning Test Suite\n" << std::endl;
  element_tests();
  utils_tests();
  block_tests();
  std::cout << "Completed Successfully!\n" << std::endl;
}

void element_tests(void)
{
  {
    /*
     * It should be default constructible
     * */
    regulus::element<int> el;
    
    assert(el.get_state() == regulus::element_state::undefined);
    assert((el.get_next() == decltype(el.get_next()){nullptr, nullptr}));
    
    /*
     * We should be able to link two disparate elements
     * */
     decltype(el) el2;
     
     auto el_addr = std::addressof(el);
     auto el2_addr = std::addressof(el2);
     
     el.set_next(el2_addr, nullptr);
     el2.set_next(el_addr, nullptr);
     
     assert(el.get_state() == regulus::element_state::free);
     assert(el2.get_state() == regulus::element_state::free);
     
     assert(
      (el.get_next() == 
        typename regulus::element<int>::next_type{el2_addr, nullptr}));
        
     assert(
      (el2.get_next() == 
        typename regulus::element<int>::next_type{el_addr, nullptr}));
        
    /*
     * We should be able to assign data to an element as well
     * */
     const int val = 1337;
     el.set_data(val);
     
     assert(el.get_data() == val);
     assert(el.get_state() == regulus::element_state::alive);
  }
}

void utils_tests(void)
{
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

void block_tests(void)
{
//  const int size = 16;
//  typename regulus::element<int>::next_type free_list{nullptr, nullptr};
//  regulus::block<int> b(size, free_list);
}

void iterator_tests(void)
{
  regulus::iterator<int> it;
}
