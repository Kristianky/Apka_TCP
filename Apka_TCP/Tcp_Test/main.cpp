#include <iostream>
#include <winsock2.h>

#pragma coment(lib,"ws2_32.lib")

int main() {
    WSADATA wsaData;
    SOCKET serversocket,clientsocket;
    sockaddr_in serverAddr{},clientaddr{};
    int clientSize;
    char buffer[1024];

    //Iniciovanie winsocku
    if (WSAStartup(MAKEWORD(2,2),&wsaData)!=0){
        std::cerr<<"Wsas startup zlyhal";
        return -1;
}
    serversocket = socket(AF_INET,SOCK_STREAM,0);
    if (serversocket == INVALID_SOCKET){
        std::cerr<<"Vytovrenie socketu zlyhalo";
        return -1;
    }
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(10100);
    serverAddr.sin_addr.s_addr = inet_addr("192.168.10.2");
if (bind(serversocket,(sockaddr*)&serverAddr,sizeof(sockaddr))==SOCKET_ERROR){
    std::cerr<<"Binding zlyhal";
    closesocket;
    WSACleanup;
    return -1;
}
if (listen(serversocket,SOMAXCONN)==SOCKET_ERROR){
    std::cerr<<"Pocuvanie zlyhalo";
    closesocket;
    WSACleanup;
    return -1;
}
std::cout<<"Server pocuva na 192.168.10.2";

clientSize = sizeof(clientaddr);
clientsocket = accept(serversocket,(sockaddr*)&clientaddr,&clientSize);
if (clientsocket==INVALID_SOCKET){
    std::cerr<<"Socket nepocuva";
    closesocket(serversocket);
    WSACleanup;
    return -1;
}
std::cout<<"client pripojeny";

int recieved = recv(clientsocket,buffer,sizeof(buffer) - 1,0);
if(recieved > 0) {
    buffer[recieved] = '/0';
    std::cout<<"Prijata sprava:"<<buffer<<std::endl;
}
else{
    std::cerr<<"Client zavrel spojenie zlyhalo";
}

closesocket(clientsocket);
closesocket(serversocket);
WSACleanup;
}