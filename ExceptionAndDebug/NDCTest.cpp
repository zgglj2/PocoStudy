#include <iostream>
#include "Poco/NestedDiagnosticContext.h"

void f1() {
    poco_ndc(f1);
    Poco::NDC::current().dump(std::cout);
}

void f2() {
    poco_ndc(f2);
    f1();
}

int main(int argc, char **argv) {
    poco_ndc(main);
    f2();
    return 0;
}