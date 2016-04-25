#ifndef REGULUS_UNROLLED_LIST_TEST_HPP_
#define REGULUS_UNROLLED_LIST_TEST_HPP_

#include <iostream>
#include <cassert>

#include "../include/unrolled_list.hpp"

void test_suite(void);
void unrolled_list_tests(void);
void iterator_tests(void);

template <typename F>
void describe(const char* str, F f)
{
  std::cout << str << std::endl;
  f();
  std::cout << std::endl;
}

template <typename F>
void it(const char* str, F f)
{
  std::cout << "\t" << str;
  f();
  std::cout << std::endl;
}

#endif // REGULUS_UNROLLED_LIST_TEST_HPP_
