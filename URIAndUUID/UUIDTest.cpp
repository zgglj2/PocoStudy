#include <Poco/UUID.h>
#include <Poco/UUIDGenerator.h>
#include <iostream>

using Poco::UUID;
using Poco::UUIDGenerator;
using namespace std;

int main(int argc, char **argv) {
    UUIDGenerator& generator = UUIDGenerator::defaultGenerator();

    UUID uuid1(generator.create());
    UUID uuid2(generator.createRandom());
    UUID uuid3(generator.createFromName(UUID::uri(), "http://appinf.com"));

    cout << "uuid1: " << uuid1.toString() << endl;
    cout << "uuid2: " << uuid2.toString() << endl;
    cout << "uuid3: " << uuid3.toString() << endl;

    return 0;
}