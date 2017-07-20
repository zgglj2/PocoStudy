#include <Poco/HashMap.h>
#include <string>
#include <iostream>

using Poco::HashMap;
using namespace std;

int main(int argc, char **argv) {
    HashMap<int, int> hashMap;

    for (int i = 0; i < 100; ++i) {
        std::pair<HashMap<int, int>::Iterator, bool> ret = hashMap.insert(HashMap<int, int>::ValueType(i, i*2));
        cout << "ret.first<" << ret.first->first << "," << ret.first->second << ">, ret.second: " << ret.second << endl;
    }
    cout << "hash Map size: " << hashMap.size() << endl;

    HashMap<int, int>::Iterator it = hashMap.find(25);
    if (it != hashMap.end()) {
        cout << "elem 25: " << it->first << endl;
        hashMap.erase(it);
    }
    cout << "hash Map size: " << hashMap.size() << endl;

    return 0;
}