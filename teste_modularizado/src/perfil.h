#pragma once
#include <string>
#include <vector>

struct Album {
    std::string titulo;
    double nota;
};

struct Usuario {
    std::string nome;
    std::vector<Album> albuns;
    std::vector<std::string> watchlist;

    void mostrarPerfil() const;
    void listarAlbunsPorLinhaDentroDoQuadro(int porLinha, int largura) const;
    void listarWatchlistPorLinhaDentroDoQuadro(int porLinha, int largura) const;
};

void salvarPerfil(const Usuario& u);
bool carregarPerfil(Usuario& u);
