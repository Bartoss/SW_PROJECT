#ifndef TOP_H_
#define TOP_H_
#include "systemc.h"
#include "simple_bus.h"
#include "simple_bus_fast_mem.h"
#include "simple_bus_arbiter.h"
#include "memory.h"
#include "processorOne.h"
#include "processorTwo.h"

class top : public sc_module
{
private:
	sc_clock clock;
	simple_bus *bus;
	simple_bus_arbiter *arbiter;
  	simple_bus_fast_mem *memory;
  	processorOne *vProcessorOne;
  	processorTwo *vProcessorTwo;

public:
	top(sc_module_name name);
};

#endif
