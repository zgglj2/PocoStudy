#include <Poco/Net/MulticastSocket.h>
#include <Poco/Net/SocketAddress.h>
#include <Poco/DateTimeFormatter.h>
#include <iostream>

using Poco::Net::MulticastSocket;
using Poco::Net::SocketAddress;
using namespace std;

int main(int argc, char **argv) {
    try {
        Poco::Net::SocketAddress address("239.255.255.250", 1900);
        Poco::Net::MulticastSocket socket(
                Poco::Net::SocketAddress(
                        Poco::Net::IPAddress(), address.port()
                )
        );
        // to receive any data you must join
        socket.joinGroup(address.host());
        Poco::Net::SocketAddress sender;
        char buffer[512];
        int n = socket.receiveFrom(buffer, sizeof(buffer), sender);
        socket.sendTo(buffer, n, sender);

    } catch (Poco::Exception &exp) {
        cout << exp.displayText() << endl;
    }

    return 0;
}