#ifndef REGULUS_TEST_HELPERS_HPP_
#define REGULUS_TEST_HELPERS_HPP_

#include <iostream>
#include <ctime>
#include <chrono>
#include <iomanip> 
 
extern int num_tests;

template <typename F>
void describe(const char* msg, F f)
{
  std::cout << msg << std::endl;
  f();
  std::cout << std::endl;
}

template <typename F>
void it(const char* msg, F f)
{
  ++num_tests;
  std::cout << (std::string{'\t'} + msg);
  
  std::clock_t c_start = std::clock();
  auto t_start = std::chrono::high_resolution_clock::now();  
  
  f();

  std::clock_t c_end = std::clock();
  auto t_end = std::chrono::high_resolution_clock::now();  

  std::cout << 
    std::fixed <<
    std::setprecision(2) << " (cpu: " << 
    1000.0 * (c_end-c_start) / CLOCKS_PER_SEC << " ms" <<
    " , wall: " << 
    std::chrono::duration<double, std::milli>(t_end-t_start).count() << " ms" <<
    std::endl;
}

#endif // REGULUS_TEST_HELPERS_HPP_
