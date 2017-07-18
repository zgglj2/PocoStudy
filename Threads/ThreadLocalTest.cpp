#include <Poco/Thread.h>
#include <Poco/Runnable.h>
#include <Poco/ThreadLocal.h>
#include <iostream>
#include <Poco/NumberFormatter.h>

using Poco::Thread;
using Poco::Runnable;
using Poco::ThreadLocal;
using Poco::NumberFormatter;
using namespace std;

class Counter : public Runnable {
public:
    void run() override {
        static ThreadLocal<int> tls;
        static ThreadLocal<std::string> tls_str;
        for (*tls = 0; *tls < 10; ++(*tls)) {
            cout << *tls << endl;
            cout << *tls_str << endl;
            *tls_str = "str" + NumberFormatter::format(*tls);
        }

    }

};

int main(int argc, char **argv) {
    Counter counter;
    Poco::Thread t1;
    Poco::Thread t2;
    t1.start(counter);
    t2.start(counter);
    t1.join();
    t2.join();

    return 0;
}