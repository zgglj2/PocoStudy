//
// Created by glj on 2017/6/10.
//

#include <Poco/Util/PropertyFileConfiguration.h>
#include <iostream>
#include <fstream>

using Poco::Util::PropertyFileConfiguration;
using Poco::AutoPtr;

int main(int argc, char **argv) {
    try {
        AutoPtr<PropertyFileConfiguration> pConf(new PropertyFileConfiguration("../../Configuration/test.properties"));
        std::string key1 = pConf->getString("key1");
        std::cout << "key1: " << key1 << std::endl;
        int value = pConf->getInt("key2");
        std::cout << "key2: " << value << std::endl;
        std::string longVal = pConf->getString("key3.longValue");
        std::cout << "key3.longValue: " << longVal << std::endl;

        pConf->setString("key4", "test");
        pConf->save("../../Configuration/test2.properties");
    } catch (Poco::Exception &exp) {
        std::cout << exp.displayText() << std::endl;
    }

}
