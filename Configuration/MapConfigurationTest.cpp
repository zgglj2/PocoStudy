//
// Created by glj on 2017/6/10.
//

#include <Poco/Util/MapConfiguration.h>
#include <iostream>
#include <fstream>

using Poco::Util::MapConfiguration;
using Poco::AutoPtr;

int main(int argc, char **argv) {
    try {
        AutoPtr<MapConfiguration> pConf(new MapConfiguration());

        pConf->setString("foo", "bar");
        std::cout << "pConf->getString(\"foo\"): " << pConf->getString("foo") << std::endl;
    } catch (Poco::Exception &exp) {
        std::cout << exp.displayText() << std::endl;
    }

}
