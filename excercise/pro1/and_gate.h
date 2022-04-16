// AND gate implementation in SystemC
#include <systemc.h>

SC_MODULE(AND) {
	sc_in<sc_uint<1>> a, b;
	sc_out<sc_uint<1>> o;


	SC_CTOR(AND){
		SC_METHOD(func);
		sensitive << a << b;  // runs the function whenever a or b changes... a.pos() or b.neg() also allowed.
	}

	void func() {
		o.write( a.read() & b.read() );
		cout  <<  "  a = " << a.read() <<  " b = " << b.read() << "  output =  " << o.read() << endl;

	}

};


