#include <Poco/Net/SocketAddress.h>
#include <Poco/Net/StreamSocket.h>
#include <Poco/Net/SocketStream.h>
#include <Poco/Net/ServerSocket.h>
#include <Poco/StreamCopier.h>
#include <iostream>

using Poco::Net::StreamSocket;
using Poco::Net::SocketAddress;
using Poco::Net::SocketStream;
using Poco::Net::ServerSocket;
using Poco::StreamCopier;
using namespace std;

int main(int argc, char **argv) {
    try {
        SocketAddress sa("www.appinf.com", 80);
        StreamSocket socket(sa);
        SocketStream str(socket);
        str << "GET / HTTP/1.1\r\n"
                "Host: www.appinf.com\r\n"
                "\r\n";
        str.flush();
        StreamCopier::copyStream(str, cout);
    } catch (Poco::Exception &exp) {
        cout << exp.displayText() << endl;
    }

    return 0;
}