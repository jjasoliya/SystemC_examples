#pragma once
#include <systemc.h>
#include <iostream>
#include <iomanip>
using namespace std;

SC_MODULE(mon)
{
	sc_in<sc_uint<32>> A, B;
	sc_in<sc_uint<32>> OUT;
	sc_in<bool> clk;


	SC_CTOR(mon)
	{
		SC_THREAD(monitor);
		sensitive << clk.pos();

	}


	void monitor() {
		cout << setw(10) << "Time";
		cout << setw(4) << "A";
		cout << setw(4) << "B";
		cout << setw(4) << "OUT" << endl;
		while (true)
		{
			cout << setw(10) << sc_time_stamp();
			cout << setw(4) << A.read();
			cout << setw(4) << B.read();
			cout << setw(4) << OUT.read() << endl;
			wait();    // wait for 1 clock cycle
		}
	}
};