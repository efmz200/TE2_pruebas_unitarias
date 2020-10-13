// Client side C/C++ program to demonstrate Socket programming
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
using namespace std;
#define PORT 8080

string cliente_serv()
{
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char *hello = "Floyd Warshall";
    char buffer[1024] = {0};
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return "-1";
    }
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)
    {
        printf("\nInvalid address/ Address not supported \n");
        return "-1";
    }
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        return "-1";
    }
    send(sock , hello , strlen(hello) , 0 );
    printf("Petición Enviada\n");
    valread = read( sock , buffer, 1024);
    printf("%s\n",buffer );
    return string(buffer);
}
