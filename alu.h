#include <systemc.h>

SC_MODULE(alu)
{
  sc_in < sc_bv<3> > op_sel;
  sc_in <bool> reset;
  sc_clock clk;
  sc_in < sc_bv<32> > register_one_in;
  sc_out < sc_bv<32> > register_one_out;
  sc_in < sc_bv<32> > register_two_in;
  sc_out < sc_bv<32> > register_two_out;
  sc_out < sc_bv<32> > accumulator;
  sc_out < sc_bv<8> > status;

  void operations();
  SC_CTOR(alu){
    SC_METHOD(operations);
    sensitive<<op_sel<<status<<accumulator;
    dont_initialize();
  }
};

