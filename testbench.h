#include <systemc.h>

SC_MODULE(testbench)
{
  sc_out < sc_bv<3> > op_sel;
  sc_out <bool> reset;
  sc_clock clk;
  sc_in < sc_bv<32> > register_one_out;
  sc_out < sc_bv<32> > register_one_in;
  sc_out < sc_bv<32> > register_two_in;
  sc_in < sc_bv<32> > register_two_out;
  sc_in < sc_bv<32> > accumulator;
  sc_in < sc_bv<8> > status;

  void feed();
  SC_CTOR(testbench){
    SC_METHOD(feed);
    sensitive<<clk;
    dont_initialize();
  }
};
