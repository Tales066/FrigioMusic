#pragma once
#include <string>
#include <vector>
#include "Favoritos.h"
#include "Resenha.h"
#include "AlbunsOuvidos.h"
#include "FilaDeInteresses.h"
class Perfil
{
	std::string nome;
	Favoritos favs;
	std::vector<Resenha> resenhas;
	FilaDeInteresses filaDeInteresses;
	AlbunsOuvidos albunsOuvidos;


	public: void MostrarPerfil()const{}

};

