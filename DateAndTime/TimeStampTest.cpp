#include <iostream>
#include <Poco/Timestamp.h>

using namespace std;
using Poco::Timestamp;

int main(int argc, char **argv) {
    Timestamp now;

    time_t t1 = now.epochTime();
    cout << t1 << endl;

    Timestamp ts1(Timestamp::fromEpochTime(t1));

    for(int i=0; i<100000; i++);

    Timestamp start(now);

    now.update();

    cout << now - start << endl;
    return 0;
}