#include <Poco/BasicEvent.h>
#include <Poco/Delegate.h>
#include <iostream>

using Poco::BasicEvent;
using Poco::Delegate;

class Source {
public:
    BasicEvent<int> theEvent;

    void fireEvent(int n) {
        theEvent(this, n);
        // theEvent.notify(this, n); // alternative syntax
    }
};

class Target {
public:
   void onEvent(const void* pSender, int& arg) {
       std::cout << "Target onEvent:" << arg << std::endl;
   }
};

class OtherTarget {
public:
    void onEvent(const void* pSender, int& arg) {
        std::cout << "OtherTarget onEvent:" << arg << std::endl;
    }
};

int main(int argc, char **argv) {
    Source source;
    Target target;
    OtherTarget otherTarget;

    source.theEvent += Poco::delegate(&target, &Target::onEvent);
    source.theEvent += Poco::delegate(&otherTarget, &OtherTarget::onEvent);
    source.fireEvent(100);
    source.theEvent -= Poco::delegate(&target, &Target::onEvent);
    source.theEvent -= Poco::delegate(&otherTarget, &OtherTarget::onEvent);

    return 0;
}