#ifndef VECTORLIST_TEST_HPP_
#define VECTORLIST_TEST_HPP_

#include "../include/element.hpp"
#include "../helpers/utils.hpp"
#include "../include/block.hpp"
#include "../iterator/iterator.hpp"
#include "../include/vectorlist.hpp"
#include "../helpers/spinlock_exec.hpp"

void test_suite(void);
void element_tests(void);
void utils_tests(void);
void block_tests(void);
void iterator_tests(void);
void vectorlist_tests(void);
void spinlock_tests(void);

#endif // VECTORLIST_TEST_HPP_
