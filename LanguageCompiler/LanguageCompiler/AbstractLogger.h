#ifndef _ABSTRACT_LOGGER_H_
#define _ABSTRACT_LOGGER_H_

#include <string>

namespace Default {
	class AbstractLogger {
	public:
		virtual std::string toLogString() = 0;
	};
}

#endif // !_ABSTRACT_LOGGER_H_

