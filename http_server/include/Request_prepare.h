#include "Include.h"
#ifndef REQUEST_PREPARE_H
#define REQUEST_PREPARE_H


class Request_prepare
{
    private:
        std::string Methods_str[3] = {"GET","POST"};
        enum Methods{GET,POST};

    public:
        Request_prepare();
        virtual ~Request_prepare();
        int Request_Methode(std::string Request);
        std::string Path_Cut(std::string Req);
    protected:

};

#endif // REQUEST_PREPARE_H
