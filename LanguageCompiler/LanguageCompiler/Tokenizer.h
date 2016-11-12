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
		// muss überprüft werden ob hier eine Kopie genügt oder 
		// gar eine Referenz mit übergeben werden muss
		// vermutlich aber reicht eine Kopie, da die Werte nur 
		// gelesen werden müssen und nicht verändert werden.
		// Das Ergebnis nach dem tokenizen ist dann der TokenFiles
		// In diesem Abschnitt wäre es nicht schlecht wenn ein 
		// TokenTree schon erstellt wird und die Token schon richtig 
		// einsortiert werden, damit diese nachher einfach mit einem 
		// ParseTokenTree ersetzt werden können und dann mit den richtigen 
		// Werten (zB für for-Schleifen) befüllt werden.
		Tokenizer(SourceFiles);
		~Tokenizer();
		std::string toLogString();
	private:
		TokenFiles* tokenFiles;
	};
}

#endif // !_TOKENIZER_H_

