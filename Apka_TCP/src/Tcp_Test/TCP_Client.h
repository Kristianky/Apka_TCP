#include<string>
#include <winsock2.h>

class TCPClient
{
private:
    SOCKET m_Socket;
public:
    TCPClient():m_Socket(INVALID_SOCKET){}
    ~TCPClient() {Disconect();};
    bool Connect();
    void Disconect();
    bool Send(const std::wstring Send_Data);
    std::wstring  Recieve();
    std::wstring String_To_Wstring();
    std::string Wstring_To_String (const std::wstring Send_Data);
};