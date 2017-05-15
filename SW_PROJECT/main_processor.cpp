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
 
 main_processor.cpp :
 
 Original Author: 
 
 *****************************************************************************/

/*****************************************************************************
 
 MODIFICATION LOG - modifiers, enter your name, affiliation, date and
 changes you are making here.
 
 Name, Affiliation, Date: Bartek
 Description of Modification:
 
 *****************************************************************************/
#include "systemc.h"
#include "main_processor.h"
#include "ncurses.h"
#include "function.h"
#define KEY_ESC 27

void main_processor::main()
{
	char key;
	int function_id, address, value;
	simple_bus_status status;
    

	while(true) 
	{
		key = getch();
		if(key == KEY_ESC)
		{
			sc_stop();
			return;
		}

        /** Ustalenie funkcji na podstawie klawisza */
		switch(key) {
			case 'q':
			case 'a':
				function_id = FUNCTION_THIRTY_ID;
				break;

			case 'w':
			case 's':
				function_id = FUNCTION_FOURTY_ID;
				break;

			case 'e':
			case 'd':
				function_id = FUNCTION_FIFTY_ID;
				break;

			case 'r':
			case 'f':
				function_id = FUNCTION_SIXTY_ID;
				break;

			case 't':
			case 'g':
				function_id = FUNCTION_SEVENTY_ID;
				break;

			default:
				continue;
		}

		/** Ustalenie akcji (wł/wył) na podstawie klawisza */
		switch(key) {
            case 'q': value = 30; break;
            case 'w': value = 40; break;
            case 'e': value = 50; break;
            case 'r': value = 60; break;
            case 't': value = 70; break;
				
        

			case 'a':
			case 's':
			case 'd':
			case 'f':
			case 'g':
				value = 0;
				break;

			default:
				continue;
		}
        if(key == 'q'){
            
        }

		/** Zapisanie nowej wartości w pamięci */
		address = bus_address + (function_id-1) * 4;

		wait();
		status = bus_port->burst_write(bus_unique_priority, &value, address, 1, bus_lock);
	}
}
