#include <systemc.h>

SC_MODULE(reseting)
{
  sc_out < sc_bv<3> > op_sel;
  sc_in <bool> resetRead;
  sc_out <bool> resetWrite;
  sc_clock clk;
  sc_out < sc_bv<32> > register_one_in;
  sc_out < sc_bv<32> > register_one_out;
  sc_out < sc_bv<32> > register_two_in;
  sc_out < sc_bv<32> > register_two_out;
  sc_out < sc_bv<32> > accumulator;
  sc_out < sc_bv<8> > status;

  void reset_Me();

  SC_CTOR(reseting){
    SC_METHOD(reset_Me);
    sensitive<<resetRead;
    dont_initialize();
  }
};


