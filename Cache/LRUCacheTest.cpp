#include <Poco/LRUCache.h>
#include <string>
#include <iostream>

using Poco::LRUCache;
using namespace std;

int main(int argc, char **argv) {
    LRUCache<int, string> myCache(3);

    myCache.add(1, "Lousy");
    Poco::SharedPtr<string> ptrElem = myCache.get(1);
    myCache.add(2, "Morning");
    myCache.add(3, "USA");
    myCache.add(4, "Good");

    cout << "Cache size: " << myCache.size() << endl;

    ptrElem = myCache.get(2);
    cout << "Elem 2: " << *ptrElem << endl;
    myCache.add(2, "Evening");
    cout << "Elem 2: " << *ptrElem << endl;

    ptrElem = myCache.get(2);
    cout << "Elem 2: " << *ptrElem << endl;

    return 0;
}