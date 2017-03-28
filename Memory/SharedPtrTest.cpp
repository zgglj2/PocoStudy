#include <iostream>
#include "Poco/SharedPtr.h"

class A {
public:
    virtual ~A() {}
};

class B : public A {
};

class C : public B {
};

int main(int argc, char **argv) {
    std::string *pString = new std::string("hello, world");

    Poco::SharedPtr<std::string> p1(pString);
    Poco::SharedPtr<std::string> p2(p1);
    std::cout << __FUNCTION__ << " p1 : refcount:" << p1.referenceCount() << std::endl;
    p2 = 0;
    std::cout << __FUNCTION__ << " p1 : refcount:" << p1.referenceCount() << std::endl;
    //p2 = pString
    p2 = p1;
    std::cout << __FUNCTION__ << " p1 : refcount:" << p1.referenceCount() << std::endl;

    std::string::size_type len = p1->length();
    std::cout << *p1 << std::endl;

    std::cout << "---------------------------------------------------------" << std::endl;
    Poco::SharedPtr<A> pA;
    Poco::SharedPtr<B> pB(new B);
    std::cout << __FUNCTION__ << " pB : refcount:" << pB.referenceCount() << std::endl;
    pA = pB;
    std::cout << __FUNCTION__ << " pA : refcount:" << pA.referenceCount() << std::endl;
    std::cout << __FUNCTION__ << " pB : refcount:" << pB.referenceCount() << std::endl;
    pA = new B;
    std::cout << __FUNCTION__ << " pA : refcount:" << pA.referenceCount() << std::endl;
    std::cout << __FUNCTION__ << " pB : refcount:" << pB.referenceCount() << std::endl;
    pB = pA.cast<B>();
    std::cout << __FUNCTION__ << " pA : refcount:" << pA.referenceCount() << std::endl;
    std::cout << __FUNCTION__ << " pB : refcount:" << pB.referenceCount() << std::endl;
    Poco::SharedPtr<C> pC(new C);
//    pB = pC.cast<B>();
//    std::cout << __FUNCTION__ << " pA : isNull:" << pB.isNull() << std::endl;

    return 0;
}