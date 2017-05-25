//
// Created by outer-glj on 2017/5/25.
//

#include <Poco/ClassLoader.h>
#include <Poco/Manifest.h>
#include <iostream>
#include "AbstractPlugin.h"

typedef Poco::ClassLoader<AbstractPlugin> PluginLoader;
typedef Poco::Manifest<AbstractPlugin> PluginManefest;

int main(int argc, char **argv) {
    PluginLoader loader;
    std::string path;
#if POCO_OS == POCO_OS_WINDOWS_NT
    std::cout << "POCO_OS_WINDOWS_NT" <<std::endl;
#elif POCO_OS == POCO_OS_LINUX
    std::cout << "POCO_OS_LINUX" <<std::endl;
#elif POCO_OS == POCO_OS_CYGWIN
    std::cout << "POCO_OS_CYGWIN" << std::endl;
    path = "cyg";
#endif
    path.append("PluginLibrary");
    path.append(Poco::SharedLibrary::suffix());

    loader.loadLibrary(path);

    PluginLoader::Iterator it(loader.begin());
    PluginLoader::Iterator end(loader.end());

    for (; it != end; it++) {
        std::cout << "Lib path:" << it->first << std::endl;
        PluginManefest::Iterator itMan(it->second->begin());
        PluginManefest::Iterator endMan(it->second->end());
        for (; itMan != endMan; itMan++) {
            std::cout << "  Class name:" << itMan->name() << std::endl;
        }
    }

    AbstractPlugin* pluginA = loader.create("PluginA");
    AbstractPlugin* pluginB = loader.create("PluginB");
    AbstractPlugin& pluginC = loader.instance("PluginC");
    std::cout << "pluginA name:" << pluginA->name() << std::endl;
    std::cout << "pluginB name:" << pluginB->name() << std::endl;
    std::cout << "pluginC name:" << pluginC.name() << std::endl;

    loader.classFor("PluginA").autoDelete(pluginA);
    delete pluginB;

    loader.unloadLibrary(path);
    return 0;
}