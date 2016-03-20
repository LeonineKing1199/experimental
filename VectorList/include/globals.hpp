#ifndef VECTORLIST_GLOBALS_HPP_
#define VECTORLIST_GLOBALS_HPP_

#include <atomic>
#include <utility>
#include <cassert>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <memory>

namespace regulus
{
  enum element_state { undefined, free, alive, boundary };
}

#endif // VECTORLIST_GLOBALS_HPP_
