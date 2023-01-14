#include "include/Include.h"
#include "include/Request_prepare.h"
#include "include/Socket.h"
#include "include/File_reader.h"
using namespace std;

int main()
{
//    Socket Sock(83);
//    Sock.Socket_prepare();
//    int sockk = Sock.acc_sock;
//    Sock.Request_Chat();
//
//    Request_prepare Req;
//    int RetReq = Req.Request_Methode("POST  /hello");
//
//    cout<<RetReq<<endl;

    string Out;
    File_reader Fread;
    Fread.File_Read(Out,"/include/Include.h");

    return 0;
}
