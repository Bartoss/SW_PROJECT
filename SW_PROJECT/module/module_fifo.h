#ifndef MODULE_MEMORY_H
#define MODULE_MEMORY_H

#define BUFFER_SIZE 8

#include "systemc.h"
#include "../interface/read_interface.h"
#include "../interface/write_interface.h"




class ModuleFifo : 
    public sc_channel,
    public ReadInterface,
    public WriteInterface
{
private:
    char     data[BUFFER_SIZE];
    int      elementsNum,
             pointer;
    sc_event writeEvent,
             readEvent;    

public:
    ModuleFifo()
        : elementsNum(0)
        , pointer(0){};
    bool isEmpty();
    bool isFull();
    void write(char c);
    void read(char &c);
    void reset();
    int count();
};

#endif