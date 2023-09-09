#include <Poco/Thread.h>
#include <Poco/Semaphore.h>
#include <iostream>

using Poco::Thread;
using Poco::Runnable;
using Poco::Semaphore;
using namespace std;

class Worker : public Runnable {
public:
    Worker(Semaphore &_sema) : _sema(_sema) {}

    void run()  {
        _sema.wait();
        cout << Poco::Thread::currentTid() << " get event1!!" << endl;
        _sema.wait();
        cout << Poco::Thread::currentTid() << " get event2!!" << endl;
    }

private:
    Semaphore &_sema;
};

int main(int argc, char **argv) {
    Semaphore sema(0, 10);
    Worker worker1(sema);
    Worker worker2(sema);
    Worker worker3(sema);

    Thread thread1;
    Thread thread2;
    Thread thread3;
    try {

        thread1.start(worker1);
        thread2.start(worker2);
        thread3.start(worker3);
        Poco::Thread::sleep(100);
        sema.set();
        sema.set();
        sema.set();
        sema.set();
        sema.set();
        sema.set();

        thread1.join();
        thread2.join();
        thread3.join();
    } catch (Poco::Exception &exp) {
        cout << exp.displayText() << endl;
    }


    return 0;
}