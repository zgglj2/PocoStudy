#include <iostream>
#include <vector>
#include "Poco/String.h"

using Poco::cat;
using namespace std;

int main(int argc, char **argv) {
    vector<string> colors;

    colors.push_back("red");
    colors.push_back("green");
    colors.push_back("blue");

    string s = cat(string(", "), colors.begin(), colors.end());

    cout << s <<endl;
    return 0;
}