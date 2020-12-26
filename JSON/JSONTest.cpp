#include <iostream>
#include "Poco/Dynamic/Var.h"
#include "Poco/Dynamic/Pair.h"
#include "Poco/Dynamic/VarIterator.h"
#include "Poco/JSON/Array.h"
#include <vector>
#include <map>
#include "Poco/JSON/Parser.h"

using Poco::Dynamic::Var;
using Poco::JSON::Parser;
using Poco::Dynamic::Pair;
using Poco::JSON::Array;
using Poco::JSON::Object;

int main(int argc, const char *argv[]) {
    using namespace std;
    Poco::JSON::Object scores;
    scores.set("数学", 98);
    scores.set("英语", 99);
    scores.set("语文", 89);
    scores.set("化学", 100);
    scores.set("物理", 98);
    scores.set("生物", 96);
    Poco::JSON::Object student;
    student.set("name", "小南");
    student.set("address", "四川省成都市锦江区锦华路");
    student.set("class", "四川省成都市第七中学");
    student.set("grade", Poco::Dynamic::Var(scores));
    Poco::Dynamic::Var JSON(student);
    cout << JSON.toString() << endl;
    string theJSON = JSON.toString();
    Poco::JSON::Parser parser;
    Poco::Dynamic::Var json = parser.parse(theJSON);
    Poco::JSON::Object theObj = *json.extract<Poco::JSON::Object::Ptr>();
    Poco::Dynamic::Var theScores = theObj.get("grade");
    Poco::Dynamic::Var name = theObj.get("name");
    Poco::Dynamic::Var address = theObj.get("address");
    Poco::Dynamic::Var theClass = theObj.get("class");
    Poco::JSON::Object grade = *theScores.extract<Poco::JSON::Object::Ptr>();
    Poco::Dynamic::Var math = grade.get("数学");
    Poco::Dynamic::Var english = grade.get("英语");
    Poco::Dynamic::Var chinese = grade.get("语文");
    Poco::Dynamic::Var wuli = grade.get("物理");
    Poco::Dynamic::Var shengwu = grade.get("生物");
    Poco::Dynamic::Var huaxue = grade.get("化学");
    cout << "\n\n姓名: " << name.toString() << endl
         << "班级: " << theClass.toString() << endl
         << "地址: " << address.toString() << endl
         << "数学: " << math.convert<int>() << endl
         << "语文: " << chinese.convert<int>() << endl
         << "化学: " << huaxue.convert<int>() << endl
         << "物理: " << wuli.convert<int>() << endl
         << "生物: " << shengwu.convert<int>() << endl;
    return 0;
}