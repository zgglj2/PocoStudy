#include "Poco/ByteOrder.h"
#include <iostream>

using Poco::ByteOrder;
using Poco::UInt16;

int main(int argc, char **argv) {
#ifdef POCO_ARCH_LITTLE_ENDIAN
    std::cout << "little endian" << std::endl;
#else
    std::cout << "big endian" << std::endl;
#endif
    UInt16 port = 80;
    UInt16 networkPort = ByteOrder::toNetwork(port);

    std::cout << "0x" << std::hex << networkPort << std::endl;
    return 0;
}