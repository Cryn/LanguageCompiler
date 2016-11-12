#ifndef _READER_H_
#define _READER_H_

#include <vector>

#include "AbstractLogger.h"
#include "InOutput.h"
#include "File.h"
#include "Abort.h"
#include "StateMachine.h"

namespace Interpreter {
	class Reader 
		: public Default::AbstractLogger {
	public:
		Reader(std::string, StateMachine::StateMachineStruct*);
		Reader(std::vector<std::string>, StateMachine::StateMachineStruct*);
		~Reader();

		SourceFiles* generateFiles();

		std::string toLogString();
	private:

		//SourceFiles* getFiles();
		void init();

		bool isReaded;
		bool isStateSetted;
		std::vector<std::string> path;
		Files* files;
		StateMachine::StateMachineStruct* stateMachine;
	};
}

#endif // !_READER_H_
