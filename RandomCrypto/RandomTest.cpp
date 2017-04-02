#include <iostream>
#include <Poco/Random.h>
#include <Poco/RandomStream.h>

using namespace std;
using Poco::Random;
using Poco::RandomInputStream;

int main(int argc, char **argv) {
    Random rnd;
    rnd.seed();

    return 0;
}