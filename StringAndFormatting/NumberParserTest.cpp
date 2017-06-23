#include <iostream>
#include <vector>
#include <Poco/Exception.h>
#include "Poco/NumberParser.h"

using Poco::NumberParser;
using namespace std;

int main(int argc, char **argv) {
    try {
        unsigned int t = NumberParser::parse("123321");
        cout << t << endl;
        t = NumberParser::parseHex("0xFF");
        cout << t << endl;

        bool flag = NumberParser::tryParseHex("0xFFFF", t);
        cout << flag << ", " << t  << endl;

        float f = NumberParser::parseFloat("0.1223");
        cout << f << endl;

        f = NumberParser::parseFloat("0.1223gg");
        cout << f << endl;
    }catch (Poco::Exception& exp){
        cout << exp.displayText() << endl;
    }
    return 0;
}