#include <Poco/Thread.h>
#include <Poco/ActiveMethod.h>
#include <Poco/ActiveDispatcher.h>
#include <iostream>

using Poco::Thread;
using Poco::ActiveMethod;
using Poco::ActiveResult;
using Poco::ActiveDispatcher;
using Poco::ActiveStarter;
using namespace std;

class ActiveAdder : public ActiveDispatcher {
public:
    ActiveAdder() : add(this, &ActiveAdder::AddImpl) {}

    ActiveMethod<int, std::pair<int, int>, ActiveAdder, ActiveStarter<ActiveDispatcher> > add;

private:
    int AddImpl(const std::pair<int, int>& args) {
        return args.first + args.second;
    }
};

int main(int argc, char **argv) {
    ActiveAdder adder;
    ActiveResult<int> sum = adder.add(std::make_pair(1, 2));
    sum.wait();
    cout << "result: " << sum.data() << endl;

    return 0;
}