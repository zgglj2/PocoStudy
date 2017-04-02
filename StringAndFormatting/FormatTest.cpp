#include <iostream>
#include <vector>
#include "Poco/Format.h"

using Poco::format;
using namespace std;

int main(int argc, char **argv) {
    int n = 42;
    std::string s;
    format(s, "The answer to life, the universe and everything is %d", n);
    cout << s << endl;
    s = format("%d + %d = %d", 2, 2, 4); // "2 + 2 = 4"
    cout << s << endl;
    s = format("%4d", 42);               // "  42"
    cout << s << endl;
    s = format("%-4d", 42);              // "42  "
    cout << s << endl;
    format(s, "%d", std::string("foo")); // "[ERRFMT]"
    cout << s << endl;
    return 0;
}