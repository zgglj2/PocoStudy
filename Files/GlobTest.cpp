//
// Created by outer-glj on 2017/5/25.
//

#include "Poco/Glob.h"
#include <iostream>

using Poco::Glob;

int main(int argc, char **argv) {
    std::set<std::string> files;
//    Glob::glob("%WINDIR%\\system32\\*.exe", files);
//    Glob::glob("/usr/include/*/*.h", files);
    Glob::glob("./*.exe", files);
    std::set<std::string>::iterator it = files.begin();
    for (; it != files.end(); ++it) {
        std::cout << *it << std::endl;
    }
    return 0;
}