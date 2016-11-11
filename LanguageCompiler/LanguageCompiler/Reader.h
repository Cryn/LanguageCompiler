#ifndef _READER_H_
#define _READER_H_

#include <vector>

#include "Logger.h"
#include "File.h"
#include "Abort.h"

namespace Interpreter {
	class Reader : Default::AbstractLogger {
	public:
		Reader();
		Reader(std::string);
		Reader(std::vector<std::string>);
		~Reader();
		std::string toLogString();
	private:
		void generateFile(std::string, std::string);
		
		Files* files;
	};
}

#endif // !_READER_H_
