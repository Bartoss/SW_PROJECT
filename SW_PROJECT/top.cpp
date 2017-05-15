#include "top.h"

top::top(sc_module_name name) : sc_module(name), clock("clock")
{
	memory = new simple_bus_fast_mem("memory", 0x00, 0xff);
	arbiter = new simple_bus_arbiter("arbiter");
	bus = new simple_bus("bus");
	m_main_processor = new main_processor("main_processor", 2, 0x00, true, 60);
	m_sub_processor = new sub_processor("sub_processor", 1, 0x00, true, 60);

	m_main_processor->clock(clock);
	m_main_processor->bus_port(*bus);

	m_sub_processor->clock(clock);
	m_sub_processor->bus_port(*bus);

	bus->clock(clock);
	bus->arbiter_port(*arbiter);
    bus->slave_port(*memory);
}
