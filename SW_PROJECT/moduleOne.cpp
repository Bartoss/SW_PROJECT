//
//  moduleOne.cpp
//  SW_PROJECT
//
//  Created by Sarata Bartlomiej on 19.04.2017.
//  Copyright © 2017 Sarata Bartlomiej. All rights reserved.
//

#include "moduleOne.hpp"
#include <systemc>
using namespace sc_core;
using namespace std;

struct synchro{
    sc_signal<float> wartosc;
    sc_event zdarzenie;
};

SC_MODULE(wartosc){
    sc_in<float> wejscie_a;
    sc_out<float> Wyjscie;
    synchro pobranoJeden;
    synchro koniec1;
    
//    void pierwszy_prog(){
//        cout << "30 stopni" << endl;
//        pobranoJeden.wartosc.write(wejscie_a.read());
//        pobranoJeden.zdarzenie.notify(0,SC_NS);
//        cout << "Minuty = " << wejscie_a.read() << endl;
//    }
    
    void wybor_programu(){
        cout << "Projekt" << endl;
        pobranoJeden.wartosc.write(wejscie_a.read());
        pobranoJeden.zdarzenie.notify(0,SC_NS);
        cout << "Wybrano program: " << wejscie_a.read() << endl;
    }
    
//    void task_1(){
//        wait(pobranoJeden.zdarzenie);
//        float temp = pobranoJeden.wartosc.read();
//        koniec1.wartosc.write(temp);
//        koniec1.zdarzenie.notify(0,SC_NS);
//        cout << "TASK 1: Program 30 stopni " <<  temp << " minuty" << endl;
//    }
    
    void prog1(){
        wait(pobranoJeden.zdarzenie);
        float temp = pobranoJeden.wartosc.read();
        if(temp == 1){
            koniec1.wartosc.write(temp);
            koniec1.zdarzenie.notify(0,SC_NS);
            cout << "PROGRAM 1 Wykonany! " << endl;
        }
    }
    
    void prog2(){
        wait(pobranoJeden.zdarzenie);
        float temp = pobranoJeden.wartosc.read();
        if(temp == 2){
            koniec1.wartosc.write(temp);
            koniec1.zdarzenie.notify(0,SC_NS);
            cout << "PROGRAM 2 Wykonany! " << endl;
        }
    }
    
    
    SC_CTOR(wartosc){
        SC_THREAD(wybor_programu);
        SC_THREAD(prog1);
        SC_THREAD(prog2);
    }
};
