#include "Poco/Path.h"
#include <iostream>
#include <Poco/Environment.h>

using namespace std;
using Poco::Path;
using Poco::Environment;

int main(int argc, char **argv) {
    Poco::Path p(true); // path will be absolute
    p.setNode("VMS001");
    p.setDevice("DSK001");
    p.pushDirectory("POCO");
    p.pushDirectory("INCLUDE");
    p.pushDirectory("POCO");
    p.setFileName("POCO.H");
    std::string s(p.toString(Poco::Path::PATH_VMS));
    // "VMS001::DSK001:[POCO.INCLUDE.POCO]POCO.H"
    cout << s << endl;

    p.clear(); // start over with a clean state
    p.pushDirectory("projects");
    p.pushDirectory("poco");
    s = p.toString(Poco::Path::PATH_WINDOWS); // "projects\poco\"
    cout << s << endl;
    s = p.toString(Poco::Path::PATH_UNIX); // "projects/poco/"
    cout << s << endl;
    s = p.toString(); // depends on your platform
    cout << s << endl;


    p = "projects\\poco";
    p = "projects/poco";
    p.parse("/usr/include/stdio.h", Path::PATH_UNIX);
    bool ok = p.tryParse("/usr/*/stdio.h");
    cout << "p.tryParse(\"/usr/*/stdio.h\") : " << ok << endl;
    ok = p.tryParse("/usr/include/stdio.h", Path::PATH_UNIX);
    cout << "p.tryParse(\"/usr/include/stdio.h\", Path::PATH_UNIX) : " << ok << endl;
    ok = p.tryParse("/usr/include/stdio.h", Path::PATH_WINDOWS);
    cout << "p.tryParse(\"/usr/include/stdio.h\", Path::PATH_WINDOWS) : " << ok << endl;
    ok = p.tryParse("DSK$PROJ:[POCO]BUILD.COM", Path::PATH_GUESS);
    cout << "p.tryParse(\"DSK$PROJ:[POCO]BUILD.COM\", Path::PATH_GUESS) : " << ok << endl;


    p = "/usr/include/stdio.h";
    std::string device(p.getDevice()); // "c"
    cout << "p.getDevice() : " << device << endl;
    int n = p.depth(); // 2
    cout << "p.depth() : " << n << endl;
    std::string dir1(p.directory(0)); // "projects"
    cout << "p.directory(0) : " << dir1 << endl;
    std::string dir2(p[1]); // "poco"
    cout << "p[1] : " << dir2 << endl;
    std::string fileName(p[2]); // "build_vs80.cmd"
    cout << "p[2] : " << fileName << endl;
    fileName = p.getFileName();
    cout << "p.getFileName() : " << fileName << endl;
    std::string baseName(p.getBaseName()); // "build_vs80"
    cout << "p.getBaseName() : " << baseName << endl;
    std::string extension(p.getExtension()); // "cmd"
    cout << "p.getExtension() : " << extension << endl;
    p.setBaseName("build_vs71");
    fileName = p.getFileName(); // "build_vs71.cmd"
    cout << "p.getFileName() : " << fileName << endl;

    p = "/usr/include/stdio.h";
    cout << "p.parent() : " << p.parent().toString(Path::PATH_UNIX) << endl;

    Path p1("stdlib.h");
    Path p2("/opt/Poco/include/Poco.h", Path::PATH_UNIX);
    p.resolve(p1);
    s = p.toString(Path::PATH_UNIX); // "/usr/include/stdlib.h"
    cout << "\"stdlib.h\" : " << s << endl;
    p.resolve(p2);
    s = p.toString(Path::PATH_UNIX); // "/opt/Poco/include/Poco.h"
    cout << "\"/opt/Poco/include/Poco.h\" : " << s << endl;

    p = "./PathTest.exe";
    cout << p.absolute().toString() << endl;


    std::cout << "cwd: " << Path::current() << std::endl
              << "home: " << Path::home() << std::endl
              << "temp: " << Path::temp() << std::endl
              << "null: " << Path::null() << std::endl;

    cout << "Path::expand(\"$HOME/config.ini\") : " << Path::expand("$HOME/config.ini") << endl;

    std::string shellName("sh");
    std::string path(Environment::get("PATH"));
    Path shellPath;
    bool found = Path::find(path, shellName, shellPath);
    cout << "found : " << found << endl;
    if (found) {
        cout << "shellPath : " << shellPath.toString() << endl;
    }

    return 0;
}