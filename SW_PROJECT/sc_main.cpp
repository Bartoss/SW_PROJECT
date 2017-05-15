#include <iostream>
#include <systemc>
#include "top.h"
#include "ncurses.h"

int sc_main (int argc, char* argv[]) {
	initscr();
	top top("top");

	sc_start();
	endwin();

	return 0;
}
