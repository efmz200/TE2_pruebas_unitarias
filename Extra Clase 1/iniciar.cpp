#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string>
#include <string.h>
#include "Server.cpp"
#include "Grafo.h"
using namespace std;

/**
 * @brief metodo que inicia el server
 */
void start(){
    Server *server=new Server();
    string msg=server->prueba();
    serv(msg);
}