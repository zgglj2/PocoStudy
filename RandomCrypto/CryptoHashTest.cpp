#include <iostream>
#include <Poco/HMACEngine.h>
#include <Poco/DigestEngine.h>
#include <Poco/SHA1Engine.h>

using namespace std;
using Poco::HMACEngine;
using Poco::DigestEngine;
using Poco::SHA1Engine;

int main(int argc, char **argv) {
    string message1("This is a top-secret message.");
    string message2("Don't tell anyone!");
    string passphrase("s3cr3t");

    HMACEngine<SHA1Engine> hmac(passphrase);
    hmac.update(message1);
    hmac.update(message2);

    const DigestEngine::Digest& digist = hmac.digest();
    string digistString(DigestEngine::digestToHex(digist));

    cout << digistString << endl;

    return 0;
}