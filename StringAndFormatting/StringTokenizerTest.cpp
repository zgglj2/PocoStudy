#include <iostream>
#include <vector>
#include <Poco/StringTokenizer.h>
#include <Poco/String.h>

using Poco::StringTokenizer;
using Poco::cat;
using namespace std;

int main(int argc, char **argv) {
    StringTokenizer::Iterator begin;
    StringTokenizer::Iterator end;

    StringTokenizer t1("red, green, blue", ",");
    for (begin = t1.begin(); begin != t1.end(); begin++)
        cout << "\"" << *begin << "\", ";
    cout << endl;

    StringTokenizer t2("red,green,,blue", ",");
    for (begin = t2.begin(); begin != t2.end(); begin++)
        cout << "\"" << *begin << "\", ";
    cout << endl;

    StringTokenizer t3("red; green, blue", ",;", StringTokenizer::TOK_TRIM);
    for (begin = t3.begin(); begin != t3.end(); begin++)
        cout << "\"" << *begin << "\", ";
    cout << endl;

    StringTokenizer t4("red; green,, blue", ",;", StringTokenizer::TOK_TRIM | StringTokenizer::TOK_IGNORE_EMPTY);
    for (begin = t4.begin(); begin != t4.end(); begin++)
        cout << "\"" << *begin << "\", ";
    cout << endl;

    std::string s(cat(std::string("; "), t4.begin(), t4.end()));
    cout << s << endl;
    return 0;
}