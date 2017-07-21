#include <Poco/URI.h>
#include <iostream>

using Poco::URI;
using namespace std;

int main(int argc, char **argv) {
    URI uri1("http://www.appinf.com:88/sample?example-query#frag");

    cout << "Scheme: " << uri1.getScheme() << endl;
    cout << "auth: " << uri1.getAuthority() << endl;
    cout << "host: " << uri1.getHost() << endl;
    cout << "port: " << uri1.getPort() << endl;
    cout << "path: " << uri1.getPath() << endl;
    cout << "query: " << uri1.getQuery() << endl;
    cout << "fragment: " << uri1.getFragment() << endl;
    cout << "pathEtc: " << uri1.getPathEtc() << endl;

    Poco::URI uri2;
    uri2.setScheme("https");
    uri2.setAuthority("www.appinf.com");
    uri2.setPath("/another sample");
    cout << "uri2: " << uri2.toString() << endl;

    URI uri3("http://www.appinf.com");
    uri3.resolve("/poco/info/index.html");
    cout << "uri3: " << uri3.toString() << endl; // "http://www.appinf.com/poco/info/index.html"
    uri3.resolve("support.html");
    cout << "uri3: " << uri3.toString() << endl; // "http://www.appinf.com/poco/info/support.html"
    uri3.resolve("http://sourceforge.net/projects/poco");
    cout << "uri3: " << uri3.toString() << endl; // "http://sourceforge.net/projects/poco"
    return 0;
}