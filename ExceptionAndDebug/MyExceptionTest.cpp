#include <iostream>
#include "MyException.h"


int main(int argc, char **argv) {
    try {
        throw MyException("Something really bad happened...");
    }
    catch (MyException &exc) {
        std::cerr << exc.displayText() << std::endl;
    }

    Poco::Exception* pExc = NULL;
    try {
        throw Poco::ApplicationException("just testing");
    }
    catch (Poco::Exception& exc) {
        pExc = exc.clone();
    }

    try {
        pExc->rethrow();
    }
    catch (Poco::Exception& exc) {
        std::cerr << exc.displayText() << std::endl;
    }
    return 0;
}