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
 
functions.h :
 
 Original Author:
 
 *****************************************************************************/

/*****************************************************************************
 
 MODIFICATION LOG - modifiers, enter your name, affiliation, date and
 changes you are making here.
 
 Name, Affiliation, Date: Bartek
 Description of Modification:
 
 *****************************************************************************/
#ifndef FUNCTION_H_
#define FUNCTION_H_
#include <stdint.h>
#define FUNCTION_THIRTY_ID 1
#define FUNCTION_FOURTY_ID 2
#define FUNCTION_FIFTY_ID 3
#define FUNCTION_SIXTY_ID 4
#define FUNCTION_SEVENTY_ID 5

/**
 * Dostępne funkcje
 */
enum class Function : uint8_t {
	THIRTY = 1, //
	FOURTY = 2, //
	FIFTY = 4, //
	SIXTY= 8, //
	SEVENTY = 16 // 
};

#endif /* FUNCTION_H_ */
