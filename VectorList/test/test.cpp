#include "test.hpp"

void test_suite(void)
{
    element_tests();
}

void element_tests(void)
{
  {
    /*
     * It should be default constructible
     * */
    regulus::element<int> el;
    
    assert(el.get_state() == regulus::element_state::undefined);
    
    /*
     * We should be able to link two disparate elements
     * */
     decltype(el) el2;
     
     auto el_addr = std::addressof(el);
     auto el2_addr = std::addressof(el2);
     
     el.set_next(el2_addr, nullptr);
     el2.set_next(el_addr, nullptr);
     
     // basic sanity checks
     assert(
      (el.get_next() == 
        typename regulus::element<int>::next_type{el2_addr, nullptr}));
        
     assert(
      (el2.get_next() == 
        typename regulus::element<int>::next_type{el_addr, nullptr}));
  }
}
