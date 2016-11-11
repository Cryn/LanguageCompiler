#include <iostream>

#include "File.h"

void breaking();

int main() {
	Interpreter::Files foo;
	Interpreter::File foo1;
	foo.push_back(foo1);

	Interpreter::TokenFiles tfoo;
	Interpreter::convert(foo, &tfoo);

	breaking();

	return 0;
}

void breaking() {
	char a;
	std::cin >> a;
}