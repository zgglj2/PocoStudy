#include "Poco/InflatingStream.h"
#include "Poco/DeflatingStream.h"
#include "Poco/StreamCopier.h"
#include <iostream>
#include <sstream>
#include <fstream>
using Poco::InflatingInputStream;
using Poco::InflatingOutputStream;
using Poco::InflatingStreamBuf;
using Poco::DeflatingInputStream;
using Poco::DeflatingOutputStream;
using Poco::DeflatingStreamBuf;

using Poco::StreamCopier;

int main(int argc, char **argv) {
    std::ofstream ostr("test.gz", std::ios::binary);
    DeflatingOutputStream deflatingOut(ostr, DeflatingStreamBuf::STREAM_GZIP);
    deflatingOut << "Hello world!!!";

    deflatingOut.close();
    ostr.close();

    std::ifstream istr("test.gz", std::ios::binary);
    InflatingInputStream inflateingIn(istr, InflatingStreamBuf::STREAM_GZIP);
    StreamCopier::copyStream(inflateingIn, std::cout);

    std::cout << std::endl;

    std::ofstream ostr2("test2.gz", std::ios::binary);
    DeflatingOutputStream deflatingOut2(ostr2, DeflatingStreamBuf::STREAM_GZIP);
    deflatingOut2 << "Hello world!!!";

    deflatingOut2.close();
    ostr2.close();

    std::ifstream istr2("test2.gz", std::ios::binary);
    InflatingInputStream inflateingIn2(istr2, InflatingStreamBuf::STREAM_GZIP);
    StreamCopier::copyStream(inflateingIn2, std::cout);

    std::cout << std::endl;
    return 0;
}