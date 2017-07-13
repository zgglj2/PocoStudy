#include "Poco/Logger.h"
#include "Poco/AsyncChannel.h"
#include "Poco/ConsoleChannel.h"
#include "Poco/AutoPtr.h"
#include <iostream>

using Poco::Logger;
using Poco::AsyncChannel;
using Poco::ConsoleChannel;
using Poco::AutoPtr;
using namespace std;

int main(int argc, char **argv) {
    AutoPtr<ConsoleChannel> pCons(new ConsoleChannel);
    AutoPtr<AsyncChannel> pAsync(new AsyncChannel(pCons));

    Logger::root().setChannel(pAsync);
    Logger& logger = Logger::get("TestLogger");
    for (int i = 0; i < 10; ++i)
        logger.information("Testing AsyncChannel");
//    Poco::Thread::sleep(2000);
    return 0;
}