#pragma once
#include <vector>
#include "Album.h"
class Favoritos
{	// classe que gerencia a exibi��o e comportamento dos favoritos no perfil

	private: std::vector<Album> AlbumFavs;

	public: void AddFavoritos(const Album& album);
	public:void Exibir();
	
};

