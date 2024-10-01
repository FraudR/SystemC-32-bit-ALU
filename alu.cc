#include "alu.h"
#include <systemc.h>
void alu::operations(){


// ADD YOUR CODE HERE
	sc_bv<32> Myaccumulator;
	sc_bv<8> statusFlags;
   	statusFlags = "00000001";
	
	if (reset.read()!=true){
		/// AND(bitwise and) ACC <-- R1 AND R2
		if (op_sel.read() == "000"){
			Myaccumulator = register_one_in.read() & register_two_in.read();
			
		}
		
		// OR ACC <-- R1 OR R2
		else if (op_sel.read() == "001"){
			Myaccumulator = register_one_in.read() | register_two_in.read();
		}

		// XOR ACC <-- R1 XOR R2
		else if (op_sel.read() == "010"){
			Myaccumulator = register_one_in.read() ^ register_two_in.read();
		}

		// SHR (logicl shift right 1 bit) ACC <-- shiftright R1
		else if (op_sel.read() == "011"){
			Myaccumulator = register_one_in.read() >> 1;
		}

		// SHL (logical shift left 1 bit) ACC <-- shiftleft R1
		else if (op_sel.read() == "100"){
			Myaccumulator = register_one_in.read() << 1;
		}

		// sv_bv doesnt support additon, so must change to sc_bigint
		// ADD (signed addition) ACC <-- R1+R2
		else if (op_sel.read() == "101"){
			Myaccumulator=(register_one_in.read().to_int() + register_two_in.read().to_int());
			sc_int<32> r1_bigint = register_one_in.read().to_int();
			sc_int<32> r2_bigint = register_two_in.read().to_int();	
			
			if (Myaccumulator.to_int() < r1_bigint.to_int() || Myaccumulator.to_int() < r2_bigint.to_int()){
				statusFlags[1]= '1'; //overflow
				
			}

		}

		// MUL (signed multiplication) ACC <-- R1 * R2
		else if (op_sel.read() == "110"){
			sc_int<32> r1_bigint = register_one_in.read().to_int();
			sc_int<32> r2_bigint = register_two_in.read().to_int();	
			
			Myaccumulator = r1_bigint * r2_bigint;
			
		}

		// DIV (signed division) ACC <-- R1/R2
		else if (op_sel.read() == "111"){
			sc_int<32> r1_bigint = register_one_in.read().to_int();
			sc_int<32> r2_bigint = register_two_in.read().to_int();	
			
			Myaccumulator = r1_bigint / r2_bigint;
			
		}
		
		accumulator.write(Myaccumulator);
		
		//checking for negative
		for (int i=0;i<32;i++){ //check for zero
			if (Myaccumulator[i]=='1'){
				statusFlags[0] = '0';
			}
		}
		
		if (Myaccumulator[31]=='1'){ //check for negative
		    statusFlags[2]='1'; 
		}
		

		status.write(statusFlags);

		// We use this to display the details inputs & outputs of each operation
		// For all operators, display two register operands, EXCEPT
		if (op_sel.read()!= "100" && op_sel.read()!= "011"){
		  cout << "Operator is:         "<<op_sel.read()<<endl;
		  cout << "register_one is      "<<register_one_in.read()<<endl;
		  cout << "register_two is      "<<register_two_in.read()<<endl;
		  cout << "Accumulator Value is "<<Myaccumulator<<endl;  //accumalator = 
		  cout << "Status flag is       "<<statusFlags<<endl;
		}

		// ...for shift operators, only show one operand
		if (op_sel.read()== "100" || op_sel.read()== "011"){
		  cout << "Operator is:         "<<op_sel.read()<<endl;
		  cout << "register_one is      "<<register_one_in.read()<<endl;
		  cout << "Accumulator value is "<<Myaccumulator<<endl;
		  cout << "Status flag is       "<<statusFlags<<endl;
		}

		// Print a double line to separate different operator outputs
		for (int i=0;i<=70;i++)
		{
		  cout << "=";
		}
		cout << endl;
	}
};




