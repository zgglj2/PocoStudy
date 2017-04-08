#include "Poco/Timezone.h"
#include <iostream>

using Poco::Timezone;
using Poco::Timestamp;
using namespace std;

int main(int argc, char **argv) {
    int utcOffset = Timezone::utcOffset();
    int dst = Timezone::dst();
    bool isDst = Timezone::isDst(Timestamp());
    int tzd = Timezone::tzd();
    std::string name = Timezone::name();
    std::string stdName = Timezone::standardName();
    std::string dstName = Timezone::dstName();

    cout << "timezone name:" << name << ", standard name:" << stdName << ", dst name:" << dstName << endl;
    return 0;
}