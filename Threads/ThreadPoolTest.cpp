#include <Poco/ThreadPool.h>
#include <iostream>

using Poco::ThreadPool;
using Poco::Runnable;
using namespace std;

class HelloRunnable : public Runnable {
public:
    void run() override {
        cout << "Hello World!!" << endl;
    }

};

int main(int argc, char **argv) {
    HelloRunnable runnable;

    ThreadPool::defaultPool().start(runnable);
    ThreadPool::defaultPool().joinAll();
    return 0;
}