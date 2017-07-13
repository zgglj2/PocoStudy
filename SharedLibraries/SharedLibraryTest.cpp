//
// Created by outer-glj on 2017/5/25.
//

#include "Poco/SharedLibrary.h"
#include <iostream>

using Poco::SharedLibrary;

typedef void (*HelloFunc)(); // function pointer type
int main(int argc, char **argv) {
    std::string path;
#if POCO_OS == POCO_OS_WINDOWS_NT
    std::cout << "POCO_OS_WINDOWS_NT" <<std::endl;
#elif POCO_OS == POCO_OS_LINUX
    std::cout << "POCO_OS_LINUX" <<std::endl;
#elif POCO_OS == POCO_OS_CYGWIN
    std::cout << "POCO_OS_CYGWIN" << std::endl;
    path = "cyg";
#endif
    path.append("TestLibrary");
    path.append(SharedLibrary::suffix());

    SharedLibrary library(path);
    HelloFunc func = (HelloFunc) library.getSymbol("hello");
    func();
    library.unload();
    return 0;
}

