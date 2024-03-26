#include <Poco/TemporaryFile.h>
#include <Poco/FileStream.h>
#include <Poco/Process.h>
#include <unistd.h>
#include <iostream>
#include "Poco/Exception.h"
using Poco::TemporaryFile;

int main(int argc, char** argv)
{
    TemporaryFile tmp;
    std::cout << tmp.path() << std::endl;

    std::string value = "./test.tmp";
    Poco::FileOutputStream ostr(value);
    if (ostr.good())
        ostr << Poco::Process::id() << std::endl;
    else
        throw Poco::CreateFileException("Cannot write PID to file", value);

    TemporaryFile::registerForDeletion(value);
    sleep(5);
    return 0;
}