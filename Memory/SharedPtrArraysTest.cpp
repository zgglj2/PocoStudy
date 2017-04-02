#include <iostream>
#include "Poco/SharedPtr.h"

template <class C>
class ArrayReleasePolicy {
public:
    static void release(C* pObj) {
        std::cout << "pObj addr:" << std::hex << (void *)pObj << std::endl;
        delete [] pObj;
    }
};

int main(int argc, char **argv) {
    char* pStr = new char[100];
    std::cout << "pStr addr:" << std::hex << (void *)pStr << std::endl;
    Poco::SharedPtr<char, Poco::ReferenceCounter, ArrayReleasePolicy<char>> p(pStr);

    return 0;
}