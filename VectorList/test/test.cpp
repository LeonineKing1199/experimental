#include "test.hpp"

void test_suite(void)
{
  std::cout << "\nRunning Test Suite\n" << std::endl;
  element_tests();
  utils_tests();
  block_tests();
  iterator_tests();
  vectorlist_tests();
  std::cout << "\nCompleted Successfully!\n" << std::endl;
}

void block_tests(void)
{
//  const int size = 16;
//  typename regulus::element<int>::next_type free_list{nullptr, nullptr};
//  regulus::block<int> b(size, free_list);
}
