#include "processor.h"

processor::processor(sc_module_name name, unsigned int bus_unique_priority, unsigned int bus_address, bool bus_lock, int bus_timeout) 
	: sc_module(name), bus_unique_priority(bus_unique_priority), bus_address(bus_address), bus_lock(bus_lock), bus_timeout(bus_timeout)
{
	SC_THREAD(main);
	sensitive << clock.pos();
}