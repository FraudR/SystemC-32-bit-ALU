HEADERS = initializer.h  reseting.h  alu.h  testbench.h
SOURCES = initializer.cc reseting.cc alu.cc testbench.cc main.cc
OBJECTS = initializer.o  reseting.o  alu.o  testbench.o  main.o
LIBS = -lsystemc -lstdc++ -lm

%.o: %.c $(HEADERS)
	$(CC) -c -o $@ %<
	
alu: $(OBJECTS)
	$(CC) -o $@ $^ $(LIBS)
	
run:
	./alu
	
wave:
	gtkwave ALU.vcd
clean:
	rm -f alu *.o *.vcd

