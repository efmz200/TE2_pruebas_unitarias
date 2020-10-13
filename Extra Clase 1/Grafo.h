/**
 * @file Grafo.h
 * @version 1.5
 * @author Erick Madrigal
 * @code
 * int main(){
 *  Grafo=new Grafo();
 *   graf->agregaVert("a");
 *      graf->agregaVert("b");
 *      graf->agregaVert("c");
 *      graf->agregaVert("d");
 *      graf->agregarArista(5,"a","b");
 *      graf->agregarArista(3,"a","c");
 *      graf->agregarArista(3,"b","c");
 *      graf->agregarArista(1,"c","d");
 *      string msg=graf->genmatriz();
 * }
 * @endcode
 *
 */
#include <iostream>
#ifndef EXTRACLASE_1_GRAFO_H

#define EXTRACLASE_1_GRAFO_H
#define INF 999
#include "Vertice.h"
#include "Arista.h"
using namespace std;

class Grafo {
        Vertice *inicial;

    public:
        /**
         * @brief Cuenta los vertices del grafo para saber su largo
         * @return retorna un int que es el largo del grafo
         */
        int lengrafo(){
            if (inicial== nullptr){
                return 0;
            }
            else{
                int cont=0;
                Vertice *aux= inicial;
                while(aux!= nullptr){
                    cont++;
                    aux=aux->sig;
                }
                return cont;
            }
        }
        /**
         * @brief funcion que busca entre los vertices hasta encontrar el que coincida con el nombre buscado
         * @param nomb nombre del vertice que se esta buscando
         * @return Vertice que tiene el nombre buscado
         */
        Vertice *getVertice(string nomb) {

            Vertice *aux;
            aux = inicial;
            while (aux != nullptr) {
                if (nomb == aux->nom) {
                    return aux;
                }
                aux = aux->sig;
            }

            return nullptr;
        }
        /**
         * @brief metodo para agregar un vertice al grafo
         * @param nomb nombre del nuevo vertice
         */
        void agregaVert(string nomb){
            Vertice *nuevo=new Vertice(nomb);
            if (inicial==nullptr){
                inicial=nuevo;
            }
            else {
                Vertice *aux = inicial;
                while (aux->sig != nullptr) {
                    aux=aux->sig;
                }
                aux->sig=nuevo;
            }
        }
        /**
         * @brief metodo que agrega una arista
         * @param pes entero que representa el peso de la arista
         * @param nomb1 nombre del vertice del que sale la arista
         * @param nomb2 nombre del vertice al que apunta la arista
         */
        void agregarArista(int pes,string nomb1,string nomb2){
            Vertice *aux1=getVertice(nomb1);
            Vertice *aux2=getVertice(nomb2);
            if(aux1!= nullptr && aux2!= nullptr){
                Arista *art= new Arista();
                art->referencia=aux2;
                art->sig=nullptr;
                art->peso=pes;
                aux1->agregarArist(art);
            }

        }
        /**
         * @brief metodo que recorre el grafo y lo pasa a una matriz para poder realizar el floyd warshall
         * @return string con el resultado del floyd warshall
         */
        string genmatriz(){
            int largo;//cantidad de nodos en el grafo
            largo=lengrafo();
            largo++;
            string arr[largo] [largo];
            string salida;
            Vertice *aux=inicial;
            // for para poner el nombre del nodo en la primer fila y columna
            for (int i=1;i<largo;i++){
                arr[i][0]=aux->nom;
                arr[0][i]=aux->nom;
                aux=aux->sig;
            }
            //for encargado de llenar de infinitos la matriz
            for (int i=1;i<largo;i++){
                for (int a=1;a<largo;a++){
                    arr[i][a]=to_string(INF);
                    if(a==i){//if para poner 0 en la diagonal principal
                        arr[i][a]="0";
                    }
                }
            }
            aux=inicial;
            //Bloque de codigo para poder asignar los pesos de las aristas en la matriz
            for (int i=1;i<largo;i++){
                Arista *auxArt=aux->arist;
                while(auxArt!=nullptr){
                    for(int a=1;a<largo;a++){
                        if(a==i){continue;}
                        Vertice *auxVert=auxArt->referencia;
                        if (arr[0][a]==auxVert->nom){
                            arr[i][a]=to_string(auxArt->peso);
                            break;
                        }
                    }
                    auxArt=auxArt->sig;
                }
                aux=aux->sig;
            }
            cout<<std::endl;
            //Floyd Warshal;
            for (int a=1;a<largo;a++){
                for (int i=1;i<largo;i++){
                    for (int j=1;j<largo;j++){
                        if(stoi(arr[i][a])+stoi(arr[a][j])<stoi(arr[i][j])){
                            int suma=stoi(arr[i][a])+stoi(arr[a][j]);
                            arr[i][j]=to_string(suma);
                        }
                    }
                }
            }
            for (int i=0;i<largo;i++){
                salida+="| ";
                for (int j=0;j<largo;j++){
                    if (arr[i][j]==""){
                        salida+=arr[i][j];
                        salida+=("   |  ");
                        continue;
                    }
                    if (arr[i][j].length()<3){
                        salida+=arr[i][j];
                        salida+=("  |  ");
                        continue;
                    }
                    if(arr[i][j]=="999"){
                        salida.pop_back();
                        salida+=" INF";
                        salida+=(" | ");
                        continue;
                    }
                    salida+=arr[i][j];
                    salida+=(" | ");

                }
                salida+="\n";
            }
            return salida;

        }

