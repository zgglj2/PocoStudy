#include <iostream>
#include <Poco/LocalDateTime.h>
#include "Poco/DateTimeFormatter.h"
#include "Poco/DateTimeFormat.h"

using namespace std;
using Poco::LocalDateTime;
using Poco::DateTimeFormatter;
using Poco::DateTimeFormat;

int main(int argc, char **argv) {
    LocalDateTime now;

    int year = now.year();
    int month = now.month();
    int day = now.day();
    int dow = now.dayOfWeek();
    int doy = now.dayOfYear();
    int hour = now.hour();
    int hour12 = now.hourAMPM();
    int min = now.minute();
    int sec = now.second();
    int ms = now.millisecond();
    int us = now.microsecond();
    double jd = now.julianDay();

    cout << "year:" << year << endl;
    cout << "month:" << month << endl;
    cout << "day:" << day << endl;
    cout << "dayOfWeek:" << dow << endl;
    cout << "dayOfYear:" << doy << endl;
    cout << "hour:" << hour << endl;
    cout << "hourAMPM:" << hour12 << endl;
    cout << "min:" << min << endl;
    cout << "sec:" << sec << endl;
    cout << "ms:" << ms << endl;
    cout << "us:" << us << endl;
    cout << "jd:" << jd << endl;

    Poco::Timestamp ts = now.timestamp();
    cout << ts.epochTime() << endl;
    cout << time(NULL) << endl;

    std::string s = DateTimeFormatter::format(ts, DateTimeFormat::SORTABLE_FORMAT);
    cout << s << endl;

    LocalDateTime dt(1973, 9, 12, 2, 30, 45);
    dt.assign(2006, 10, 13, 13, 45, 12, 345);

    bool isAM = dt.isAM(); // false
    bool isPM = dt.isPM(); // true

    cout << isAM << endl;
    cout << isPM << endl;


    return 0;
}