
#include <systemc.h>

SC_MODULE(stim) {
	sc_out<sc_uint<32>> a_tb, b_tb;
	sc_in<bool> clk_tb;
	sc_in<sc_uint<32>> out_tb;


	SC_CTOR(stim) {
		SC_THREAD(stim_func);
		sensitive << clk_tb.pos();

	}


	void stim_func()
	{
		wait();
		a_tb.write(5);
		b_tb.write(5);
		wait();
		a_tb.write(10);
		b_tb.write(10);
		wait();
		a_tb.write(15);
		b_tb.write(15);
	
		for (int i = 0; i < 5; i++) {
			wait();
		}




		sc_stop();

	}




};

