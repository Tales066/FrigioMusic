#include "Perfil.h"
#include "Resenha.h"


#include <iostream>

using namespace std;
/*
	void Perfil:: MostrarPerfil()const 
	{
        cout << "\n👤 Perfil do Usuário\n";
        cout << "Nome: " << nome << endl;

        if(albunsOuvidos.albunsOuvidos.empty())//teste
        {
            cout << "\nNenhum álbum avaliado.\n";
        }
        else
        {
            cout << "\n🎵 Seus álbuns avaliados:\n";
            albunsOuvidos.ListarAlbunsPorLinhaDentroDoQuadro(3);
        }

        if(filaDeInteresses.filaDeAlbum.empty())
        {
            cout << "\nNenhum álbum foi encontrado na sua lista de interesses.\n";
        }
        else
        {
            cout << "\n📝 Sua lista de interesses:\n";
            filaDeInteresses.ListarWatchlistPorLinhaDentroDoQuadro(3);
        }
    }*/
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

    // Nome centralizado
    std::cout << "║" << std::string((largura - nome.length()) / 2, ' ') << nome
        << std::string(largura - nome.length() - (largura - nome.length()) / 2, ' ') << "║\n";

// Linha separadora
    std::cout << "╠";
    for(int i = 0; i < largura; ++i)
        std::cout << "═";
    std::cout << "╣\n";

    if(albunsOuvidos.Empty())
    {
        std::cout << "║ Nenhum álbum avaliado." << std::string(largura - 23, ' ') << "║\n";
    }
    else
    {
        std::cout << "║ Meus álbuns avaliados:" << std::string(largura - 22, ' ') << "║\n";
        albunsOuvidos.ListarAlbunsPorLinhaDentroDoQuadro(3, largura);
    }

    std::cout << "╠";
    for(int i = 0; i < largura; ++i)
        std::cout << "═";
    std::cout << "╣\n";

    if(filaDeInteresses.Empty())
    {
        std::cout << "║ Nenhuma Watchlist cadastrada." << std::string(largura - 29, ' ') << "║\n";
    }
    else
    {
        std::cout << "║ Minha Watchlist:" << std::string(largura - 17, ' ') << "║\n";
        filaDeInteresses.ListarWatchlistPorLinhaDentroDoQuadro(3, largura);
    }

    std::cout << "╚";
    for(int i = 0; i < largura; ++i)
        std::cout << "═";
    std::cout << "╝" << reset << "\n";
}

