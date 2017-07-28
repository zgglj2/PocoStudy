#include <Poco/DOM/DOMParser.h>
#include <Poco/DOM/Document.h>
#include <Poco/DOM/NodeIterator.h>
#include <Poco/DOM/NodeFilter.h>
#include <Poco/DOM/AutoPtr.h>
#include <Poco/SAX/InputSource.h>
#include <Poco/DOM/NamedNodeMap.h>
#include "Poco/DOM/Text.h"
#include "Poco/DOM/Element.h"
#include "Poco/DOM/DOMWriter.h"
#include "Poco/XML/XMLWriter.h"
#include <iostream>

using Poco::XML::DOMParser;
using Poco::XML::Document;
using Poco::XML::NodeIterator;
using Poco::XML::NodeFilter;
using Poco::XML::AutoPtr;
using Poco::XML::InputSource;
using Poco::XML::NamedNodeMap;
using Poco::XML::Text;
using Poco::XML::Element;
using Poco::XML::DOMWriter;
using Poco::XML::XMLWriter;
using namespace std;

int main(int argc, char **argv) {
    try {
        DOMParser parser;
        AutoPtr<Document> pDoc = parser.parse("../../XML/DOMTest.xml");

        NodeIterator it(pDoc, NodeFilter::SHOW_ELEMENT);
        Poco::XML::Node* pNode = it.nextNode();
        while (pNode)
        {
            std::cout<<pNode->nodeName()<<":"<< pNode->nodeValue()<<std::endl;
            pNode = it.nextNode();
        }


        pDoc = new Document;
        AutoPtr<Element> pRoot = pDoc->createElement("root");
        pDoc->appendChild(pRoot);
        AutoPtr<Element> pChild1 = pDoc->createElement("child1");
        AutoPtr<Text> pText1 = pDoc->createTextNode("text1");
        pChild1->appendChild(pText1);
        pRoot->appendChild(pChild1);
        AutoPtr<Element> pChild2 = pDoc->createElement("child2");
        AutoPtr<Text> pText2 = pDoc->createTextNode("text2");
        pChild2->appendChild(pText2);
        pRoot->appendChild(pChild2);
        DOMWriter writer;
        writer.setNewLine("\n");
        writer.setOptions(XMLWriter::PRETTY_PRINT);
        writer.writeNode(std::cout, pDoc);
    } catch (Poco::Exception &exp) {
        cout << exp.displayText() << endl;
    }

    return 0;
}