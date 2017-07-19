#include <Poco/Thread.h>
#include <Poco/Activity.h>
#include <iostream>

using Poco::Thread;
using Poco::Activity;
using namespace std;

class ActivityExample {
public:
    ActivityExample() : _activity(this, &ActivityExample::runActivity) {}

    void start() {
        _activity.start();
    }

    void stop() {
        _activity.stop();
        _activity.wait();
    }

protected:
    void runActivity() {
        while (!_activity.isStopped()) {
            std::cout << "Activity running." << std::endl;
            Thread::sleep(200);
        }
    }

private:
    Activity<ActivityExample> _activity;
};

int main(int argc, char **argv) {
    ActivityExample example;
    example.start();
    Thread::sleep(2000);
    example.stop();

    return 0;
}