#ifndef REGULUS_TEST_HELPERS_HPP_
#define REGULUS_TEST_HELPERS_HPP_

#include <iostream>

template <typename F>
void describe(const char* msg, F f)
{
  std::cout << msg << std::endl;
  f();
  std::cout << "\n";
}

template <typename F>
void it(const char* msg, F f)
{
  describe((std::string{'\t'} + msg).c_str(), f);
}

#endif // REGULUS_TEST_HELPERS_HPP_
