#pragma once
#include "Album.h"
#include <iostream>
#include <vector>
#include <string>
class FilaDeInteresses
{
    private:
    std::vector<Album> filaDeAlbum;

    public:
    void Adicionar(const Album& a);
    void Remover(const std::string& titulo);
    void ListarWatchlistPorLinhaDentroDoQuadro(int porLinha, int largura) const;
    bool Empty() const noexcept { return filaDeAlbum.empty(); }

    const std::vector<Album>& GetWatchlist() const noexcept { return filaDeAlbum; }
    std::vector<Album>& GetWatchlist()       noexcept { return filaDeAlbum; }
};


