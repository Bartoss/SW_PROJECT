#include <iostream>
#include <systemc>
#include "topModule.h"
#include "ncurses.h"

int sc_main (int argc, char* argv[]) {
	initscr();
	topModule topModule("topModule");

	sc_start();
	endwin();

	return 0;
}
