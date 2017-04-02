#include <iostream>
#include "Poco/String.h"

using Poco::replace;
using namespace std;

int main(int argc, char **argv) {
    string s("aabbcc");

    string r(replace(s, "bb", "BB"));
    cout << r << endl;

    r = replace(s, "aa", "AAA");
    cout << r << endl;

    r = replace(s, "bbcc", "");
    cout << r << endl;


    return 0;
}