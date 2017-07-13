#include <Poco/Thread.h>
#include <Poco/RunnableAdapter.h>
#include <iostream>

using Poco::Thread;
using Poco::Runnable;
using Poco::RunnableAdapter;
using namespace std;

class HelloRunnable : public Runnable {
public:
    void run() override {
        cout << "Hello World!!" << endl;
    }

};

class Greeter {
public:
    void greet() {
        cout << "Hello HelloRunnableAdapter!!" << endl;
    }

};

int main(int argc, char **argv) {
    HelloRunnable runnable;

    Thread thread;
    thread.start(runnable);
    thread.join();

    Greeter greeter;
    RunnableAdapter<Greeter> adapter(greeter, &Greeter::greet);
    Thread thread2;
    thread.start(adapter);
    thread.join();
    return 0;
}