
//include systemc 

#include <systemc.h>

SC_MODULE(add)
{
	sc_in<sc_uint<32>> a, b;
	sc_in<bool> clk;
	sc_out<sc_uint<32>> out;

	SC_CTOR(add)
	{
		SC_THREAD(func);
		sensitive << clk.pos();

	}

	void func() {

		int i, j, k;
		while (true) {
			i = a.read();
			j = b.read();
			out.write(i + j);
			wait();
		}
		

		

		
	}

};