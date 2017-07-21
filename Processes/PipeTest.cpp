#include <Poco/Process.h>
#include <Poco/PipeStream.h>
#include <Poco/StreamCopier.h>
#include <string>
#include <iostream>

using Poco::Process;
using Poco::ProcessHandle;
using Poco::PipeInputStream;
using Poco::StreamCopier;
using Poco::Pipe;
using namespace std;

int main(int argc, char **argv) {
    std::string cmd("ls");
    std::vector<std::string> args;
    args.push_back("PipeTest.exe");

    Pipe outPipe;
    ProcessHandle ph = Process::launch(cmd, args, NULL, &outPipe, NULL);
    ph.wait();

    PipeInputStream istr(outPipe);
    StreamCopier::copyStream(istr, cout);

    return 0;
}