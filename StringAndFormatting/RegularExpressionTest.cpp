#include <iostream>
#include "Poco/RegularExpression.h"

using Poco::RegularExpression;
using namespace std;

int main(int argc, char **argv) {
    RegularExpression re1("[0-9]+");
    cout << re1.match("123") << endl;
    cout << re1.match("abc") << endl;
    cout << re1.match("abc123", 3) << endl;

    RegularExpression::Match pos;
    re1.match("123", 0, pos);
    cout << "offset:" << pos.offset << ", length:" << pos.length << endl;
    re1.match("ab12cd", 0, pos);
    cout << "offset:" << pos.offset << ", length:" << pos.length << endl;
    re1.match("abcd", 0, pos);
    cout << "offset:" << pos.offset << ", length:" << pos.length << endl;

    RegularExpression re2("([0-9]+) ([0-9]+)");
    RegularExpression::MatchVec posVec;
    re2.match("123 456", 0, posVec);
    RegularExpression::MatchVec::iterator begin;
    RegularExpression::MatchVec::iterator end;
    for (begin = posVec.begin(); begin != posVec.end(); begin++) {
        cout << "offset:" << begin->offset << ", length:" << begin->length << endl;
    }
    std::string s;
    int n = re1.extract("123", s);   // n == 1, s == "123"
    n = re1.extract("ab12de", 0, s); // n == 1, s == "12"
    n = re1.extract("abcd", 0, s);   // n == 0, s == ""
    std::vector<std::string> vec;
    re2.split("123 456", 0, vec);
// vec[0] == "123"
// vec[1] == "456"
    s = "123";
    re1.subst(s, "ABC");   // s == "ABC"
    s = "123 456";
    re2.subst(s, "$2 $1"); // s == "456 123"
    RegularExpression re3("ABC");
    RegularExpression re4("ABC", RegularExpression::RE_CASELESS);
    bool match;
    match = re3.match("abc", 0); // false
    match = re4.match("abc", 0); // true
    return 0;
}