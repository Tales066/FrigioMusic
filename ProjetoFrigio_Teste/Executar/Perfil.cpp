#include "Perfil.h"
#include "Resenha.h"

#include <iostream>
#include <sstream>
using namespace std;

void Perfil::MostrarPerfil() const
{
    const int largura = 52;

    std::cout << "\n" << corQuadrados;

    // Cabeçalho decorado
    std::cout << "═══■════■════■════■════■════■════■════■════■═══\n";
    std::cout << "     ✦✧✦ PERFIL DO USUÁRIO ✦✧✦\n";
    std::cout << "═══■════■════■════■════■════■════■════■════■═══\n";

    // Avatar e nome
    std::vector<std::string> linhasCabeca;
    std::istringstream stream(cabeca);
    std::string linha;
    while (std::getline(stream, linha))
        linhasCabeca.push_back(linha);

    while (linhasCabeca.size() < 3)
        linhasCabeca.push_back("       ");

    for (int i = 0; i < 3; ++i)
    {
        std::string parteCabeca = linhasCabeca[i];
        parteCabeca.resize(7, ' ');
        std::cout << "  " << parteCabeca << "  ";

        if (i == 1)
        {
            int espacos = largura - 7 - 4 - (int)nome.length();
            int esq = espacos / 2;
            int dir = espacos - esq;
            std::cout << std::string(esq, ' ') << nome << std::string(dir, ' ');
        }
        else
        {
            std::cout << std::string(largura - 7 - 4, ' ');
        }

        std::cout << "\n";
    }

    // Divisória com cor igual
    std::cout << corQuadrados << "═══■════■════■════■════■════■════■════■════■═══\n" << reset;

    // Álbuns
    if (albunsOuvidos.Empty())
    {
        std::cout << "Nenhum álbum avaliado.\n";
    }
    else
    {
        std::cout << "Meus álbuns avaliados:\n";
        std::cout << "\n";  // linha em branco extra
        albunsOuvidos.ListarAlbunsPorLinhaDentroDoQuadro(5, largura);
    }

    // Divisória com cor igual
    std::cout << corQuadrados << "═══■════■════■════■════■════■════■════■════■═══\n" << reset;

    // Watchlist
    if (filaDeInteresses.Empty())
    {
        std::cout << "Nenhuma Watchlist cadastrada.\n";
    }
    else
    {
        std::cout << "Minha Watchlist:\n";
        std::cout << "\n";  // linha em branco extra
        filaDeInteresses.ListarWatchlistPorLinhaDentroDoQuadro(5, largura);
    }

    // Final
    std::cout << corQuadrados << "═══■════■════■════■════■════■════■════■════■═══\n" << reset;
}
