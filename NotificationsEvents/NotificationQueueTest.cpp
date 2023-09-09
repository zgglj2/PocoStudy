#include <Poco/NotificationQueue.h>
#include <Poco/Notification.h>
#include <Poco/AutoPtr.h>
#include <Poco/ThreadPool.h>
#include <iostream>
#include <unistd.h>

using Poco::NotificationQueue;
using Poco::Notification;
using Poco::AutoPtr;
using Poco::ThreadPool;
using Poco::Runnable;
using namespace std;

class WorkerNotification : public Notification {
public:
    WorkerNotification(int _data) : _data(_data) {}

    int data() const {
        return _data;
    }

    void dump() {
        cout << _data << endl;
    }

private:
    int _data;
};

class Worker : public Runnable {
public:
    Worker(NotificationQueue &_queue) : _queue(_queue) {}

    void run() {
        cout << "test" << endl;
        AutoPtr<Notification> pNf;
        while (true) {
            pNf = _queue.waitDequeueNotification();
            if (!pNf)
                break;
            WorkerNotification* pWorkerNf = dynamic_cast<WorkerNotification*>(pNf.get());
            if (pWorkerNf) {
                pWorkerNf->dump();
            }
        }
    }

private:
    NotificationQueue &_queue;
};

int main(int argc, char **argv) {
    NotificationQueue queue;

    Worker worker1(queue);
    Worker worker2(queue);

    ThreadPool::defaultPool().start(worker1);
//    sleep(1);
    ThreadPool::defaultPool().start(worker2);

    for (int i = 0; i < 100; i++) {
        queue.enqueueNotification(new WorkerNotification(i));
    }
    while (!queue.empty()) {
        Poco::Thread::sleep(100);
    }
    queue.wakeUpAll();
    ThreadPool::defaultPool().joinAll();
    return 0;
}