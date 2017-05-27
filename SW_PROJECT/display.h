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
 
 display.h :
 
 Original Author: 
 
 *****************************************************************************/

/*****************************************************************************
 
 MODIFICATION LOG - modifiers, enter your name, affiliation, date and
 changes you are making here.
 
 Name, Affiliation, Date: Bartek
 Description of Modification:
 
 *****************************************************************************/
#ifndef DISPLAY_H_
#define DISPLAY_H_
#include <map>
#include <string>
#include <sstream>
#include <iostream>
#include <stdint.h>
#include "function.h"

/**
 * Wyświetlacz
 */
class Display {
public:
	Display();
	virtual ~Display();

	/**
	 * Wyświetla aktualny stan funkcji
	 */
	void refresh();

	/**
	 * Sprawdza, czy funkcja jest włączona
	 */
	bool check(Function);

	/**
	 * Włącza funkcję
	 */
	void enable(Function);

	/**
	 * Wyłącza funkcję
	 */
	void disable(Function);

private:
	enum COLOR_PAIR { ENABLED = 1, DISABLED = 2 };

	/**
	 * Aktualny stan funkcji
	 * Suma bitowa wartości Function
	 */
	uint8_t state = 0;

	/**
	 * Nazwy funkcji
	 */
	std::map<Function, std::string> functions_names;

	/**
	 * Inicjalizuje listę nazw funkcji
	 */
	void set_functions_names();

	/**
	 * Inicjalizuje ustawienia kolorów
	 */
	void init_colors();
};

#endif /* DISPLAY_H_ */
