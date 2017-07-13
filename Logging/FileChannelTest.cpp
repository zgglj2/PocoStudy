#include <Poco/Logger.h>
#include <Poco/FileChannel.h>
#include <Poco/AutoPtr.h>
#include <iostream>

using Poco::Logger;
using Poco::FileChannel;
using Poco::AutoPtr;
using namespace std;

int main(int argc, char **argv) {
    AutoPtr<FileChannel> pChannel(new FileChannel);
    pChannel->setProperty("path", "../../Logging/FileChannel.log");
    pChannel->setProperty("rotation", "2 K");
    pChannel->setProperty("archive", "timestamp");
    pChannel->setProperty("compress", "true");
    pChannel->setProperty("purgeCount", "3");


    Logger::root().setChannel(pChannel);
    Logger& logger = Logger::get("TestLogger");
    for (int i = 0; i < 100; ++i)
        logger.information("Testing FileChannel");

    return 0;
}