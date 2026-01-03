#include "Pages.h"
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
};