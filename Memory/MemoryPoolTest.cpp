#include <iostream>
#include "Poco/MemoryPool.h"

using Poco::MemoryPool;

int main(int argc, char **argv) {
    try {
//    MemoryPool pool(10); // unlimited number of 1024 byte blocks
        MemoryPool pool(10, 1, 1); // at most 16 blocks; 4 preallocated
        char *buffer = reinterpret_cast<char *>(pool.get());
        std::cin.read(buffer, pool.blockSize());
        std::streamsize n = std::cin.gcount();
        std::string s(buffer, n);

        char *buffer2 = reinterpret_cast<char *>(pool.get());
        std::cin.read(buffer2, pool.blockSize());
        std::streamsize n2 = std::cin.gcount();
        std::string s2(buffer2, n2);

        pool.release(buffer);
        std::cout << s << std::endl;
        pool.release(buffer2);
        std::cout << s2 << std::endl;
    } catch (Poco::Exception &exp) {
        std::cout << exp.displayText() << std::endl;
    }

    return 0;
}