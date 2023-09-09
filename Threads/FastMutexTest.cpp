#include <Poco/Thread.h>
#include <Poco/Mutex.h>
#include <iostream>

using Poco::Thread;
using Poco::Runnable;
using Poco::FastMutex;
using namespace std;

class Worker : public Runnable {
public:
    Worker(FastMutex &_mtx) : _mtx(_mtx) {}

    void run()  {
        _mtx.lock();
//        _mtx.lock();
        cout << Poco::Thread::currentTid() << " get mutex!!" << endl;
        Poco::Thread::sleep(2000);
        _mtx.unlock();
//        _mtx.unlock();
    }

private:
    FastMutex& _mtx;
};

int main(int argc, char **argv) {
    FastMutex mtx;
    Worker worker1(mtx);
    Worker worker2(mtx);

    Thread thread1;
    Thread thread2;
    thread1.start(worker1);
    thread2.start(worker2);
    thread1.join();
    thread2.join();

    return 0;
}