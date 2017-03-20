#include "Poco/DynamicAny.h"
#include <iostream>
#include <string>

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

    std::string ss = "/var/log/.tect/tect1.log";
    size_t pos = ss.rfind(".log", ss.npos, 4);
    std::cout << pos << std::endl;
    std::cout << ss.find(".log") << std::endl;
    std::cout << ss.erase(pos, 4) << std::endl;
    return 0;
}