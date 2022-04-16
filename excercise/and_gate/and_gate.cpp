// and_gate.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// test bench implementation in SystemC 

#include "and_gate.h"


int sc_main(int, char* []) {
	//signals
	sc_signal<sc_uint<1>> a_tb, b_tb;
	sc_signal<sc_uint<1>> out_tb;

	AND A1("a1");
	//port binding
	A1.a(a_tb);
	A1.b(b_tb);
	A1.o(out_tb);

	//tracing 
	sc_trace_file* file = sc_create_vcd_trace_file("trace");
	sc_trace(file, out_tb, "output_signal");


	sc_start(0, SC_NS); // start sims


	 // stimulus definition
	for (int i = 0; i < 50; i++) {
		a_tb.write(1);
		b_tb.write(0);
		sc_start(10, SC_NS);
		a_tb.write(1);
		b_tb.write(1);
		sc_start(10, SC_NS);
	}


	sc_close_vcd_trace_file(file);
	return 0;


}
