#include <Poco/URIStreamOpener.h>
#include <Poco/Net/HTTPStreamFactory.h>
#include <Poco/Net/FTPStreamFactory.h>
#include <Poco/StreamCopier.h>
#include <Poco/URI.h>
#include <iostream>

using Poco::URIStreamOpener;
using Poco::Net::HTTPStreamFactory;
using Poco::Net::FTPStreamFactory;
using Poco::SharedPtr;
using Poco::StreamCopier;
using Poco::URI;
using namespace std;

int main(int argc, char **argv) {
    try {
        HTTPStreamFactory::registerFactory();
        FTPStreamFactory::registerFactory();
        URIStreamOpener& opener = URIStreamOpener::defaultOpener();

        SharedPtr<std::istream> istr1(
                opener.open("http://www.163.com/")
        );
//        SharedPtr<std::istream> istr2(
//                opener.open("ftp://ftp.appinf.com/pub/poco/poco-1.2.5.tar.gz")
//        );
        SharedPtr<std::istream> istr3(
                opener.open("file:///usr/include/stdio.h")
        );
        StreamCopier::copyStream(*istr3.get(), std::cout);
    }catch (Poco::Exception& exp) {
        cout << exp.displayText() << endl;
    }

    return 0;
}