#include "menu.h"
#include "cores.h"
#include "plataforma.h"
#include <iostream>
#include <string>
using namespace std;

void showMenu(int selected) {
    const int largura = 44;
    string options[] = {
        "Criar/Editar Perfil",
        "Adicionar Álbum",
        "Remover Álbum",
        "Ver Perfil e Álbuns",
        "Adicionar à Watchlist",
        "Alterar Cores",
        "Sair"
    };
    int n = sizeof(options)/sizeof(options[0]);

    limparTela();
    cout << corMenu;
    cout << "╔════════════════════════════════════════════╗\n";
    cout << "║              MENU DO PERFIL                 ║\n";
    cout << "╠════════════════════════════════════════════╣\n";

    for (int i = 0; i < n; ++i) {
        cout << "║ ";
        if (i == selected) {
            cout << "\033[1;36m> [ " << options[i];
            cout << string(largura - 6 - options[i].size(), ' ') << " ]\033[0m" << corMenu;
        } else {
            cout << "  " << options[i] << string(largura - 4 - options[i].size(), ' ');
        }
        cout << "║\n";
    }

    cout << "╚════════════════════════════════════════════╝\n" << reset;
    cout << "Use ↑/↓ para navegar e ENTER para selecionar.\n";
}

void menuUsuario() {
    Usuario u;
    carregarPerfil(u);
    int selected = 0;
    bool sair = false;

    while (!sair) {
        showMenu(selected);
        int key = getKey();

#ifdef _WIN32
        if (key == 72) selected = (selected - 1 + 7) % 7;
        else if (key == 80) selected = (selected + 1) % 7;
        else if (key == 13) {
#else
        if (key == 'U') selected = (selected - 1 + 7) % 7;
        else if (key == 'D') selected = (selected + 1) % 7;
        else if (key == '\n') {
#endif
            switch(selected) {
                case 0:
                    cout << "Nome: "; getline(cin, u.nome); salvarPerfil(u); break;
                case 1: {
                    Album a;
                    cout << "Título: "; getline(cin, a.titulo);
                    cout << "Nota (1 a 5): "; cin >> a.nota; cin.ignore();
                    u.albuns.push_back(a); salvarPerfil(u); break;
                }
                case 2:
                    if (u.albuns.empty()) { cout << "Nenhum álbum para remover.\nPressione Enter..."; cin.ignore(); break; }
                    cout << "Álbuns disponíveis:\n";
                    for (size_t i = 0; i < u.albuns.size(); ++i)
                        cout << i + 1 << ". " << u.albuns[i].titulo << " (Nota: " << u.albuns[i].nota << ")\n";
                    cout << "Digite o número do álbum para remover (0 para cancelar): ";
                    int rem; cin >> rem; cin.ignore();
                    if (rem > 0 && rem <= (int)u.albuns.size()) {
                        u.albuns.erase(u.albuns.begin() + rem - 1); salvarPerfil(u);
                        cout << "Álbum removido com sucesso.\n";
                    } else cout << "Operação cancelada.\n";
                    cout << "Pressione Enter..."; cin.ignore(); break;
                case 3:
                    limparTela(); u.mostrarPerfil(); cout << "Pressione Enter..."; cin.ignore(); break;
                case 4:
                    cout << "Título para Watchlist: "; {
                    string w; getline(cin, w); u.watchlist.push_back(w); salvarPerfil(u); }
                    break;
                case 5:
                    alterarCores(); break;
                case 6:
                    sair = true; break;
            }
        }
    }
}

