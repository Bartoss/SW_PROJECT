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
#include "display.h"
#define KEY_ESC 27

void main_processor::main()
{
	char key;
	int function_id, address, value;
    char str1[10] = "30 stopni";
    char str2[10] = "35 stopni";
    char str3[10] = "40 stopni";
    char str4[10] = "45 stopni";
    char str5[10] = "50 stopni";
    char str6[10] = "55 stopni";
    char str7[10] = "60 stopni";
    char str8[10] = "Wylaczono";
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
				function_id = FUNCTION_THIRTYFIVE_ID;
				break;

			case 'e':
			case 'd':
				function_id = FUNCTION_FOURTY_ID;
				break;

			case 'r':
			case 'f':
				function_id = FUNCTION_FOURTYFIVE_ID;
				break;

			case 't':
			case 'g':
				function_id = FUNCTION_FIFTY_ID;
				break;
            case 'y':
            case 'h':
                function_id = FUNCTION_FIFTYFIVE_ID;
                break;
            case 'u':
            case 'j':
                function_id = FUNCTION_SIXTY_ID;
                break;

		}

		/** Ustalenie akcji (wł/wył) na podstawie klawisza */
		switch(key) {
            case 'q': printf("\n%s\n", str1 ); break;
            case 'w': printf("\n%s\n", str2 ); break;
            case 'e': printf("\n%s\n", str3 ); break;
            case 'r': printf("\n%s\n", str4 ); break;
            case 't': printf("\n%s\n", str5 ); break;
            case 'y': printf("\n%s\n", str6 ); break;
            case 'u': printf("\n%s\n", str7 ); break;
        

			case 'a': printf("\n%s\n", str8 ); break;
			case 's': printf("\n%s\n", str8 ); break;
			case 'd': printf("\n%s\n", str8 ); break;
			case 'f': printf("\n%s\n", str8 ); break;
			case 'g': printf("\n%s\n", str8 ); break;
            case 'h': printf("\n%s\n", str8 ); break;
            case 'j': printf("\n%s\n", str8 ); break;

		}


		/** Zapisanie nowej wartości w pamięci */
		address = bus_address + (function_id-1) * 4;

		wait();
		status = bus_port->burst_write(bus_unique_priority, &value, address, 1, bus_lock);
	}
}
