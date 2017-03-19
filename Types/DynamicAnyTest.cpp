#include "Poco/DynamicAny.h"
#include <iostream>

using Poco::DynamicAny;

int main(int argc, char **argv) {
    DynamicAny any(42);

    int i = any;
    std::cout << std::dec << i << std::endl;

    std::string s(any.convert<std::string>());
    std::cout << s << std::endl;

    const int& j = any.extract<int>();
    std::cout << std::dec << j << std::endl;

    try {
        short s = any.extract<short>();
    } catch (Poco::BadCastException &exp) {
        std::cout << exp.displayText() << std::endl;

    }

    return 0;
}