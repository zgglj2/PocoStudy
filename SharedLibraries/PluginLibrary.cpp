//
// Created by outer-glj on 2017/5/25.
//

#include <Poco/ClassLibrary.h>
#include "AbstractPlugin.h"
#include <iostream>

class PluginA : public AbstractPlugin {
public:
    PluginA() {
        std::cout << "PluginA()" << std::endl;
    }

    ~PluginA() {
        std::cout << "~PluginA()" << std::endl;
    }

    std::string name() const {
        return "PluginA";
    }

};

class PluginB : public AbstractPlugin {
public:
    PluginB() {
        std::cout << "PluginB()" << std::endl;
    }

    ~PluginB() {
        std::cout << "~PluginB()" << std::endl;
    }

    std::string name() const {
        return "PluginB";
    }

};

class PluginC : public AbstractPlugin {
public:
    PluginC() {
        std::cout << "PluginC()" << std::endl;
    }

    ~PluginC() {
        std::cout << "~PluginC()" << std::endl;
    }

    std::string name() const {
        return "PluginC";
    }
};


POCO_BEGIN_MANIFEST(AbstractPlugin)
        POCO_EXPORT_CLASS(PluginA)
        POCO_EXPORT_CLASS(PluginB)
        POCO_EXPORT_SINGLETON(PluginC)
POCO_END_MANIFEST

void pocoInitializeLibrary() {
    std::cout << "PluginLibrary initializing" << std::endl;
}

void pocoUninitializeLibrary() {
    std::cout << "PluginLibrary uninitializing" << std::endl;
}