#ifndef _LOGGER_H_
#define _LOGGER_H_

#include <string>
#include <iostream>
#include <chrono>
#include <time.h>

#include "InOutput.h"
#include "AbstractLogger.h"

#define END_SIGN "\n"

namespace Default {
	class Logger {
	public:
		static Logger *getInstance() {
			if (_instance == nullptr) 
				_instance = new Logger();
			return _instance;
		}

		void setError(std::string s) {
			this->logData += "\t" + s + END_SIGN;
		}
		void setInfo(std::string s) {
			this->logData += s + END_SIGN;
		}

		void setObjectLog(AbstractLogger* object) {
			this->logData += object->toLogString() + END_SIGN;
		}

		void printLog() {
			std::cout << this->logData << std::endl;
		} 		

		void createLog() {
			write(this->writePath, this->logData);
			this->reset();
		}
	private:
		static Logger* _instance;

		const std::string writePath = "C:\\Users\\Documents\\logger.txt";

		std::string logData;
		Logger() {
			this->logData = this->createFirstLine();
		}

		void reset() {
			this->logData = "";
		}

		std::string createFirstLine() {
			std::string ret = "Logger data";
			ret += END_SIGN;
			return ret;
		}

	};

	Logger* Logger::_instance = nullptr;
}

#endif // !_LOGGER_H_
