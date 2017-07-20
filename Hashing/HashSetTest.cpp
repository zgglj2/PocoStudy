#include <Poco/HashSet.h>
#include <string>
#include <iostream>

using Poco::HashSet;
using Poco::Hash;
using namespace std;

int main(int argc, char **argv) {
    HashSet<int, Hash<int>> lht;

    for (int i = 0; i < 100; ++i) {
        std::pair<HashSet<int, Hash<int>>::Iterator, bool> ret = lht.insert(i);
        cout << "*ret.first: " << *ret.first << ", ret.second: " << ret.second << endl;
    }
    cout << "hash set size: " << lht.size() << endl;

    HashSet<int, Hash<int>>::Iterator it = lht.find(25);
    if (it != lht.end()) {
        cout << "elem 25: " << *it << endl;
        lht.erase(it);
    }
    cout << "hash set size: " << lht.size() << endl;

    return 0;
}