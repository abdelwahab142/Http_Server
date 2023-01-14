#include "include/Include.h"
#include "include/Request_prepare.h"
#include "include/Socket.h"
#include "include/File_reader.h"
using namespace std;

int main()
{
    Socket Sock(88);
    Sock.Socket_prepare();
    int sockk = Sock.acc_sock;
    Sock.Request_Chat();
//    Request_prepare Req;
//    std::cout<<Req.Path_Cut("GET /html.html HTTP");

    return 0;
}
