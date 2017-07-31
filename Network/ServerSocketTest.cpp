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
    ServerSocket srv(8765);
    StreamSocket ss;
    while (true) {
        try {
            ss = srv.acceptConnection();
            SocketStream str(ss);
            str << "HTTP/1.0 200 OK\r\n"
                    "Content-Type: text/html\r\n"
                    "\r\n"
                    "<html><head><title>My 1st Web Server</title></head>"
                    "<body><h1>Hello, world!</h1></body></html>"
                << std::flush;

        } catch (Poco::Exception &exp) {
            cout << exp.displayText() << endl;
        }
    }

    return 0;
}