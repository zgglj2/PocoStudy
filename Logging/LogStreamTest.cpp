#include "Poco/LogStream.h"
#include "Poco/AutoPtr.h"
#include <Poco/ConsoleChannel.h>

using Poco::Logger;
using Poco::LogStream;
using Poco::ConsoleChannel;
using Poco::AutoPtr;

int main(int argc, char **argv) {
    AutoPtr<ConsoleChannel> pCons(new ConsoleChannel);
    Logger::root().setChannel(pCons);

    Logger &logger = Logger::get("TestLogger");
    LogStream lstr(logger);
    lstr << "This is a test" << std::endl;
    lstr.error() << "This is a error test" << std::endl;
    return 0;
}