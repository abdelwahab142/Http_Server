#include "Request_prepare.h"

Request_prepare::Request_prepare()
{

}

int Request_prepare::Request_Methode(std::string Request){
    std::cout<<Request<<std::endl;

    for(int i=0;i<2;i++){
        if(strstr(Request.c_str(),Methods_str[i].c_str())){
            return i;
        }
    }

    return -1;
}
std::string Request_prepare::Path_Cut(std::string Req){
    std::string Ret_str = Req.substr(Req.find('/')+1,Req.find('H')-Req.find('/')-2);

    return Ret_str;

}

Request_prepare::~Request_prepare()
{
    //dtor
}
