#include <iostream>
#include <Poco/Random.h>
#include <Poco/RandomStream.h>

using namespace std;
using Poco::Random;
using Poco::RandomInputStream;

int main(int argc, char **argv) {
    Random rnd;
    rnd.seed();

    std::cout << "Random integer: " << rnd.next() << std::endl;
    std::cout << "Random digit: " << rnd.next(10) << std::endl;
    std::cout << "Random char: " << rnd.nextChar() << std::endl;
    std::cout << "Random bool: " << rnd.nextBool() << std::endl;
    std::cout << "Random double: " << rnd.nextDouble() << std::endl;

    RandomInputStream ris;
    string rs;

    ris >> rs;
    cout << "Random input stream(len:" << rs.size() << "):" << rs << endl;
    return 0;
}