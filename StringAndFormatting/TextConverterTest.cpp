#include <iostream>
#include <string>
#include <Poco/TextConverter.h>
#include <Poco/Latin1Encoding.h>
#include <Poco/UTF8Encoding.h>
#include <Poco/StreamConverter.h>

using Poco::TextConverter;
using Poco::Latin1Encoding;
using Poco::UTF8Encoding;
using Poco::OutputStreamConverter;
using namespace std;

int main(int argc, char **argv) {
    string latin1String("This is Latin-1 encoded text.");
    string utf8String;

    Latin1Encoding latin1;
    UTF8Encoding utf8;

    TextConverter converter(latin1, utf8);
    converter.convert(latin1String, utf8String);

    cout << utf8String << endl;

    OutputStreamConverter converter2(cout, latin1, utf8);
    converter2 << latin1String << endl;
    return 0;
}