#include "reseting.h"

void reseting::reset_Me(){
  if (resetRead.read()==true){
    op_sel.write("000");
    sc_bv <32> rand_vector_maker;
    for (int i=0; i<=31;i++){

      rand_vector_maker[i]="0";

    }
    //register_one_in.write(rand_vector_maker);
    register_one_in.write("00000000000000000000000000000000");
    //register_two_in.write(rand_vector_maker);
    register_two_in.write("00000000000000000000000000000000");
    register_one_out.write("00000000000000000000000000000000");
    register_two_out.write("00000000000000000000000000000000");
    accumulator.write("00000000000000000000000000000000");
    status.write("00000000");
    

    cout<<"got into Reset, values have been reset now"<<endl<<endl;
  }

  resetWrite.write(false);
}

