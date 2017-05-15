#include "systemc.h"
#include "../interface/read_interface.h"


SC_MODULE(SubProcessor) {
	public:
		sc_port<ReadInterface> in;

	SC_CTOR(SubProcessor) {
		SC_THREAD(main);
	}
	

	void main() {
		char c = 0;
		while (true) {
			in->read(c);
			cout <<c<<endl;
		}
	}

};