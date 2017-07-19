#include <Poco/Thread.h>
#include <Poco/Timer.h>
#include <iostream>

using Poco::Thread;
using Poco::Timer;
using Poco::TimerCallback;
using namespace std;

class TimerWorker {
public:
    void onTimer(Poco::Timer& timer) {
        cout << Poco::Thread::currentTid() << " timer thread!!" << endl;
    }

};

int main(int argc, char **argv) {
    cout << Poco::Thread::currentTid() << " main thread!!" << endl;
    try {
        TimerWorker tw;
        Timer timer(250, 500);
        timer.start(TimerCallback<TimerWorker>(tw, &TimerWorker::onTimer));
        Thread::sleep(5000);
        timer.stop();
    } catch (Poco::Exception &exp) {
        cout << exp.displayText() << endl;
    }


    return 0;
}