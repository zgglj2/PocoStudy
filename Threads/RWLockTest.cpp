#include <Poco/Thread.h>
#include <Poco/RWLock.h>
#include <iostream>

using Poco::Thread;
using Poco::Runnable;
using Poco::RWLock;
using namespace std;

class Worker1 : public Runnable {
public:
    Worker1(RWLock &_rwlock) : _rwlock(_rwlock) {}

    void run() override {
        _rwlock.readLock();
        cout << Poco::Thread::currentTid() << " get readlock!!" << endl;
        Poco::Thread::sleep(1000);
        _rwlock.unlock();
    }

private:
    RWLock &_rwlock;
};
class Worker2 : public Runnable {
public:
    Worker2(RWLock &_rwlock) : _rwlock(_rwlock) {}

    void run() override {
        _rwlock.writeLock();
        cout << Poco::Thread::currentTid() << " get writelock!!" << endl;
        Poco::Thread::sleep(2000);
        _rwlock.unlock();
    }

private:
    RWLock &_rwlock;
};

int main(int argc, char **argv) {
    RWLock rwlock;
    Worker1 worker1(rwlock);
    Worker1 worker2(rwlock);
    Worker2 worker3(rwlock);
    Worker1 worker4(rwlock);

    Thread thread1;
    Thread thread2;
    Thread thread3;
    Thread thread4;
    try {

        thread1.start(worker1);
        thread2.start(worker2);
        Poco::Thread::sleep(100);
        thread3.start(worker3);
        thread4.start(worker4);
        Poco::Thread::sleep(100);

        thread1.join();
        thread2.join();
        thread3.join();
        thread4.join();
    } catch (Poco::Exception &exp) {
        cout << exp.displayText() << endl;
    }


    return 0;
}