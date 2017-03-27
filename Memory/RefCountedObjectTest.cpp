#include <iostream>
#include "Poco/AutoPtr.h"
#include "Poco/RefCountedObject.h"


class RC0 : public Poco::RefCountedObject {
public:
    RC0() {
        std::cout << __FUNCTION__ << " : refcount:" << referenceCount() <<std::endl;
    }

    void greet() const {
        std::cout << "Hello, world!" << std::endl;
    }

protected:
    ~RC0() {
        std::cout << __FUNCTION__ << " : refcount:" << referenceCount() <<std::endl;
    }

};

int main(int argc, char **argv) {
    Poco::AutoPtr<RC0> pRC0(new RC0);
    pRC0->greet();
    (*pRC0).greet();

    std::cout << __FUNCTION__ << " : refcount:" << pRC0->referenceCount() <<std::endl;

    RC0* p1 = pRC0;
    RC0* p2 = pRC0.get();
    std::cout << __FUNCTION__ << " : refcount:" << pRC0->referenceCount() <<std::endl;

    return 0;
}