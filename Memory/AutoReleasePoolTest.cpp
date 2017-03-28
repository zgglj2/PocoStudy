#include <iostream>
#include "Poco/AutoReleasePool.h"

class C {
public:
    C() {
        std::cout << __FUNCTION__ << std::endl;
    }

    void release() {
        delete this;
    }

protected:
    ~C() {
        std::cout << __FUNCTION__ << std::endl;
    }
};

int main(int argc, char **argv) {
    Poco::AutoReleasePool<C> pool;

    C* pC = new C;
    pool.add(pC);
    pC = new C;
    pool.add(pC);

    return 0;
}