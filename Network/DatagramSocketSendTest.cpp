#include <Poco/Net/DatagramSocket.h>
#include <Poco/Net/SocketAddress.h>
#include <Poco/DateTimeFormatter.h>
#include <iostream>

using Poco::Net::DatagramSocket;
using Poco::Net::SocketAddress;
using namespace std;

int main(int argc, char **argv) {
    try {
        SocketAddress sa("127.0.0.1", 514);
        DatagramSocket dgs;
        dgs.connect(sa);

        Poco::Timestamp now;
        std::string msg = Poco::DateTimeFormatter::format(now, "<14>%w %f %H:%M:%S Hello, world!");

        dgs.sendBytes(msg.c_str(), msg.size());

    } catch (Poco::Exception &exp) {
        cout << exp.displayText() << endl;
    }

    return 0;
}