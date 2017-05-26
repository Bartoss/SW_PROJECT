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
 
 sub_processor.cpp :
 
 Original Author: 
 
 *****************************************************************************/

/*****************************************************************************
 
 MODIFICATION LOG - modifiers, enter your name, affiliation, date and
 changes you are making here.
 
 Name, Affiliation, Date: Bartek
 Description of Modification:
 
 *****************************************************************************/

#include "systemc.h"
#include "processorTwo.h"

void processorTwo::main()
{
	const int length = 7;
	simple_bus_status status;

	int data[7];
	while(true) 
	{
		wait();
		status = bus_port->burst_read(bus_unique_priority, data, bus_address, length, bus_lock);
		if(data[0]==0) {
			data[1] =0;
			data[2] = 0;
			data[3] = 0;
			data[4] = 0;
            data[5] = 0;
            data[6] = 0;
		}
		wait();wait();wait();wait();wait();wait();wait();wait();wait();
		cout << data[0] << "-" << data[1] << "-" << data[2] << "-" << data[3] << "-" << data[4] << "-" << data[5] << "-" << data[6]  << endl;
	}
}
