#pragma once
#include <string>
#include "Album.h"
#include "Estrelas.h"
using namespace std;

class Resenha
{
	Album album;
	std::string resenha;
	int nota;
    bool ouvido = false;
    bool favorito = false;


	public: std::string CriarResenha(std::string c) {}
	public: void MarcarComoOuvido() {}
	public:	void Remover(){}
	

};

