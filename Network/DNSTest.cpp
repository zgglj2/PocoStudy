#include <Poco/Net/DNS.h>
#include <iostream>

using Poco::Net::DNS;
using Poco::Net::IPAddress;
using Poco::Net::HostEntry;
using namespace std;

int main(int argc, char **argv) {
    try {
        const HostEntry& entry = DNS::hostByName("www.baidu.com");
        cout << "Canonical Name: " << entry.name() << endl;

        const HostEntry::AliasList& aliasList = entry.aliases();
        HostEntry::AliasList::const_iterator it = aliasList.begin();
        for (; it != aliasList.end() ; ++it) {
            cout << "  Alias: " << *it << endl;
        }

        const HostEntry::AddressList& addrs = entry.addresses();
        HostEntry::AddressList::const_iterator it2 = addrs.begin();
        for (; it2 != addrs.end(); ++it2)
            std::cout << "Address: " << it2->toString() << std::endl;
    } catch (Poco::Exception &exp) {
        cout << exp.displayText() << endl;
    }

    return 0;
}