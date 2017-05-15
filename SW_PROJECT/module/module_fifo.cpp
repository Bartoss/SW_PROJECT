#include "systemc.h"
#include "module_fifo.h"

void ModuleFifo::write(char c) 
{
	if (isFull()) {
		wait(readEvent);
	} 

	data[elementsNum] = c;
	elementsNum++;

	writeEvent.notify();
}

void ModuleFifo::read(char &c) 
{
	if (isEmpty()) {
		wait(writeEvent);
	}

	c = data[pointer];
	elementsNum--;
	pointer++;

	readEvent.notify();
}

void ModuleFifo::reset() 
{
	elementsNum = pointer = 0;
}

int ModuleFifo::count() 
{
	return elementsNum;
}

bool ModuleFifo::isFull() 
{
	return (elementsNum >= (BUFFER_SIZE - 1));
}

bool ModuleFifo::isEmpty() 
{
	return elementsNum < 1;
}