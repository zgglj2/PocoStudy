#include <Poco/FileStream.h>
#include <fstream>
#include <sstream>
#include <iostream>

using Poco::FileStream;
using Poco::FileInputStream;
using Poco::FileOutputStream;

int main(int argc, char **argv) {
    FileStream fs("fs.txt");
    fs << "Hello World";
    fs << 12345;
    fs << true;

    fs.flush();
    fs.close();

    std::stringstream ss;
    FileInputStream fin("fs.txt");
    while (fin.good()) {
        std::cout << fin.get() << std::endl;
    }

    return 0;
}