#include "Menu.h"

#include "cores.h"
#include "plataforma.h"
#include "ServicosPerfil.h"
#include <iostream>
#include <string>
using namespace std;

void Menu::showMenu(int selected)
{
    const int largura = 44; // Largura entre as bordas
    string options[] = {
        "Criar Perfil",
        "Adicionar Album",
        "Remover Album",
        "Ver Perfil e Albuns",
        "Adicionar a Watchlist",
        "Alterar Cores",
        "Sair"
    };
    size_t n = sizeof(options) / sizeof(options[0]);

    limparTela();
    cout << corMenu;
    cout << "╔═══════════════════════════════════════════╗\n";
    cout << "║              MENU DO PERFIL               ║\n";
    cout << "╠═══════════════════════════════════════════╣\n";

    for(size_t i = 0; i < n; ++i)
    {
        cout << "║";

        if(i == selected)
        {
            string texto = "> [ " + options[i] + " ]";
            size_t espacos = largura - texto.size();
            size_t espacosEsq = (espacos - 1) / 2;
            size_t espacosDir = espacos / 2;
            cout << "\033[1;30m" << string(espacosEsq, ' ') << texto << string(espacosDir, ' ') << "\033[0m" << corMenu;
        }
        else
        {
            string texto = options[i];
            size_t espacos = largura - texto.size();
            size_t espacosEsq = (espacos - 1) / 2;
            size_t espacosDir = espacos / 2;
            cout << string(espacosEsq, ' ') << texto << string(espacosDir, ' ');
        }

        cout << "║\n";
    }
    cout << "╚═══════════════════════════════════════════╝\n";
    cout << "\033[0m"; // Resetar cores
}

void Menu::menuUsuario()
{
    Perfil u;
    carregarPerfil(u);          // minúsculo, bate com função livre

    int selected = 0;
    bool sair = false;

    while(!sair)
    {
        Menu::showMenu(selected);
        int key = getKey();

        #ifdef _WIN32
        if(key == 72) selected = (selected + 6) % 7;
        else if(key == 80) selected = (selected + 1) % 7;
        else if(key == 13)
            #else
        if(key == 'U') selected = (selected + 6) % 7;
        else if(key == 'D') selected = (selected + 1) % 7;
        else if(key == '\n')
            #endif
        {
            switch(selected)
            {
                case 0:
                    {                           // criar/alterar perfil
                        std::string novo;
                        std::cout << "Nome: ";
                        std::getline(std::cin, novo);
                        u.SetNome(std::move(novo));
                        salvarPerfil(u);
                        break;
                    }
                case 1:
                    {                           // adicionar álbum
                        std::string titulo; double nota;
                        std::cout << "Título: "; std::getline(std::cin, titulo);
                        std::cout << "Nota (0-10): "; std::cin >> nota; std::cin.ignore();
                        Autor dummy{ "Desconhecido", {} };
                        u.Albuns().GetAlbuns().emplace_back(titulo, dummy, 0, nota);
                        salvarPerfil(u);
                        break;
                    }               
                case 2:
                    {                                // remover álbum
                        auto& lista = u.Albuns().GetAlbuns();

                        if(lista.empty())
                        {
                            std::cout << "Nenhum álbum.\nPressione Enter...";
                            std::cin.ignore();
                            break;
                        }

                        for(size_t i = 0; i < lista.size(); ++i)
                            std::cout << i + 1 << ". " << lista[i].GetTitulo()
                            << " (" << lista[i].GetNota() << ")\n";

                        std::cout << "Número p/ remover (0 cancela): ";
                        int idxInput;                           // ainda lê como int
                        std::cin >> idxInput; std::cin.ignore();

                        if(idxInput > 0)
                        {
                            size_t idx = static_cast<size_t>(idxInput);   // ← conversão segura
                            if(idx <= lista.size())
                            {
                                lista.erase(lista.begin() + idx - 1);
                                salvarPerfil(u);
                                std::cout << "Álbum removido.\n";
                            }
                            else
                            {
                                std::cout << "Índice fora do intervalo.\n";
                            }
                        }
                        break;
                    }
                case 3:                             // ver perfil
                    limparTela();
                    u.MostrarPerfil();
                    std::cout << "Enter para seguir…"; std::cin.ignore();
                    break;

                case 4:
                    {                           // add watchlist
                        std::string t; std::cout << "Título: "; std::getline(std::cin, t);
                        Autor dummy{ "Desconhecido", {} };
                        u.Watchlist().GetWatchlist().emplace_back(t, dummy, 0);
                        salvarPerfil(u);
                        break;
                    }
                case 5: alterarCores(); break;
                case 6: sair = true; break;
            }
        }
    }
}

