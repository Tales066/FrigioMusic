#pragma once
#include "Album.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class FilaDeInteresses{
	public:
	std::vector<Album> filaDeAlbum;
	public: void Adicionar(const Album& addAlbum);
	public: void Remover();
	public: void ExibirFilaDeInteresses(int porLinha) const{}

};

