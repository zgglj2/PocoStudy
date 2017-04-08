#include "Poco/DateTime.h"
#include "Poco/Timespan.h"

using Poco::DateTime;
using Poco::Timespan;

int main(int argc, char **argv) {
// what is my age?
    DateTime birthdate(1973, 9, 12, 2, 30); // 1973-09-12 02:30:00
    DateTime now;
    Timespan age = now - birthdate;
    int days = age.days();         // in days
    int hours = age.totalHours();   // in hours
    int secs = age.totalSeconds(); // in seconds
// when was I 10000 days old?
    Timespan span(10000 * Timespan::DAYS);
    DateTime dt = birthdate + span;
    return 0;
}