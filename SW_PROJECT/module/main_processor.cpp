#include "systemc.h"
#include "../interface/write_interface.h"


SC_MODULE(MainProcessor) {
	public:
		sc_port<WriteInterface> out;

	SC_CTOR(MainProcessor) {
		SC_THREAD(main);
	}
	

	void main() {
		char c = 0;
		while (true) {
			out->write(123);

			if (out->isFull()) {
			 	return;
			}
		}
	}

};
