#pragma once
#include <vector>
#include "Album.h"
class Favoritos
{	// classe que gerencia a exibição e comportamento dos favoritos no perfil

	private: std::vector<Album> AlbumFavs;

	public: void AddFavoritos(const Album& album);
	public:void Exibir();
	
};

