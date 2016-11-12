#ifndef _ABORT_H_
#define _ABORT_H_

#include <cstdlib>

static void AbortFunction(int type) {
	// hier wäre eine Logausgabe in einer extra Datei ganz sinnvoll:D
	switch (type)
	{
	case INT8_MAX:{
		// do nothing
	}
	default:
		break;
	}
	
	abort();
}

#endif // !_ABORT_H_
