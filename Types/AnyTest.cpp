#include "Poco/Any.h"
#include <iostream>

using Poco::Any;
using Poco::AnyCast;
using Poco::RefAnyCast;

int main(int argc, char **argv) {
    Any any(42);

    int i = AnyCast<int>(any);
    int &j = RefAnyCast<int>(any);

    std::cout << std::dec << i << std::endl;
    std::cout << std::dec << j << std::endl;

    try {
        short s = AnyCast<short>(any);
    } catch (Poco::BadCastException &exp) {
        std::cout << exp.displayText() << std::endl;

    }

    return 0;
}