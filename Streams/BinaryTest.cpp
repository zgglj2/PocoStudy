#include <Poco/BinaryReader.h>
#include <Poco/BinaryWriter.h>
#include <fstream>
#include <iostream>

using Poco::BinaryReader;
using Poco::BinaryWriter;

int main(int argc, char **argv) {
    std::ofstream ostr("binary.dat", std::ios::binary);
    BinaryWriter writer(ostr);

    writer.writeBOM();
    writer << "Hello World!!!" << 42;
    writer.write7BitEncoded((Poco::UInt32)123);
    writer << true;
    ostr.flush();
    ostr.close();

    std::ifstream istr("binary.dat", std::ios::binary);
    BinaryReader reader(istr);

    reader.readBOM();
    std::string hello;
    int i;
    bool b;

    reader >> hello >> i;
    std::cout << "hello:" << hello << std::endl;
    std::cout << "i:" << i << std::endl;
    reader.read7BitEncoded((Poco::UInt32&)i);
    std::cout << "i:" << i << std::endl;
    reader >> b;
    std::cout << "b:" << b << std::endl;



    return 0;
}