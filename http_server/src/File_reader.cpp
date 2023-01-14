#include "File_reader.h"

File_reader::File_reader()
{
    //ctor
}

int File_reader::File_Read(std::string &Output,std::string File_Path){
    std::string app_path= get_path().substr(0,get_path().find_last_of('/'));
    std::string ALL_Path = "main.html";

    if(File_Path ==ALL_Path){
        std::cout<<"Equal"<<std::endl;
    }
    std::cout<<File_Path;


    std::cout<<ALL_Path<<std::endl;
    Output="";


    std::ifstream inp(File_Path,std::ios::in);
    std::cout<<inp.is_open();

    while(inp){
        Output+=inp.get();
    }
    std::cout<<Output;
    Output = Output.substr(0,Output.size()-1);
    inp.close();
}
std::string File_reader::get_path()
{
        char arg1[20];
        char exepath[PATH_MAX + 1] = {0};

        sprintf( arg1, "/proc/%d/exe", getpid() );
        readlink( arg1, exepath, PATH_MAX );
        return std::string( exepath );
}

File_reader::~File_reader()
{
    //dtor
}
