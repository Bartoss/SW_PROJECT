//  SW_PROJECT
//
//  Created by Sarata Bartlomiej on 18.04.2017.
//  Copyright © 2017 Sarata Bartlomiej. All rights reserved.
//
/*****************************************************************************
 
 Licensed to Accellera Systems Initiative Inc. (Accellera) under one or
 more contributor license agreements.  See the NOTICE file distributed
 with this work for additional information regarding copyright ownership.
 Accellera licenses this file to you under the Apache License, Version 2.0
 (the "License"); you may not use this file except in compliance with the
 License.  You may obtain a copy of the License at
 
 http://www.apache.org/licenses/LICENSE-2.0
 
 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
 implied.  See the License for the specific language governing
 permissions and limitations under the License.
 
 *****************************************************************************/

/*****************************************************************************
 
 display.cpp :
 
 Original Author:
 
 *****************************************************************************/

/*****************************************************************************
 
 MODIFICATION LOG - modifiers, enter your name, affiliation, date and
 changes you are making here.
 
 Name, Affiliation, Date: Bartek
 Description of Modification:
 
 *****************************************************************************/
#include "display.h"
#include "ncurses.h"

Display::Display() {
	initscr();
	set_functions_names();
	init_colors();
}

bool Display::check(Function function)
{
	int value = static_cast<int>(function);
	return (state&value)>0;
}

void Display::enable(Function function)
{
	state |= static_cast<int>(function);
}

void Display::disable(Function function)
{
	state &= ~static_cast<int>(function);
}

void Display::refresh()
{
	short line = 0;
	for(const auto& function : functions_names) {
		if(check(function.first)) {
			attron(COLOR_PAIR(COLOR_PAIR::ENABLED));
		} else {
			attron(COLOR_PAIR(COLOR_PAIR::DISABLED));
		}
		mvwprintw(stdscr, line++, 0, "%s", function.second.c_str());
	}
}

void Display::set_functions_names()
{
	functions_names[Function::THIRTY]  = "30 Stopni";
	functions_names[Function::FOURTY]  = "40 Stopni";
	functions_names[Function::FIFTY]   = "50 Stopni";
	functions_names[Function::SIXTY]   = "60 Stopni";
	functions_names[Function::SEVENTY] = "70 Stopni";
}

void Display::init_colors()
{
	start_color();
	init_pair(COLOR_PAIR::ENABLED, COLOR_BLACK, COLOR_GREEN);
	init_pair(COLOR_PAIR::DISABLED, COLOR_WHITE, COLOR_BLACK);
}

Display::~Display() {
	endwin();
}


