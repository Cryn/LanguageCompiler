#include <iostream>
#include "XMLReader.h"

void breaking();

int main() {
	std::string source;
	source = "<TEST><R>BAUM</R><T></T></TEST>";

	Default::XMLReader* xmlReader = new Default::XMLReader(source);
	xmlReader->convert();

	breaking();
	return 0;
}

void breaking() {
	char a;
	std::cin >> a;
}