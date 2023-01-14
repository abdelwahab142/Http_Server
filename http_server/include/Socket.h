#include "Include.h"
#include "Request_prepare.h"
#include "File_reader.h"
#ifndef SOCKET_H
#define SOCKET_H

int getSO_ERROR(int fd);

void closeSocket(int fd);

class Socket
{
    private:
        int sock;
        sockaddr_in hint,acc_hin;

    public:
        int acc_sock;
        Socket(int port);
        virtual ~Socket();
        int Socket_prepare();
        void Request_Chat();


    protected:

};

#endif // SOCKET_H
