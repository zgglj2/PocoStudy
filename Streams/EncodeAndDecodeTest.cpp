#include "Poco/Base64Encoder.h"
#include "Poco/Base64Decoder.h"
#include "Poco/HexBinaryEncoder.h"
#include "Poco/HexBinaryDecoder.h"
#include "Poco/StreamCopier.h"
#include <iostream>
#include <sstream>
using Poco::Base64Encoder;
using Poco::Base64Decoder;
using Poco::HexBinaryEncoder;
using Poco::HexBinaryDecoder;
using Poco::StreamCopier;

int main(int argc, char **argv) {
    Base64Encoder base64Enc(std::cout);
    base64Enc << "Hello world!!!" << std::endl;

    std::cout << std::endl;

    std::stringstream sstr;
    sstr << "SGVsbG8gd29ybGQhISE=";
    Base64Decoder base64Dec(sstr);
    StreamCopier::copyStream(base64Dec, std::cout);


    std::cout << std::endl;

    HexBinaryEncoder hexBinEnc(std::cout);
    hexBinEnc << "Hello world!!!" << std::endl;

    std::cout << std::endl;

    sstr << "48656c6c6f20776f726c642121210a";
    HexBinaryDecoder hexBinDec(sstr);
    StreamCopier::copyStream(hexBinDec, std::cout);
    return 0;
}