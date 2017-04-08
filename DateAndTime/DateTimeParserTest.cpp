#include "Poco/DateTimeParser.h"
#include "Poco/DateTime.h"
#include "Poco/DateTimeFormat.h"
#include "Poco/LocalDateTime.h"
#include "Poco/Timestamp.h"

using Poco::DateTimeParser;
using Poco::DateTimeFormat;
using Poco::DateTime;

int main(int argc, char **argv) {
    std::string s("Sat, 1 Jan 2005 12:00:00 GMT");
    int tzd;
    DateTime dt;
    DateTimeParser::parse(DateTimeFormat::RFC1123_FORMAT, s, dt, tzd);
    Poco::Timestamp ts = dt.timestamp();
    Poco::LocalDateTime ldt(tzd, dt);
    bool ok = DateTimeParser::tryParse("2006-10-22", dt, tzd);
    ok = DateTimeParser::tryParse("%e.%n.%Y", "22.10.2006", dt, tzd);
    return 0;
}