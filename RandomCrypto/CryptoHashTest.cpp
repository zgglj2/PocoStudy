#include <iostream>
#include <Poco/DigestEngine.h>
#include <Poco/HMACEngine.h>
#include <Poco/SHA1Engine.h>
#include <Poco/DigestStream.h>
#include <Poco/MD5Engine.h>

using namespace std;
using Poco::HMACEngine;
using Poco::DigestEngine;
using Poco::SHA1Engine;

using Poco::DigestOutputStream;
using Poco::MD5Engine;


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

    MD5Engine md5;
    DigestOutputStream ostr(md5);

    ostr << "This is some text";
    ostr.flush();

    const DigestEngine::Digest& md5digist = md5.digest();
    string md5digistString(DigestEngine::digestToHex(md5digist));
    cout << md5digistString << endl;

    SHA1Engine sha1;
    DigestOutputStream ostr2(sha1);

    ostr2 << "This is some text";
    ostr2.flush();

    const DigestEngine::Digest& sha1digist = sha1.digest();
    string sha1digistString(DigestEngine::digestToHex(sha1digist));
    cout << sha1digistString << endl;
    return 0;
}