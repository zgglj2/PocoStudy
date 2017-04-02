#include <iostream>
#include <vector>
#include "Poco/Platform.h"

using namespace std;

int main(int argc, char **argv) {
#if POCO_OS == POCO_OS_WINDOWS_NT
    cout << "POCO_OS_WINDOWS_NT" <<endl;
#elif POCO_OS == POCO_OS_LINUX
    cout << "POCO_OS_LINUX" <<endl;
#elif POCO_OS == POCO_OS_CYGWIN
    cout << "POCO_OS_CYGWIN" <<endl;
#endif

#if defined(POCO_OS_FAMILY_UNIX)
    cout << "POCO_OS_FAMILY_UNIX" <<endl;
#elif defined(POCO_OS_FAMILY_WINDOWS)
    cout << "POCO_OS_FAMILY_WINDOWS" <<endl;
#endif


    return 0;
}