#pragma once
#include <string>
#include "Album.h"
#include "Estrela.h"


class Resenha
{
	Album album;
	std::string resenha;
	int nota;
    bool ouvido = false;
    bool favorito = false;


	public: std::string CriarResenha(std::string c);
	public: void MarcarComoOuvido();
	public:	void Remover();
	

};

