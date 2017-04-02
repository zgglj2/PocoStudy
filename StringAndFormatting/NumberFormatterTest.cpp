#include <iostream>
#include <vector>
#include "Poco/NumberFormatter.h"

using Poco::NumberFormatter;
using namespace std;

int main(int argc, char **argv) {
    string s;
    s = NumberFormatter::format(123);
    cout << s << endl;
    s = NumberFormatter::format(123, 5);    // "  123"
    cout << s << endl;
    s = NumberFormatter::format(-123, 5);   // " -123"
    cout << s << endl;
    s = NumberFormatter::format(12345, 3);  // "12345"
    s = NumberFormatter::format0(123, 5);   // "00123"
    cout << s << endl;
    s = NumberFormatter::formatHex(123);    // "7B"
    cout << s << endl;
    s = NumberFormatter::formatHex(123, 4); // "007B"
    cout << s << endl;
    s = NumberFormatter::format(1.5);       // "1.5"
    cout << s << endl;
    s = NumberFormatter::format(1.5, 2);    // "1.50"
    cout << s << endl;
    s = NumberFormatter::format(1.5, 5, 2); // " 1.50"
    cout << s << endl;
    s = NumberFormatter::format(&s);        // "00235F7D"
    cout << s << endl;
    return 0;
}