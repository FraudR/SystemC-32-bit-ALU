#include "initializer.h"

void initializer::initialize_Me(){

  op_sel.write("000");
  reset.write(false);
  sc_bv <32> rand_vector_maker;
  register_one_in.write("00000000000000000000000000000000");
  register_two_in.write("00000000000000000000000000000000");
  register_one_out.write("00000000000000000000000000000000");
  register_two_out.write("00000000000000000000000000000000");
  accumulator.write("00000000000000000000000000000000");
  status.write("00000000");
  cout<<"got into initializer, values have been set now"<<endl;

}

