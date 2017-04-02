#include <iostream>
#include "Poco/String.h"

using Poco::trim;
using Poco::trimLeft;
using Poco::trimRight;
using Poco::trimRightInPlace;

int main(int argc, char **argv) {
    std::string hello("  Hello world!!!  ");
    std::string s1(trimLeft(hello));
    std::cout << "s1:" << s1 << std::endl;
    trimRightInPlace(s1);
    std::cout << "s1:" << s1 << std::endl;
    std::string s2(trim(hello));
    std::cout << "s2:" << s2 << std::endl;

    return 0;
}