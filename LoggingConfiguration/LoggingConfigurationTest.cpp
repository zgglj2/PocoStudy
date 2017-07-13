#include "Poco/Logger.h"
#include <Poco/Util/PropertyFileConfiguration.h>
#include <Poco/Util/LoggingConfigurator.h>
#include <unistd.h>
using Poco::Logger;

int main(int argc, char **argv) {
    Poco::AutoPtr<Poco::Util::PropertyFileConfiguration> pConf = new Poco::Util::PropertyFileConfiguration(
            "../../LoggingConfiguration/LoggingConfigurationTest.properties");
//    Poco::AutoPtr<Poco::Util::PropertyFileConfiguration> pConf = new Poco::Util::PropertyFileConfiguration(
//            "../../Applications/ApplicationTestLog.properties");
    Poco::Util::LoggingConfigurator log_configurator;
    log_configurator.configure(pConf);

    Logger &logger = Logger::get("Test");
    logger.information("This is an informational message");
    logger.warning("This is a warning message");
    sleep(5);
    return 0;
}