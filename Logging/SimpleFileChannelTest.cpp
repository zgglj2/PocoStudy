#include <Poco/Logger.h>
#include <Poco/SimpleFileChannel.h>
#include <Poco/AutoPtr.h>
#include <iostream>

using Poco::Logger;
using Poco::SimpleFileChannel;
using Poco::AutoPtr;
using namespace std;

int main(int argc, char **argv) {
    AutoPtr<SimpleFileChannel> pChannel(new SimpleFileChannel);
    pChannel->setProperty("path", "../../Logging/SimpleFileChannel.log");
    pChannel->setProperty("rotation", "2 K");

    Logger::root().setChannel(pChannel);
    Logger& logger = Logger::get("TestLogger");
    for (int i = 0; i < 1000; ++i)
        logger.information("Testing SimpleFileChannel");

    return 0;
}