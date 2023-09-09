#include <Poco/Thread.h>
#include <Poco/Event.h>
#include <iostream>

using Poco::Thread;
using Poco::Runnable;
using Poco::Event;
using namespace std;

class Worker : public Runnable {
public:
    Worker(Event &_evt) : _evt(_evt) {}

    void run()  {
        _evt.wait();
        cout << Poco::Thread::currentTid() << " get event1!!" << endl;
        _evt.wait();
        cout << Poco::Thread::currentTid() << " get event2!!" << endl;
    }

private:
    Event &_evt;
};

int main(int argc, char **argv) {
//    Event evt(false);
    Event evt(true);
    Worker worker1(evt);
    Worker worker2(evt);
    Worker worker3(evt);

    Thread thread1;
    Thread thread2;
    Thread thread3;
    try {

        thread1.start(worker1);
        thread2.start(worker2);
        thread3.start(worker3);
        Poco::Thread::sleep(100);
        evt.set();
        Poco::Thread::sleep(100);
        evt.set();
        Poco::Thread::sleep(100);
        evt.set();
        Poco::Thread::sleep(100);
        evt.set();
        Poco::Thread::sleep(100);
        evt.set();
        Poco::Thread::sleep(100);
        evt.set();

//        Poco::Thread::sleep(1000);
//        evt.set();

        thread1.join();
        thread2.join();
        thread3.join();
    } catch (Poco::Exception &exp) {
        cout << exp.displayText() << endl;
    }


    return 0;
}