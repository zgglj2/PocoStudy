#include <Poco/Thread.h>
#include <Poco/RunnableAdapter.h>
#include <Poco/ErrorHandler.h>
#include <iostream>

using Poco::Thread;
using Poco::Runnable;
using Poco::RunnableAdapter;
using Poco::ErrorHandler;
using namespace std;

class MyErrorHandler : public Poco::ErrorHandler {
public:
    void exception(const Poco::Exception &exc) {
        std::cerr << exc.displayText() << std::endl;
    }

    void exception(const std::exception &exc) {
        std::cerr << exc.what() << std::endl;
    }

    void exception() {
        std::cerr << "unknown exception" << std::endl;
    }
};

class HelloRunnable : public Runnable {
public:
    void run() override {
        throw Poco::ApplicationException("got you");
    }

};

int main(int argc, char **argv) {
    MyErrorHandler eh;
    ErrorHandler* pOldEh = Poco::ErrorHandler::set(&eh);

    HelloRunnable runnable;

    Thread thread;
    thread.start(runnable);
    thread.join();
    cout << "test test test" << endl;
    Poco::ErrorHandler::set(pOldEh);
    return 0;
}