    /**
     * @brief Metodo para probar el grafo en el cual ademas de hacer el floyd Warshall se impmrime el grafo antes y
     * despues de realizar dicho metodo para poder ver el cambio en el grafo
     */
    void prueba_matriz(){
        int largo;//cantidad de nodos en el grafo
        largo=lengrafo();
        largo++;
        string arr[largo] [largo];
        string salida;
        Vertice *aux=inicial;
        // for para poner el nombre del nodo en la primer fila y columna
        for (int i=1;i<largo;i++){
            arr[i][0]=aux->nom;
            arr[0][i]=aux->nom;
            aux=aux->sig;
        }
        //for encargado de llenar de infinitos la matriz
        for (int i=1;i<largo;i++){

            for (int a=1;a<largo;a++){

                arr[i][a]=to_string(INF);

                if(a==i){//if para poner 0 en la diagonal principal
                    arr[i][a]="0";
                }
            }
        }
        aux=inicial;

        //Bloque de codigo para poder asignar los pesos de las aristas en la matriz
        for (int i=1;i<largo;i++){
            Arista *auxArt=aux->arist;

            while(auxArt!=nullptr){
                for(int a=1;a<largo;a++){
                    if(a==i){
                        continue;
                    }
                    Vertice *auxVert=auxArt->referencia;

                    if (arr[0][a]==auxVert->nom){
                        arr[i][a]=to_string(auxArt->peso);

                        break;

                    }

                }
                auxArt=auxArt->sig;
            }
            aux=aux->sig;
        }

        cout<<"Grafo antes del Floyd Warshall"<<std::endl;
        //--------------
        //print de pueba
        //---------------
        for (int i=0;i<largo;i++){
            std::cout << "-"<<std::endl;
            for (int a=0;a<largo;a++){
                std::cout << "_";
                std::cout << arr[i][a] ;
            }
        }
        cout<<std::endl;
        //Floyd Warshal;
        cout<<"prueba "<<stoi(arr[1][2])<<std::endl;
        for (int a=1;a<largo;a++){
            for (int i=1;i<largo;i++){
                for (int j=1;j<largo;j++){

                    if(stoi(arr[i][a])+stoi(arr[a][j])<stoi(arr[i][j])){
                        int suma=stoi(arr[i][a])+stoi(arr[a][j]);
                        arr[i][j]=to_string(suma);
                    }
                }
            }
        }

        //--------------
        //print de pueba
        //---------------
        for (int i=0;i<largo;i++){
            std::cout << "-"<<std::endl;
            for (int a=0;a<largo;a++){
                std::cout << "_";
                std::cout << arr[i][a] ;
            }
        }
    }
    };

#endif //EXTRACLASE_1_GRAFO_H

