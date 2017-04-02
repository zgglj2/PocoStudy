#include <iostream>
#include "Poco/Buffer.h"

int main(int argc, char **argv) {
    Poco::Buffer<char> buffer(5);
    buffer[0] = 't';
    buffer[1] = 't';
    buffer[2] = 't';
    buffer[3] = 't';
    buffer[4] = '\0';
    std::cout << "buffer:" << buffer.begin() << ", len:" << buffer.size() << std::endl;

    std::string s(buffer.begin(), buffer.size());

    std::cout << s << std::endl;

    return 0;
}