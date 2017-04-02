#include <iostream>
#include "Poco/SingletonHolder.h"

class MySingleton {
public:
    MySingleton() {

    }
    ~MySingleton(){

    }
    static MySingleton& instance(){
        static Poco::SingletonHolder<MySingleton> sh;
        return *sh.get();
    }
};

int main(int argc, char **argv) {
    MySingleton& instance = MySingleton::instance();

    return 0;
}