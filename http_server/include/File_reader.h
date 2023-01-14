#include "Include.h"
#ifndef FILE_READER_H
#define FILE_READER_H


class File_reader
{
    public:
        File_reader();
        virtual ~File_reader();
        int File_Read(std::string& Output,std::string File_Path);
        std::string get_path();

    protected:

    private:
};

#endif // FILE_READER_H
