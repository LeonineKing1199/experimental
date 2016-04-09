#include "test.hpp"

/*
 * This file is important enough that I'm going to explain it
 * */

void vectorlist_tests(void)
{
  std::cout << "Running Vector List Tests" << std::endl;
  
//  /*
//   * It should be default constructible.
//   * We also expect that we can "emplace" an 
//   * element into the container.
//   * 
//   * The container will have a default capacity
//   * and a size
//   * */
//  {
//    regulus::vector_list<int> vl;
//    const int val = 1337;
//    auto it = vl.emplace(val);
//    assert(*it == val);
//    
//    assert(vl.capacity() == 16);
//    assert(vl.size() == 1);    
//  }
//  
//  /*
//   * We now wish to test the block appending mechanism.
//   * What makes the container so attractive is the way it
//   * handles its paging system.
//   * 
//   * It should also be bi-directionally iterable as well
//   * */
//  {
//    regulus::vector_list<int> vl;
//    
//    for (int i = 0; i < 64; ++i) {
//      vl.emplace(i);
//    }
//    
//    assert(vl.capacity() == 96);
//    assert(vl.size() == 64);
//    
//    int i = 0;
//    for (auto it = vl.begin(); it != vl.end(); ++it, ++i) {
//      assert(*it == i);
//    }
//    
//    assert((typename regulus::vector_list<int>::size_type ) i == vl.size());
//    
//    for (auto it = vl.rbegin(); it != vl.rend(); --it, --i) {
//      assert(*it == (i - 1));
//    }
//  }
  
  /*
   * Finally, we start some thread-based testing because the
   * container is supposed to be thread-safe while being completely
   * transparent to the user.
   * */
  {
    const int size = 1000000;
    regulus::vector_list<int> vl;
    std::list<int> l;
    std::vector<int> v;
    v.reserve(4 * size);

    for (int i = 0; i < 4; ++i)
      for (int j = 0; j < size; ++j)
        l.push_back(j);
        //vl.emplace(j);
        //v.emplace_back(j);
    
    long int cnt = 0;
//    for (auto it = vl.begin(); it != vl.end(); ++it) {
//      ++cnt;
//    }
    
    for (auto&& it : l) {
      ++cnt;
    }
    
    assert(cnt == 4 * size);
//    const int num_threads = 4;
//    std::vector<std::thread> tasks;
//    tasks.reserve(num_threads);
//    
//    for (int i = 0; i < num_threads; ++i) {
//      tasks.emplace_back([&vl](void) -> void {
//        for (int j = 0; j < size; ++j) {
//          vl.emplace(j);
//        }
//      });
//    }
//    
//    for (auto &t : tasks) {
//      t.join();
//    }

//    assert(vl.size() == num_threads * size);
//    
//    int vals[size] = { 0 };
//    
//    int num_steps = 0;
//    for (auto it = vl.begin(); it != vl.end(); ++it) {
//      ++num_steps;
//      ++vals[*it];
//    }
//    
//    assert(num_steps = vl.size());
//    
//    for (int i = 0; i < size; ++i) {
//      assert(vals[i] == num_threads);
//    }
  }
}
