// simple_adder.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "simple_adder.h"
#include "stimulus.h"
#include "monitor.h"

int sc_main(int argc, char *argv[])
{
	//signals
	sc_signal<sc_uint<32>> a_top, b_top;
	sc_clock TestClk("TestClock", 1, SC_NS, 0.5);
	sc_signal<sc_uint<32>> out_top;

	add a1("add");
	a1.a(a_top);
	a1.b(b_top);
	a1.clk(TestClk);
	a1.out(out_top);

	// stimulus block
	stim S1("Stim");
	S1.a_tb(a_top);
	S1.b_tb(b_top);
	S1.clk_tb(TestClk);
	S1.out_tb(out_top);

	// monitor block
	mon m("monitor");
	m.A(a_top);
	m.B(b_top);
	m.OUT(out_top);
	m.clk(TestClk);


	//tracing 
	sc_trace_file* file = sc_create_vcd_trace_file("trace");
	sc_trace(file, out_top, "output_signal");
	sc_trace(file, a_top, "inputA");
	sc_trace(file, b_top, "inputB");
	sc_trace(file, TestClk, "clock");

	sc_start();
	
	
	//closing 
	sc_close_vcd_trace_file(file);

	return 0;

}