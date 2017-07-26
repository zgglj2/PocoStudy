#include <Poco/SAX/ContentHandler.h>
#include <Poco/SAX/SAXParser.h>
#include <Poco/SAX/Attributes.h>
#include <Poco/SAX/XMLReader.h>
#include "Poco/String.h"
#include <iostream>

using Poco::XML::ContentHandler;
using Poco::XML::SAXParser;
using Poco::XML::XMLString;
using Poco::XML::XMLReader;
using namespace std;

class MyContentHandler : public ContentHandler {
public:
    void setDocumentLocator(const Poco::XML::Locator *loc) override {
        cout << "setDocumentLocator()" << endl;
    }

    void startDocument() override {
        cout << "startDocument()" << endl;
    }

    void endDocument() override {
        cout << "endDocument()" << endl;
    }

    void startElement(const XMLString &uri, const XMLString &localName, const XMLString &qname,
                      const Poco::XML::Attributes &attrList) override {
        cout << "startElement()" << ", uri: " << uri << ", localName: " << localName << ", qname: " << qname << endl;
        for (int i = 0; i < attrList.getLength(); ++i) {
            cout << "    " << ", attribute name: " << attrList.getLocalName(i) << ", value: " << attrList.getValue(i)
                 << endl;
        }

    }

    void endElement(const XMLString &uri, const XMLString &localName, const XMLString &qname) override {
        cout << "endElement()" << ", uri: " << uri << ", localName: " << localName << ", qname: " << qname << endl;

    }

    void characters(const Poco::XML::XMLChar *ch, int start, int length) override {
        std::string ss(ch);
        ss.resize(length);
        ss.erase(0, start);
        Poco::trimInPlace(ss);
        if (ss.size() != 0 && ss != "\n")
            cout << "characters()" << ", ch: " << ss << ", start: " << start << ", length: " << length << endl;
    }

    void ignorableWhitespace(const Poco::XML::XMLChar *ch, int start, int length) override {
//        cout << "ignorableWhitespace()" << ", ch: " << ch << ", start: " << start << ", length: " << length << endl;
    }

    void processingInstruction(const XMLString &target, const XMLString &data) override {
        cout << "processingInstruction()" << ", target: " << target << ", data: " << data << endl;
    }

    void startPrefixMapping(const XMLString &prefix, const XMLString &uri) override {
        cout << "startPrefixMapping()" << ", prefix: " << prefix << ", uri: " << uri << endl;
    }

    void endPrefixMapping(const XMLString &prefix) override {
        cout << "endPrefixMapping()" << ", prefix: " << prefix << endl;
    }

    void skippedEntity(const XMLString &name) override {
        cout << "skippedEntity()" << ", name: " << name << endl;
    }

};

int main(int argc, char **argv) {
    MyContentHandler handler;
    SAXParser parser;
    parser.setFeature(XMLReader::FEATURE_NAMESPACES, true);
    parser.setFeature(XMLReader::FEATURE_NAMESPACE_PREFIXES, true);
    parser.setContentHandler(&handler);
    try {
        parser.parse("../../XML/SAXTest.xml");
    }
    catch (Poco::Exception &e) {
        std::cerr << e.displayText() << std::endl;
    }

    return 0;
}