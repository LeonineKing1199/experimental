#include "test.hpp"

void element_tests(void)
{
  std::cout << "Running Element Tesets" << std::endl;
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
