#include <Poco/ThreadPool.h>
#include <iostream>
#include <unistd.h>
#include <unistd.h>
#include <sys/file.h>
#include <sys/types.h>
#include <sys/stat.h>


using Poco::AutoPtr;
using Poco::ThreadPool;
using Poco::Runnable;
using namespace std;

int counter = 0;

class Worker : public Runnable {
public:
    void run() {
        int fd = open("/tmp/flock", O_CREAT | O_RDWR);
        for (int i = 0; i < 100000; i++) {
            if ((flock(fd, LOCK_EX)) < 0) {
                std::cout << "Log::The log have been locked" << std::endl;
                close(fd);
                return;
            }
//            cout << "thread id:" << pthread_self() << ", in file lock" << endl;
//            Poco::Thread::sleep(10000);
            counter++;
            if ((flock(fd, LOCK_UN)) < 0) {
                std::cout << "Log::unlock the logfile error" << std::endl;
                close(fd);
                return;
            }
        }

        close(fd);


    }

};

int main(int argc, char **argv) {

    Worker worker1;
    Worker worker2;

    ThreadPool::defaultPool().start(worker1);
    ThreadPool::defaultPool().start(worker2);


    Poco::Thread::sleep(100);
    ThreadPool::defaultPool().joinAll();
    std::cout << "counter:" << counter << std::endl;
    return 0;
}