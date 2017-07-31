#include <Poco/Net/DatagramSocket.h>
#include <Poco/Net/SocketAddress.h>
#include <iostream>

using Poco::Net::DatagramSocket;
using Poco::Net::SocketAddress;
using namespace std;

int main(int argc, char **argv) {
    try {
//        SocketAddress sa(Poco::Net::IPAddress(), 514);
        SocketAddress sa("127.0.0.1", 514);
        DatagramSocket dgs;
        char buffer[1024];

        while (true) {
            SocketAddress sender;
            int n = dgs.receiveFrom(buffer, sizeof(buffer)-1, sender);
            buffer[n] = '\0';
            cout << "sender: " << sender.toString() << ", buffer: " << buffer << endl;
        }

    } catch (Poco::Exception &exp) {
        cout << exp.displayText() << endl;
    }

    return 0;
}