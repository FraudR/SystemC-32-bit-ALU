#include <systemc.h>
#include <cstdlib>
#include "alu.h"
#include "initializer.h"
#include "reseting.h"
#include "testbench.h"

int sc_main(int argc, char * argv[]) {

    sc_signal<sc_bv<3>, SC_MANY_WRITERS> op_sel_sig;
    sc_signal<bool, SC_MANY_WRITERS> reset_sig, resetRead_sig;
    sc_signal<sc_bv<8>, SC_MANY_WRITERS> status_sig;
    sc_signal<sc_bv<32>, SC_MANY_WRITERS> r1_in_sig, r1_out_sig, r2_in_sig, r2_out_sig, accumulator_sig;

	
    initializer initializer1("initializer1");
    initializer1.op_sel(op_sel_sig);
    initializer1.reset(reset_sig);
    initializer1.register_one_in(r1_in_sig);
    initializer1.register_one_out(r1_out_sig);
    initializer1.register_two_in(r2_in_sig);
    initializer1.register_two_out(r2_out_sig);
    initializer1.accumulator(accumulator_sig);
    initializer1.status(status_sig);


    reseting reset1("reset1");
    reset1.op_sel(op_sel_sig);
    reset1.resetRead(reset_sig);
    reset1.resetWrite(reset_sig); // Separate signal for resetWrite
    reset1.register_one_in(r1_in_sig);
    reset1.register_one_out(r1_out_sig); // Changed to input
    reset1.register_two_in(r2_in_sig);
    reset1.register_two_out(r2_out_sig); // Changed to input
    reset1.accumulator(accumulator_sig);
    reset1.status(status_sig);


    alu alu1("alu1");
    alu1.op_sel(op_sel_sig);
    alu1.reset(reset_sig);
    alu1.register_one_in(r1_in_sig);
    alu1.register_one_out(r1_out_sig);
    alu1.register_two_in(r2_in_sig);
    alu1.register_two_out(r2_out_sig);
    alu1.accumulator(accumulator_sig);
    alu1.status(status_sig);
    
    testbench test1("testbench1");
    test1.op_sel(op_sel_sig);
    test1.reset(reset_sig);
    test1.register_one_in(r1_in_sig);
    test1.register_one_out(r1_out_sig);
    test1.register_two_in(r2_in_sig);
    test1.register_two_out(r2_out_sig);
    test1.accumulator(accumulator_sig);
    test1.status(status_sig);

	sc_trace_file *tf = sc_create_vcd_trace_file("ALU");

	sc_trace(tf,op_sel_sig,"op_sel_sig");
	sc_trace(tf,reset_sig,"reset_sig");
	sc_trace(tf,r1_in_sig,"register_one_in_sig");
	sc_trace(tf,r1_out_sig,"register_one_out_sig");
	sc_trace(tf,r2_in_sig,"register_two_in_sig");
	sc_trace(tf,r2_out_sig,"register_two_out_sig");
	sc_trace(tf,accumulator_sig,"accumulator_sig");
	sc_trace(tf,status_sig,"status_sig");
    sc_start(10, SC_NS);
  //sc_start();

  return 0;
}
