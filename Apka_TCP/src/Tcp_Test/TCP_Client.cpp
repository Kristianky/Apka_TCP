#include "TCP_Client.h"

bool TCPClient::Connect()
{
    WSADATA Wsa_Data;
    int res = WSAStartup(MAKEWORD(2, 2), &Wsa_Data);
    if (res != 0)
    {
        return false;
    }
    m_Socket = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);

    sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(12345);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    int result = connect(m_Socket,(SOCKADDR*)&server,sizeof(server));

    if (result == INVALID_SOCKET)
    {
        closesocket (m_Socket);
        WSACleanup();
        m_Socket = INVALID_SOCKET;
        return false;
    }


    return true;
}

void TCPClient::Disconect()
{
    closesocket(m_Socket);
    m_Socket = INVALID_SOCKET;
    WSACleanup();

}