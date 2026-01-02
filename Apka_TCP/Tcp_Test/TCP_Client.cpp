#include "TCP_Client.h"

bool TCPClient::Connect()
{
    WSADATA Wsa_Data;
    int res = WSAStartup(MAKEWORD(2, 2), &Wsa_Data);
    if (res == 0)
    {
        return false;
    }
    SOCKET Sock = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);

    sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(12345);
    server.sin_addr.s_addr = inet_addr("127.168.0.1");

    int result = connect(Sock,(SOCKADDR*)&server,sizeof(server));

    if (result == INVALID_SOCKET)
    {
        closesocket (Sock);
        WSACleanup;
        return false;
    }
    return true;
}