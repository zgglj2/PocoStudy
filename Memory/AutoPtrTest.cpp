#include <iostream>
#include "Poco/AutoPtr.h"

class RC0 {
public:
    RC0() : _rc(1) {
        std::cout << __FUNCTION__ << " : Count=" << _rc << std::endl;
    }

    void duplicate() {
        ++_rc;
        std::cout << __FUNCTION__ << " : Count:" << _rc << std::endl;
    }

    void release() {
        --_rc;
        std::cout << __FUNCTION__ << " : Count:" << _rc << std::endl;
        if (_rc == 0) {
            delete this;
        }
    }

private:
    int _rc;

};

int main(int argc, char **argv) {
    RC0 *pNew = new RC0;
    Poco::AutoPtr<RC0> p1(pNew);
    Poco::AutoPtr<RC0> p2(p1);
    Poco::AutoPtr<RC0> p3(pNew, true);
    p2 = 0;
    p3 = 0;
    RC0 *pRC0 = p1;
    p1 = 0;
    p1 = new RC0;

    return 0;
}