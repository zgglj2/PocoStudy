#include <Poco/Task.h>
#include <Poco/TaskManager.h>
#include <Poco/TaskNotification.h>
#include <Poco/Observer.h>
#include <iostream>

using Poco::Task;
using Poco::TaskManager;
using Poco::TaskProgressNotification;
using Poco::TaskFinishedNotification;
using Poco::Observer;
using namespace std;

class SampleTask : public Task {
public:
    SampleTask(const string &name) : Task(name) {}

    void runTask() override {
        for (int i = 0; i < 100; ++i) {
            setProgress((float) i / 100);
            if (sleep(100))
                break;
        }
    }
};

class ProgressHandler {
public:
    void onProgress(TaskProgressNotification* pNf) {
        cout << pNf->task()->name() << " progress: " << pNf->progress() << endl;
        pNf->release();
    }

    void onFinished(TaskFinishedNotification* pNf) {
        cout << pNf->task()->name() << " finished!!" << endl;
        pNf->release();
    }
};

int main(int argc, char **argv) {
    TaskManager tm;
    ProgressHandler ph;
    tm.addObserver(Observer<ProgressHandler, TaskProgressNotification>(ph, &ProgressHandler::onProgress));
    tm.addObserver(Observer<ProgressHandler, TaskFinishedNotification>(ph, &ProgressHandler::onFinished));

    tm.start(new SampleTask("Sample task1"));
    tm.start(new SampleTask("Sample task2"));

    tm.joinAll();
    return 0;
}