#include <systemc.h>

SC_MODULE(initializer)
{
  sc_out < sc_bv<3> > op_sel;
  sc_out <bool> reset;
  sc_clock clk;
  sc_out < sc_bv<32> > register_one_in;
  sc_out < sc_bv<32> > register_one_out;
  sc_out < sc_bv<32> > register_two_in;
  sc_out < sc_bv<32> > register_two_out;
  sc_out < sc_bv<32> > accumulator;
  sc_out < sc_bv<8> > status;

  void initialize_Me();

  SC_CTOR(initializer){
    SC_THREAD(initialize_Me);
  }
};

