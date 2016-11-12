#ifndef _TOKENIZER_H_
#define _TOKENIZER_H_

#include "AbstractLogger.h"
#include "Abort.h"
#include "Token.h"
#include "File.h"

namespace Interpreter {
	class Tokenizer 
		: public Default::AbstractLogger{
	public:
		// muss �berpr�ft werden ob hier eine Kopie gen�gt oder 
		// gar eine Referenz mit �bergeben werden muss
		// vermutlich aber reicht eine Kopie, da die Werte nur 
		// gelesen werden m�ssen und nicht ver�ndert werden.
		// Das Ergebnis nach dem tokenizen ist dann der TokenFiles
		// In diesem Abschnitt w�re es nicht schlecht wenn ein 
		// TokenTree schon erstellt wird und die Token schon richtig 
		// einsortiert werden, damit diese nachher einfach mit einem 
		// ParseTokenTree ersetzt werden k�nnen und dann mit den richtigen 
		// Werten (zB f�r for-Schleifen) bef�llt werden.
		Tokenizer(SourceFiles);
		~Tokenizer();
		std::string toLogString();
	private:
		TokenFiles* tokenFiles;
	};
}

#endif // !_TOKENIZER_H_

