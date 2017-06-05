#include "Poco/Util/XMLConfiguration.h"
#include "Poco/AutoPtr.h"
#include <iostream>
#include <fstream>

using Poco::Util::XMLConfiguration;
using Poco::AutoPtr;

int main(int argc, char **argv) {
    try {
        std::fstream fs("../../Configuration/test.xml");
//        std::fstream fs("test.xml");
        std::cout << fs.is_open() << std::endl;
        AutoPtr<XMLConfiguration> pConf(new XMLConfiguration(fs));
//        AutoPtr<XMLConfiguration> pConf(new XMLConfiguration("test.xml"));

        std::string prop1 = pConf->getString("prop1");
        std::cout << "prop1: " << prop1 << std::endl;
        int prop2 = pConf->getInt("prop2");
        std::cout << "prop2: " << prop2 << std::endl;
        std::string prop3 = pConf->getString("prop3");
        std::cout << "prop3: " << prop3 << std::endl;
        std::string prop4 = pConf->getString("prop3.prop4");
        std::cout << "prop4: " << prop4 << std::endl;
        prop4 = pConf->getString("prop3.prop4[0][@attr]");
        std::cout << "prop4[0][@attr]: " << prop4 << std::endl;
        prop4 = pConf->getString("prop3.prop4[1][@attr]");
        std::cout << "prop4[1][@attr]: " << prop4 << std::endl;

        pConf->save("../../Configuration/test2.xml");
    } catch (Poco::Exception &exp) {
        std::cout << exp.displayText() << std::endl;
    }

    return 0;
}