#include "Estrelas.h"

	static std::string GerarEstrelas(int nota)
	{

		int estrelas = static_cast<int>(nota / 2);
		return string(estrelas, '*');
	}

