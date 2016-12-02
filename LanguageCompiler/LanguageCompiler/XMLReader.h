#ifndef _XML_READER_H_
#define _XML_READER_H_

#include "AbstractLogger.h"
#include "Pair.h"
#include <string>
#include <iostream>
#include <vector>


namespace Default {
	struct struct_xml_token;
	typedef struct_xml_token XMLToken;
	struct struct_xml_token {
		Default::Pairs *attributes;
		int stage;
		std::string name;
		XMLToken* parentXMLToken;
		std::vector<XMLToken*> subXMLTokens;
	};

	class XMLReader 
		: public Default::AbstractLogger {
	public:
		// der XMLReader bekommt den String mit dem Inhalt der 
		// zu lesenden Datei
		XMLReader(std::string);
		int convert();
		std::string toLogString() { return ""; };
	private:
		const int offset = 2;
		std::string content;
		XMLToken *xmlTokenStart;
		XMLToken *innerXMLToken(std::string, int, XMLToken*);
		Default::Pairs *readPairs(std::string);		
	};
}

#endif // !_XML_READER_H_
