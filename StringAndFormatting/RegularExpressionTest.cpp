#include <iostream>
#include "Poco/RegularExpression.h"

using Poco::RegularExpression;
using namespace std;

int main(int argc, char **argv) {
    RegularExpression re("[0-9]+");
    cout << re.match("123") << endl;

    return 0;
}