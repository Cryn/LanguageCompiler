#ifndef _FILE_H_
#define _FILE_H_

#include <vector>
#include <string>

#include "Token.h"
#include "Vec2D.h"

#define NO_CONTENT "No content, needs to be filled as soon as pssible"

namespace Interpreter {
	struct struct_file;
	struct struct_file_token;
	struct struct_file_source;

	typedef struct_file File;
	typedef struct_file_token TokenFile;
	typedef struct_file_source SourceFile;
	typedef std::vector<File> Files;
	typedef std::vector<TokenFile> TokenFiles;
	typedef std::vector<SourceFile> SourceFiles;

	struct struct_file {
		bool isLanguage;
		Files connectedFiles;
		std::string language;
	};

	struct struct_file_token {
		File structFile;
		std::vector<Token> tokenStream;
	};

	struct struct_file_source {
		File structFile;
		std::string source;
	};
	static void copy(File f1, File* f2) {
		for each (auto var in f1.connectedFiles)
			f2->connectedFiles.push_back(var);
		f2->isLanguage = f1.isLanguage;
		f2->language = f1.language;
	}
	/*
		Diese Funktion zerstört am Ende alle File-Objekte die sich 
		in files befinden und konvertiert diese direkt in tokenFiles;
	*/
	static void convert(Files* files, TokenFiles* tokenFiles) {
		if (tokenFiles == nullptr) {
			tokenFiles = new std::vector<TokenFile>();
		}
		for each (auto var in *files){
			TokenFile tFile = TokenFile();
			copy(var, &(tFile.structFile));
			
			Token t;
			t.content = NO_CONTENT;
			t.fileName = NO_CONTENT;
			t.position = Math::Vec2D();
			t.tokenType = (ETokenType)0;
			
			tFile.tokenStream.push_back(t);
			tokenFiles->push_back(tFile);
		}
		files->clear();
	}

	static void convert(Files* files, SourceFiles* sourceFiles) {
		if (sourceFiles == nullptr) {
			sourceFiles = new std::vector<SourceFile>();
		}
		if (files == NULL)
			return;
		for each (auto var in *files) {
			SourceFile sFile = SourceFile();
			copy(var, &(sFile.structFile));

			sFile.source = NO_CONTENT;
			sourceFiles->push_back(sFile);
		}
		files->clear();
	}
}

#endif //_FILE_H_