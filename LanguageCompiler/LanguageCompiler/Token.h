#ifndef _TOKEN_H_
#define _TOKEN_H_

#include <string>

#include "Vec2D.h"

namespace Interpreter {
	enum ETokenType {

	};

	struct struct_token;

	typedef struct_token Token;

	struct struct_token {
		ETokenType tokenType;
		Math::Vec2D position;
		std::string fileName;
		std::string content;
	};
}

#endif // !_TOKEN_H_
