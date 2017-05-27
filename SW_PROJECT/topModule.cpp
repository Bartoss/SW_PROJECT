#include "topModule.h"

topModule::topModule(sc_module_name name) : sc_module(name), clock("clock")
{
	memory = new simple_bus_fast_mem("memory", 0x00, 0xff);
	arbiter = new simple_bus_arbiter("arbiter");
	bus = new simple_bus("bus");
	vProcessorOne = new processorOne("processorOne", 2, 0x00, true, 60);
	vProcessorTwo = new processorTwo("processorTwo", 1, 0x00, true, 60);

	vProcessorOne->clock(clock);
	vProcessorOne->bus_port(*bus);

	vProcessorTwo->clock(clock);
	vProcessorTwo->bus_port(*bus);

	bus->clock(clock);
	bus->arbiter_port(*arbiter);
    bus->slave_port(*memory);
}
