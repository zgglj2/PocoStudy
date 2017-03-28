#include <iostream>
#include "Poco/AutoPtr.h"
#include "Poco/RefCountedObject.h"


class RC0 : public Poco::RefCountedObject {
public:
    RC0() {
        std::cout << __FUNCTION__ << " : refcount:" << referenceCount() << std::endl;
    }

    void greet() const {
        std::cout << "Hello, world!" << std::endl;
    }

protected:
    ~RC0() {
        std::cout << __FUNCTION__ << " : refcount:" << referenceCount() << std::endl;
    }

};


class A : public Poco::RefCountedObject {
public:
    A() {
        std::cout << __FUNCTION__ << " : refcount:" << referenceCount() << std::endl;
    }

protected:
    ~A() {
        std::cout << __FUNCTION__ << " : refcount:" << referenceCount() << std::endl;
    }
};

class B : public A {
public:
    B() {
        std::cout << __FUNCTION__ << " : refcount:" << referenceCount() << std::endl;
    }

protected:
    ~B() {
        std::cout << __FUNCTION__ << " : refcount:" << referenceCount() << std::endl;
    }
};

class C : public Poco::RefCountedObject {
public:
    C() {
        std::cout << __FUNCTION__ << " : refcount:" << referenceCount() << std::endl;
    }

protected:
    ~C() {
        std::cout << __FUNCTION__ << " : refcount:" << referenceCount() << std::endl;
    }
};

int main(int argc, char **argv) {
    Poco::AutoPtr<RC0> pRC0(new RC0);
    pRC0->greet();
    (*pRC0).greet();

    std::cout << __FUNCTION__ << " pRC0 : refcount:" << pRC0->referenceCount() << std::endl;

    RC0 *p1 = pRC0;
    RC0 *p2 = pRC0.get();
    std::cout << __FUNCTION__ << " pRC0 : refcount:" << pRC0->referenceCount() << std::endl;

    std::cout << "---------------------------------------------------------" << std::endl;
    Poco::AutoPtr<A> pA;
    Poco::AutoPtr<B> pB(new B);
    std::cout << __FUNCTION__ << " pB : refcount:" << pB->referenceCount() << std::endl;
    pA = pB;
    std::cout << __FUNCTION__ << " pA : refcount:" << pA->referenceCount() << std::endl;
    std::cout << __FUNCTION__ << " pB : refcount:" << pB->referenceCount() << std::endl;
    pA = new B;
    std::cout << __FUNCTION__ << " pA : refcount:" << pA->referenceCount() << std::endl;
    std::cout << __FUNCTION__ << " pB : refcount:" << pB->referenceCount() << std::endl;
    pB = pA.cast<B>();
    std::cout << __FUNCTION__ << " pA : refcount:" << pA->referenceCount() << std::endl;
    std::cout << __FUNCTION__ << " pB : refcount:" << pB->referenceCount() << std::endl;
    Poco::AutoPtr<C> pC(new C);
    pA = pC.cast<A>();
    std::cout << __FUNCTION__ << " pA : isNull:" << pA.isNull() << std::endl;

    std::cout << "---------------------------------------------------------" << std::endl;
    Poco::AutoPtr<A> pp1(new A);
    A *ppA = pp1;
    std::cout << __FUNCTION__ << " pp1 : refcount:" << pp1->referenceCount() << std::endl;
    //Poco::AutoPtr<A> pp2(pA);
    Poco::AutoPtr<A> pp2(ppA, true);
    std::cout << __FUNCTION__ << " pp1 : refcount:" << pp2->referenceCount() << std::endl;
    Poco::AutoPtr<A> pp3;
    //pp3 = ppA;
    pp3.assign(ppA, true);
    std::cout << __FUNCTION__ << " pp1 : refcount:" << pp2->referenceCount() << std::endl;


    return 0;
}











