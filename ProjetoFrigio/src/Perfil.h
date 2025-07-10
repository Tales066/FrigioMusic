#pragma once
#include <string>
#include "AlbunsOuvidos.h"
#include "FilaDeInteresse.h"
#include "Favoritos.h"
#include "Resenha.h"

class Perfil
{
    private:
    std::string     nome;
    Favoritos       favs;
    std::vector<Resenha> resenhas;
    FilaDeInteresses filaDeInteresses;
    AlbunsOuvidos    albunsOuvidos;
    std::string cabeca;

    public:
        // acesso controlado
    void               SetNome(std::string n) { nome = std::move(n); }
    const std::string& GetNome() const noexcept { return nome; }

    AlbunsOuvidos& Albuns()       noexcept { return albunsOuvidos; }
    const AlbunsOuvidos& Albuns() const noexcept { return albunsOuvidos; }

    FilaDeInteresses& Watchlist()       noexcept { return filaDeInteresses; }
    const FilaDeInteresses& Watchlist() const noexcept { return filaDeInteresses; }

    void MostrarPerfil() const;
    
    void SetCabeca(const std::string& c) { cabeca = c; }
    std::string GetCabeca() const { return cabeca; }
};
