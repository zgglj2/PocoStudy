#include "Poco/TeeStream.h"
#include <iostream>

using Poco::TeeInputStream;
using Poco::TeeOutputStream;

int main(int argc, char **argv) {
    TeeOutputStream teeOut;

    teeOut.addStream(std::cout);
    teeOut.addStream(std::cout);

    teeOut << "Hello World!!!" << std::endl;

    return 0;
}