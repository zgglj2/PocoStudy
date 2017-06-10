//
// Created by glj on 2017/6/10.
//

#include <Poco/Util/IniFileConfiguration.h>
#include <iostream>
#include <fstream>

using Poco::Util::IniFileConfiguration;
using Poco::AutoPtr;

int main(int argc, char **argv) {
    try {
        AutoPtr<IniFileConfiguration> pConf(new IniFileConfiguration("../../Configuration/test.ini"));

        std::string path = pConf->getString("MyApplication.somePath");
        std::cout << "MyApplication.somePath: " << path << std::endl;
        int value = pConf->getInt("MyApplication.someValue");
        std::cout << "MyApplication.someValue: " << value << std::endl;
        value = pConf->getInt("myapplication.SomeValue");
        std::cout << "myapplication.SomeValue: " << value << std::endl;
        value = pConf->getInt("myapplication.SomeOtherValue", 456 );
        std::cout << "myapplication.SomeOtherValue: " << value << std::endl;

    } catch (Poco::Exception &exp) {
        std::cout << exp.displayText() << std::endl;
    }

}