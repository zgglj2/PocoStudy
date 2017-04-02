#include <iostream>
#include "Poco/String.h"

using Poco::toUpper;
using Poco::toLower;
using Poco::toUpperInPlace;
using Poco::toLowerInPlace;
using Poco::icompare;

int main(int argc, char **argv) {
    std::string hello("Hello world!!!");
    std::string s1(toUpper(hello));
    std::cout << "toUpper s1:" << s1 << std::endl;
    toLowerInPlace(s1);
    std::cout << "toLowerInPlace s1:" << s1 << std::endl;

    std::cout  << icompare(hello, s1) << std::endl;

    std::cout  << icompare(hello, "Hello universal") << std::endl;
    return 0;
}