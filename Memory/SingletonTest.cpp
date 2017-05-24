#include <iostream>
#include "Poco/SingletonHolder.h"

class MySingleton {
public:
    MySingleton() {

    }
    ~MySingleton(){

    }
    static MySingleton* instance(){
        static Poco::SingletonHolder<MySingleton> sh;
        return sh.get();
    }
};

int main(int argc, char **argv) {
    MySingleton* instance1 = MySingleton::instance();
    MySingleton* instance2 = MySingleton::instance();

    std::cout << "instance1:" << instance1 << ", instance2:" << instance2 << std::endl;
    return 0;
}