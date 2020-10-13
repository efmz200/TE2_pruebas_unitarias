//
// Created by drump1 on 19/9/20.
//

#ifndef EXTRACLASE_1_VERTICE_H
#define EXTRACLASE_1_VERTICE_H
#include "Arista.h"
#include <iostream>
using namespace std;
class Vertice {

    string nom;
    Vertice *sig;
    Arista *arist;
    friend class Arista;
    friend class Grafo;
    /**
     * @brief constructor del vertice
     * @param nomb del vertice
     */
    Vertice(string nomb) {
        nom = nomb;
        sig = NULL;
        arist = NULL;
    }
    /**
     * @brief Metodo que agrega una aritas a un vertice
     * @param arista objeto tipo arista que que se va agregar al vertice
     */
    void agregarArist(Arista *arista){
        if (arist==NULL){
            arist=arista;
        }
        else{
            Arista *aux=arist;
            while (aux->sig!=NULL){
                aux=aux->sig;
            }
            aux->sig=arista;
        }
    }
    /**
     * @brief metodo para encontrar una arista entre la lista de aristas de un vertide
     * @param nomOut nombre del vertice al que apunta el vertice
     * @return returna la arista que se estaba buscando
     */
    Arista  *getArt(string nomOut){
        if (arist==NULL){
            return 0;
        }
        Arista *aux=arist;
        while (aux->sig!=NULL){
            Vertice *aux2=aux->referencia;
            if(aux2->nom==nomOut){
                return aux;
            }
            aux=aux->sig;
        }

    }
};


#endif //EXTRACLASE_1_VERTICE_H
