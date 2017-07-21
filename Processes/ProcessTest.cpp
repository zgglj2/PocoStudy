#include <Poco/Process.h>
#include <string>
#include <iostream>

using Poco::Process;
using Poco::ProcessHandle;
using namespace std;

int main(int argc, char **argv) {
    cout << "process id: " << Process::id() << endl;
    long userTime, kernelTime;
    Process::times(userTime, kernelTime);
    cout << "user time: " << userTime << ", kernel time: " << kernelTime << endl;

    std::string path = "ls";
    std::vector<std::string> args;
    args.push_back("-l");
    ProcessHandle ph = Process::launch(path, args);
    ph.wait();


    return 0;
}