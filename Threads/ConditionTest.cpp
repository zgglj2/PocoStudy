#include <Poco/Thread.h>
#include <Poco/Mutex.h>
#include <Poco/Condition.h>
#include <iostream>

using Poco::Thread;
using Poco::Runnable;
using Poco::Mutex;
using Poco::Condition;
using namespace std;

class Worker : public Runnable {
public:
    Worker(Mutex &_mtx, Condition &_cond) : _mtx(_mtx), _cond(_cond) {}

    void run() override {
        _mtx.lock();
        _cond.wait(_mtx);
        cout << Poco::Thread::currentTid() << " get mutex!!" << endl;
        _mtx.unlock();
    }

private:
    Mutex &_mtx;
    Condition &_cond;
};

int main(int argc, char **argv) {
    Mutex mtx;
    Condition cond;
    Worker worker1(mtx, cond);
    Worker worker2(mtx, cond);
    Worker worker3(mtx, cond);

    Thread thread1;
    Thread thread2;
    Thread thread3;
    try {

        thread1.start(worker1);
        Thread::sleep(1000);
        thread2.start(worker2);
        thread3.start(worker3);

        cond.signal();
        thread1.join();
        cond.broadcast();
        thread2.join();
        thread3.join();
    } catch (Poco::Exception &exp) {
        cout << exp.displayText() << endl;
    }


    return 0;
}