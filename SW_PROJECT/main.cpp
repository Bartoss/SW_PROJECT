//
//  main.cpp
//  SW_PROJECT
//
//  Created by Sarata Bartlomiej on 18.04.2017.
//  Copyright © 2017 Sarata Bartlomiej. All rights reserved.
//

#include <iostream>
#include <systemc>
#include "moduleOne.cpp"

using namespace std;
using namespace sc_core;

int sc_main(int argc, char *argv[]) {
    
    sc_signal<float> we_a;
    sc_signal<float> out;
    
    //dane wejsciowe
    we_a= 32;
    
    wartosc wart("");
    
    wart.wejscie_a(we_a);
    
    wart.Wyjscie(out);
    
    sc_start();
    sc_stop();
    return 0;
}

