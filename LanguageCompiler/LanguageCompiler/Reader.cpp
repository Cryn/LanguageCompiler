#include "Reader.h"

#include <string>

Interpreter::Reader::Reader(std::string singleFile, StateMachine::StateMachineStruct* stateMachine) {
	this->init();
	this->path.push_back(singleFile);
	if (stateMachine == nullptr)
		stateMachine = new StateMachine::StateMachineStruct();
	this->stateMachine = stateMachine;
	if (singleFile.compare(".lang")) {
		this->stateMachine->language 
			= singleFile.substr(0, singleFile.find("."));
		this->isStateSetted = true;
	}
	File f;
	if (this->files == NULL)
		this->files = new Files();
	this->files->push_back(f);
}

Interpreter::Reader::Reader(std::vector<std::string> multiFiles, 
	StateMachine::StateMachineStruct* stateMachine) {
	this->init();
	this->path = multiFiles;
	for each (auto var in multiFiles) {
		if (!isStateSetted) {
			Reader(multiFiles, stateMachine);
			return;
		}
	}
}

Interpreter::Reader::~Reader() {
		this->stateMachine->isReaded 
			= this->isReaded;
		delete this->files;
}

//Interpreter::SourceFiles* Interpreter::Reader::getFiles() {
//	SourceFiles* files = new SourceFiles();
//	convert(this->files, files);
//	return files;
//}

Interpreter::SourceFiles* Interpreter::Reader::generateFiles() {
	this->isReaded = true;
	SourceFiles* files = new SourceFiles();
	convert(this->files, files);
	for (unsigned int i = 0; i < this->path.size(); i++) {
		std::string sourceCode = Default::read(this->path[i]);
		files->at(i).source = sourceCode;
	}
	return files;
}

void Interpreter::Reader::init() {
	this->isReaded = false;
	this->isStateSetted = false;
}

std::string Interpreter::Reader::toLogString() {
	std::string ret  = "#############################################################";
	ret				+= "\n";
	ret				+= "Reader class";
	ret				+= "\n";
	ret				+= "Contain: " + this->path.size();
	ret				+= "\n";
	if (this->files == NULL || this->path.size() != this->files->size()) {
		ret			+= "Paths are not equal to files";
		AbortFunction(INT8_MAX);
	}
	else {
		for (unsigned int i = 0; i < this->path.size(); i++) {
			ret		+= "\tName: " + this->path[i];
			ret		+= "\n";
			ret		+= "\tConnected files among: " + this->files->at(i).connectedFiles.size();
			ret		+= "\n";
			ret		+= "\tLanguage: " + this->files->at(i).language;
			ret		+= "\n";
		}
	}
	return ret;
}