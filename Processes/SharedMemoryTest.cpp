#include <Poco/SharedMemory.h>
#include <Poco/File.h>
#include <string>
#include <iostream>

using Poco::SharedMemory;
using Poco::File;
using namespace std;

int main(int argc, char **argv) {
    File f("../../Processes/CMakeLists.txt");
    SharedMemory mem(f, SharedMemory::AM_READ);

    for (char* ptr = mem.begin(); ptr != mem.end(); ptr++) {
        cout << *ptr;
    }


    SharedMemory mem2("MySharedMemnory", 64, SharedMemory::AM_WRITE);
    for (char* ptr = mem2.begin(); ptr != mem2.end(); ptr++) {
        *ptr = 'x';
    }
    for (char* ptr = mem2.begin(); ptr != mem2.end(); ptr++) {
        cout << *ptr;
    }
    return 0;
}