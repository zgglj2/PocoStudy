#include "Poco/DirectoryIterator.h"
#include <iostream>

using Poco::DirectoryIterator;
using Poco::Path;

int main(int argc, char **argv) {
    std::string cwd(Path::current());
    DirectoryIterator it(cwd);
    DirectoryIterator end;
    while (it != end) {
        std::cout << "Name: " << it.name();
        if (it->isFile())
            std::cout << ", Size: " << it->getSize();
        std::cout << std::endl;
        Path p(it.path());
        ++it;
    }
    return 0;
}