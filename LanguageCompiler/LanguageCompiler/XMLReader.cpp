#include "XMLReader.h"

Default::XMLReader::XMLReader(std::string content){
	this->content = content;
	this->xmlTokenStart = new XMLToken();
}

int Default::XMLReader::convert() {
	/*
		Aktuell kann dieser nur ein Element pro Ebene auslesen
		Sollte aber mehrere Elemente pro Ebene lesen können.
	*/
	std::string str = this->content;
	std::string firstTag = str.substr(0, str.find(">") + 1); 
	firstTag = firstTag.substr(1, firstTag.size() - this->offset);
	str = str.substr(firstTag.size() + this->offset);
	std::string endTag = str.substr(str.find("</" + firstTag));
	str = str.substr(0, str.find(endTag));
	this->xmlTokenStart->name = firstTag;
	this->xmlTokenStart->stage = 0;
	this->xmlTokenStart->parentXMLToken = nullptr;
	this->xmlTokenStart->
		subXMLTokens.push_back(this->nextXMLToken(str, 1, this->xmlTokenStart));
	return 0;
}

/*
	Diese Funktion sucht mir anhand des endstrings oder midstrings
	weitere xmlstrings
*/
Default::XMLToken *Default::XMLReader::nextXMLToken(std::string str, 
	int stage, Default::XMLToken* parentToken) {
	std::string s = str;
	int stageL = stage;
	if (s.size() == 0) return nullptr;
	XMLToken *xmlToken = new XMLToken();
	xmlToken->parentXMLToken = parentToken;
	if (s.find("<") == -1 || s.find(">") == -1) {
		xmlToken->name = s;
		xmlToken->stage = stageL;
		return xmlToken;
	}
	else {
		std::string firstTag = s.substr(s.find("<"), s.find(">") + 1);
		firstTag = firstTag.substr(1, firstTag.size() - this->offset);
		s = s.substr(firstTag.size() + this->offset);
		std::string midTag = s.substr(0, s.find("</" + firstTag));
		if (midTag.size() != 0)
			xmlToken->
				subXMLTokens.push_back(this->nextXMLToken(midTag, stage++, xmlToken));
		s = s.substr(s.find("</" + firstTag) + ("</" + firstTag).size() + 1);
		if(parentToken != NULL)
			parentToken->
				subXMLTokens.push_back(this->nextXMLToken(s, stageL, xmlToken->parentXMLToken));
		xmlToken->name = firstTag;
		xmlToken->stage = stageL;
	}
	return xmlToken;
}