#ifndef _STATE_MACHINE_H_
#define _STATE_MACHINE_H_

#include <string>

namespace StateMachine {
	struct struct_stateMachine;

	typedef struct_stateMachine StateMachineStruct;
	
	struct struct_stateMachine {
		std::string language;
		bool isReaded;
	};


}

#endif // !_STATE_MACHINE_H_
