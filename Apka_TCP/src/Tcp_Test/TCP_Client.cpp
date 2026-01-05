#include "TCP_Client.h"

bool TCPClient::Connect()
{
    WSADATA Wsa_Data;
    int res = WSAStartup(MAKEWORD(2, 2), &Wsa_Data);
    if (res != 0)
    {
        return false;
    }
    m_Socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(12345);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    int result = connect(m_Socket, (SOCKADDR *)&server, sizeof(server));

    if (result == INVALID_SOCKET)
    {
        closesocket(m_Socket);
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

std::string TCPClient::Wstring_To_String(const std::wstring Send_Data)
{
    int Lenght = WideCharToMultiByte(CP_UTF8, 0, Send_Data.c_str(), -1, nullptr, 0, nullptr, nullptr);
    std::string Send_Buffer;
    Send_Buffer.resize(Lenght - 1);
    WideCharToMultiByte(CP_UTF8, 0, Send_Data.c_str(), -1, Send_Buffer.data(), Lenght, nullptr, nullptr);
    return Send_Buffer;
}

std::wstring TCPClient::String_To_Wstring()
{
}

bool TCPClient::Send(const std::wstring Send_Data)
{
    std::string Send_Buffer = Wstring_To_String(Send_Data);
    int Send_Erorr = send(m_Socket,Send_Buffer.c_str(),Send_Buffer.length(),0);
    if(Send_Erorr == SOCKET_ERROR)
    {
        return false;
    }
    return true;
}