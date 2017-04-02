#include <iostream>
#include "Poco/Environment.h"

using namespace std;
using Poco::Environment;

int main(int argc, char **argv) {
    cout << "OS Name:" << Environment::osName() <<endl;
    cout << "OS Version:" << Environment::osVersion() <<endl;
    cout << "OS Arch:" << Environment::osArchitecture() <<endl;
    cout << "Node Name:" << Environment::nodeName() <<endl;
    cout << "Node ID:" << Environment::nodeId() <<endl;

    if (Environment::has("HOME")) {
        cout << "Home:" << Environment::get("HOME") << endl;
    }
    Environment::set("POCO", "foo");
    cout << "POCO:" << Environment::get("POCO") << endl;
    return 0;
}