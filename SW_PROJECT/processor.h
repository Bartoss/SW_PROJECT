#ifndef PROCESSOR_H_
#define PROCESSOR_H_
#include "systemc.h"
#include "simple_bus_blocking_if.h"

/*
 * Klasa bazowa dla procesorów
 */
class processor : public sc_module
{
public:
	sc_in_clk clock;
 	sc_port<simple_bus_blocking_if> bus_port;

	SC_HAS_PROCESS(processor);

	processor(sc_module_name name, unsigned int bus_unique_priority, unsigned int bus_address, bool bus_lock, int bus_timeout);

	virtual void main() = 0;

protected:
	unsigned int bus_unique_priority;
	unsigned int bus_address;
	bool bus_lock;
	int bus_timeout;
};

#endif