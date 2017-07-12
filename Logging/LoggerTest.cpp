#include <Poco/Logger.h>
#include <iostream>

using Poco::Logger;
using namespace std;

int main(int argc, char **argv) {
    Logger& logger = Logger::get("TestLogger");

    cout << "logger level:" << logger.getLevel() << endl;
    logger.information("This is an informational message");
    logger.error("This is an error message");
    return 0;
}