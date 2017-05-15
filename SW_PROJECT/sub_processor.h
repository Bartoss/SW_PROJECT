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
 
 sub_processor.h :
 
 Original Author: 
 
 *****************************************************************************/

/*****************************************************************************
 
 MODIFICATION LOG - modifiers, enter your name, affiliation, date and
 changes you are making here.
 
 Name, Affiliation, Date: Bartek
 Description of Modification:
 
 *****************************************************************************/

#ifndef SUB_PROCESSOR_H_
#define SUB_PROCESSOR_H_
#include "systemc.h"
#include "processor.h"

class sub_processor : public processor
{
public:

	SC_HAS_PROCESS(sub_processor);

	sub_processor(sc_module_name name, unsigned int bus_unique_priority, unsigned int bus_address, bool bus_lock, int bus_timeout)
		: processor(name, bus_unique_priority, bus_address, bus_lock, bus_timeout) 
	{

	}

	void main();
};

#endif
