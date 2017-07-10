#include "Poco/CountingStream.h"
#include "Poco/StreamCopier.h"
#include "Poco/Base64Encoder.h"
#include <iostream>
#include <sstream>
using Poco::CountingInputStream;
using Poco::CountingOutputStream;
using Poco::CountingStreamBuf;
using Poco::StreamCopier;
using Poco::Base64Encoder;

int main(int argc, char **argv) {
    CountingOutputStream cntOutStr(std::cout);
    Base64Encoder base64Enc(cntOutStr);
    base64Enc << "Hello world!!!" << std::endl;
    std::cout << std::endl;
    std::cout << cntOutStr.pos() << std::endl;

    std::stringstream sstr;
    sstr << "SGVsbG8gd29ybGQhISE=";
    CountingInputStream cntInStr(sstr);
    while (cntInStr.good()) {
        cntInStr.get();
    }
    std::cout << cntInStr.chars() << std::endl;

    return 0;
}