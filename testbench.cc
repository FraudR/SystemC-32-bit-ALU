#include "testbench.h"
#include <time.h>

//change this value to play around with the size of random operands
#define NUM_RAND_BITS 32 

void testbench::feed(){
  sc_bv <3> rand_operation_maker;
  sc_bv <32> rand_operand_maker;
  int rst_feed;
  rand_operation_maker[0]=rand()%2;
  rand_operation_maker[1]=rand()%2;
  rand_operation_maker[2]=rand()%2;
  op_sel.write(rand_operation_maker);

  for (int i=0; i<=NUM_RAND_BITS;i++){
    rand_operand_maker[i]=rand()%2;
  }

  register_one_in.write(rand_operand_maker);

  for (int i=0; i<=NUM_RAND_BITS;i++){
    rand_operand_maker[i]=rand()%2;
  }

  register_two_in.write(rand_operand_maker);

  rst_feed = rand()%10;
  if (rst_feed<1){
    reset.write(true);
  }
}

