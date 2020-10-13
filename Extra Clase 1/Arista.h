//
// Created by drump1 on 19/9/20.
//

#ifndef EXTRACLASE_1_ARISTA_H
#define EXTRACLASE_1_ARISTA_H
#include "Vertice.h"
#include <iostream>
using namespace std;

class Vertice;

class Arista {

    friend class Grafo;
    friend class Vertice;

    int peso;
    Arista *sig;
    Vertice *referencia;




    void setNext(Arista *next) {
        sig=next;
    }
};


#endif //EXTRACLASE_1_ARISTA_H
