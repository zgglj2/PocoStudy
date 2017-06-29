#include "Poco/File.h"
#include "Poco/Path.h"
#include <iostream>

using Poco::File;
using Poco::Path;
using namespace std;

int main(int argc, char **argv) {
    Path tmpPath(Path::temp());
    tmpPath.pushDirectory("PocoFileSample");
    File tmpDir(tmpPath);
    tmpDir.createDirectories();
    bool exists = tmpDir.exists();
    cout << "tmpDir.exists() : " << exists << endl;
    bool isFile = tmpDir.isFile();
    cout << "tmpDir.isFile() : " << isFile << endl;
    bool isDir = tmpDir.isDirectory();
    cout << "tmpDir.isDirectory() : " << isDir << endl;
    bool canRead = tmpDir.canRead();
    cout << "tmpDir.canRead() : " << canRead << endl;
    bool canWrite = tmpDir.canWrite();
    cout << "tmpDir.canWrite() : " << canWrite << endl;
    File tmpFile(Path(tmpPath, std::string("PocoFileSample.dat")));
    if (tmpFile.exists() || tmpFile.createFile()) {
        tmpFile.setSize(10000);
        File tmpFile2(Path(tmpPath, std::string("PocoFileSample2.dat")));
        cout << "tmpFile2.path() : " << tmpFile2.path() << endl;
        tmpFile.copyTo(tmpFile2.path());
        Poco::Timestamp now;
        tmpFile.setLastModified(now);
        tmpFile.setReadOnly();
        canWrite = tmpFile.canWrite();
        tmpFile.setWriteable();
        canWrite = tmpFile.canWrite();
    }
    std::vector<std::string> files;
    tmpDir.list(files);
    std::vector<std::string>::iterator it = files.begin();
    for (; it != files.end(); ++it) {
        std::cout << *it << std::endl;
    }
//    tmpDir.remove(true);
    return 0;
}