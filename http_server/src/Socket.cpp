#include "Socket.h"

std::string str="HTTP/1.0 200 OK\r\nServer: Simple\http/1.0\r\nDate: Sat, 14 Jan 2023 13:45:11 GMT\r\nContent-type: text/html; charset=utf-8\nContent-Length: 1545\r\n\r\n\n";

int getSO_ERROR(int fd) {
   int err = 1;
   socklen_t len = sizeof err;
   if (-1 == getsockopt(fd, SOL_SOCKET, SO_ERROR, (char *)&err, &len))
      printf("getSO_ERROR");
   if (err)
      errno = err;              // set errno to the socket SO_ERROR
   return err;
}

void closeSocket(int fd) {      // *not* the Windows closesocket()
   if (fd >= 0) {
      getSO_ERROR(fd); // first clear any errors, which can cause close to fail
      if (shutdown(fd, SHUT_RDWR) < 0) // secondly, terminate the 'reliable' delivery
         if (errno != ENOTCONN && errno != EINVAL) // SGI causes EINVAL
            std::cerr<<"shutdown";
      if (close(fd) < 0) // finally call close()
         std::cerr<<"close";
   }
}


Socket::Socket(int port)
{
    //ctor
    sock = socket(AF_INET,SOCK_STREAM,0);
    hint.sin_addr.s_addr = INADDR_ANY;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(port);
}

int Socket::Socket_prepare(){
    bind(sock,(sockaddr*)&hint,sizeof(hint));
    listen(sock,1);

    int len = sizeof(acc_hin);




}

void Socket::Request_Chat(){
    char buff[4096+1];
    Request_prepare Req;
    File_reader FileRead;
    std::string Out;
    std::string ALl_Send;
    std::string HE;
    std::string HH;

    while(1){
        sockaddr_in client;
        socklen_t clientSize = sizeof(client);

        acc_sock = accept(sock,(sockaddr*)&client, &clientSize);

        if(recv(acc_sock,buff,4096,0)<0)
            break;

        HE = buff;
        HH=Req.Path_Cut(HE);

        FileRead.File_Read(Out,HH);

        std::cout<<Out;
        ALl_Send = str;
        ALl_Send+=Out;

        std::cout<<ALl_Send<<std::endl;
        int RetReq = Req.Request_Methode(buff);
        std::string rec(buff);
        if(RetReq==0){
            send(acc_sock,ALl_Send.c_str(),ALl_Send.size(),0);
            close(acc_sock);
        }
        else{
            close(acc_sock);
        }
        ALl_Send.clear();
    }

}

Socket::~Socket()
{

}
