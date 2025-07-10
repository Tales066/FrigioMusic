#include "Perfil.h"
#include "Resenha.h"

#include <iostream>
#include <sstream>  // para std::istringstream
using namespace std;

void Perfil::MostrarPerfil() const
{
    const int largura = 52;

    std::cout << "\n" << corQuadrados;

    // Linha superior
    std::cout << "╔";
    for(int i = 0; i < largura; ++i)
        std::cout << "═";
    std::cout << "╗\n";

    // Título centralizado
    std::cout << "║" << std::string((largura - 17) / 2, ' ') << "PERFIL DO USUÁRIO"
        << std::string(largura - 17 - (largura - 17) / 2, ' ') << "║\n";

    // Linha separadora
    std::cout << "╠";
    for(int i = 0; i < largura; ++i)
        std::cout << "═";
    std::cout << "╣\n";

    // >>>>> CABECINHA AO LADO DO NOME <<<<<
    std::vector<std::string> linhasCabeca;
    std::istringstream stream(cabeca);  // 'cabeca' vem do perfil
    std::string linha;
    while (std::getline(stream, linha))
        linhasCabeca.push_back(linha);

    // Garante 3 linhas para padronizar o tamanho
    while (linhasCabeca.size() < 3)
        linhasCabeca.push_back("       ");

    for (int i = 0; i < 3; ++i)
    {
        std::cout << "║ ";

        std::string parteCabeca = linhasCabeca[i];
        parteCabeca.resize(7, ' '); // largura fixa

        std::cout << parteCabeca << "  ";

        if (i == 1) // linha central mostra o nome
        {
            int espacos = largura - 7 - 3 - (int)nome.length();
            int esq = espacos / 2;
            int dir = espacos - esq;
            std::cout << std::string(esq, ' ') << nome << std::string(dir, ' ');
        }
        else
        {
            std::cout << std::string(largura - 7 - 3, ' ');
        }

        std::cout << "║\n";
    }

    // Linha separadora
    std::cout << "╠";
    for(int i = 0; i < largura; ++i)
        std::cout << "═";
    std::cout << "╣\n";

    // Álbuns avaliados
    if(albunsOuvidos.Empty())
    {
        std::cout << "║ Nenhum álbum avaliado." << std::string(largura - 23, ' ') << "║\n";
    }
    else
    {
        std::cout << "║ Meus álbuns avaliados:" << std::string(largura - 22, ' ') << "║\n";
        albunsOuvidos.ListarAlbunsPorLinhaDentroDoQuadro(3, largura);
    }

    // Linha separadora
    std::cout << "╠";
    for(int i = 0; i < largura; ++i)
        std::cout << "═";
    std::cout << "╣\n";

    // Watchlist
    if(filaDeInteresses.Empty())
    {
        std::cout << "║ Nenhuma Watchlist cadastrada." << std::string(largura - 30, ' ') << "║\n";
    }
    else
    {
        std::cout << "║ Minha Watchlist:" << std::string(largura - 17, ' ') << "║\n";
        filaDeInteresses.ListarWatchlistPorLinhaDentroDoQuadro(3, largura);
    }

    // Linha inferior
    std::cout << "╚";
    for(int i = 0; i < largura; ++i)
        std::cout << "═";
    std::cout << "╝" << reset << "\n";
}
