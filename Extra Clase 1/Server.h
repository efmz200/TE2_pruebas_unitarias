//
// Created by drump1 on 22/9/20.
//

#ifndef EXTRACLASE_1_SERVER_H
#define EXTRACLASE_1_SERVER_H
#include "Grafo.h"
#include <string>
class Server {


public:
    Grafo *graf=new Grafo();
    /**
     * @brief metodo que crea un grafo para poder hacer el floyd warshall
     * @return string para representar la matriz
     */
    string prueba(){
        graf->agregaVert("a");
        graf->agregaVert("b");
        graf->agregaVert("c");
        graf->agregaVert("d");
        graf->agregarArista(5,"a","b");
        graf->agregarArista(3,"a","c");
        graf->agregarArista(3,"b","c");
        graf->agregarArista(1,"c","d");
        string msg=graf->genmatriz();
        return msg;
    }

};


#endif //EXTRACLASE_1_SERVER_H
