#pragma once
#include <vector>
#include "Cores.h"
#include "Album.h"
#include <iostream>
#include <string>

class AlbunsOuvidos
{
    private:
    std::vector<Album> albunsOuvidos;

    public:
    void ListarAlbunsPorLinhaDentroDoQuadro(int porLinha, int largura) const;
    bool Empty() const noexcept { return albunsOuvidos.empty(); }

    
    const std::vector<Album>& GetAlbuns() const noexcept { return albunsOuvidos; }
    std::vector<Album>& GetAlbuns()       noexcept { return albunsOuvidos; }
};
