#include <Poco/UniqueExpireCache.h>
#include <Poco/ExpirationDecorator.h>
#include <Poco/Thread.h>
#include <string>
#include <iostream>

using Poco::UniqueExpireCache;
using Poco::ExpirationDecorator;
using Poco::Thread;
using namespace std;

int main(int argc, char **argv) {
    UniqueExpireCache<int, ExpirationDecorator<string>> myCache;

    myCache.add(1, ExpirationDecorator<string>("test1", 500));
    myCache.add(3, ExpirationDecorator<string>("test2", 1500));

    cout << "Cache size: " << myCache.size() << endl;
    Thread::sleep(1000);
    cout << "Cache size: " << myCache.size() << endl;
    Thread::sleep(1000);
    cout << "Cache size: " << myCache.size() << endl;
    return 0;
}