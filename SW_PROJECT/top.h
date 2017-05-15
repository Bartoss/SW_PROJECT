#ifndef TOP_H_
#define TOP_H_
#include "systemc.h"
#include "simple_bus.h"
#include "simple_bus_fast_mem.h"
#include "simple_bus_arbiter.h"
#include "memory.h"
#include "main_processor.h"
#include "sub_processor.h"

class top : public sc_module
{
private:
	sc_clock clock;
	simple_bus *bus;
	simple_bus_arbiter *arbiter;
  	simple_bus_fast_mem *memory;
  	main_processor *m_main_processor;
  	sub_processor *m_sub_processor;

public:
	top(sc_module_name name);
};

#endif
