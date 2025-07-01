#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>
using namespace std;

struct Album {
    string titulo;
    double nota;
};

struct Usuario {
    string nome;
    vector<Album> albuns;
    vector<string> watchlist;

    void mostrarPerfil() const {
        cout << "\n👤 Perfil do Usuário\n";
        cout << "Nome: " << nome << endl;

        if (albuns.empty()) {
            cout << "\nNenhum álbum avaliado.\n";
        } else {
            cout << "\n🎵 Seus álbuns avaliados:\n";
            listarAlbunsPorLinha(3);
        }

        if (watchlist.empty()) {
            cout << "\nNenhuma Watchlist cadastrada.\n";
        } else {
            cout << "\n📝 Sua Watchlist:\n";
            listarWatchlistPorLinha(3);
        }
    }

    void listarAlbunsPorLinha(int porLinha) const {
        for (size_t i = 0; i < albuns.size(); i += porLinha) {
            for (size_t j = i; j < i + porLinha && j < albuns.size(); ++j)
                cout << "\033[1;31m┌───────┐ \033[0m";
            cout << "\n";

            for (size_t j = i; j < i + porLinha && j < albuns.size(); ++j)
                cout << "\033[1;31m│\033[1;36m _|#|_ \033[1;31m│ \033[0m";
            cout << "\n";

            for (size_t j = i; j < i + porLinha && j < albuns.size(); ++j)
                cout << "\033[1;31m│\033[1;36m |(O)| \033[1;31m│ \033[0m";
            cout << "\n";

            for (size_t j = i; j < i + porLinha && j < albuns.size(); ++j)
                cout << "\033[1;31m│\033[1;36m ----- \033[1;31m│ \033[0m";
            cout << "\n";

            for (size_t j = i; j < i + porLinha && j < albuns.size(); ++j) {
                string nome = albuns[j].titulo;
                nome = nome.substr(0, min<size_t>(7, nome.length()));
                nome.append(7 - nome.length(), ' ');
                cout << "\033[1;31m│\033[1;32m" << nome << "\033[1;31m│ \033[0m";
            }
            cout << "\n";

            for (size_t j = i; j < i + porLinha && j < albuns.size(); ++j) {
                string estrelas = gerarEstrelas(albuns[j].nota);
                estrelas = estrelas.substr(0, min<size_t>(5, estrelas.length()));
                estrelas.append(5 - estrelas.length(), ' ');
                cout << "\033[1;31m│ \033[1;33m" << estrelas << "\033[1;31m │ \033[0m";
            }
            cout << "\n";

            for (size_t j = i; j < i + porLinha && j < albuns.size(); ++j)
                cout << "\033[1;31m└───────┘ \033[0m";
            cout << "\n";
        }
    }

    void listarWatchlistPorLinha(int porLinha) const {
        for (size_t i = 0; i < watchlist.size(); i += porLinha) {
            for (size_t j = i; j < i + porLinha && j < watchlist.size(); ++j)
                cout << "\033[1;35m┌───────┐ \033[0m";
            cout << "\n";

            for (size_t j = i; j < i + porLinha && j < watchlist.size(); ++j)
                cout << "\033[1;35m│\033[1;36m _|#|_ \033[1;35m│ \033[0m";
            cout << "\n";

            for (size_t j = i; j < i + porLinha && j < watchlist.size(); ++j)
                cout << "\033[1;35m│\033[1;36m |(O)| \033[1;35m│ \033[0m";
            cout << "\n";

            for (size_t j = i; j < i + porLinha && j < watchlist.size(); ++j)
                cout << "\033[1;35m│\033[1;36m ----- \033[1;35m│ \033[0m";
            cout << "\n";

            for (size_t j = i; j < i + porLinha && j < watchlist.size(); ++j) {
                string nome = watchlist[j];
                nome = nome.substr(0, min<size_t>(7, nome.length()));
                nome.append(7 - nome.length(), ' ');
                cout << "\033[1;35m│\033[1;32m" << nome << "\033[1;35m│ \033[0m";
            }
            cout << "\n";

            for (size_t j = i; j < i + porLinha && j < watchlist.size(); ++j)
                cout << "\033[1;35m└───────┘ \033[0m";
            cout << "\n";
        }
    }

    string gerarEstrelas(double nota) const {
        int estrelas = static_cast<int>(nota / 2);
        return string(estrelas, '*');
    }
};

void salvarPerfil(const Usuario& u) {
    ofstream out("perfil_com_albuns.txt");
    if (out.is_open()) {
        out << u.nome << endl;
        out << u.albuns.size() << endl;
        for (const auto& a : u.albuns) {
            out << a.titulo << endl;
            out << a.nota << endl;
        }
        out << u.watchlist.size() << endl;
        for (const auto& w : u.watchlist) {
            out << w << endl;
        }
        out.close();
        cout << "✅ Perfil salvo!\n";
    } else {
        cout << "❌ Erro ao salvar.\n";
    }
}

bool carregarPerfil(Usuario& u) {
    ifstream in("perfil_com_albuns.txt");
    if (in.is_open()) {
        getline(in, u.nome);
        size_t qtdAlbuns;
        in >> qtdAlbuns;
        in.ignore();
        u.albuns.clear();
        for (size_t i = 0; i < qtdAlbuns; ++i) {
            Album a;
            getline(in, a.titulo);
            in >> a.nota;
            in.ignore();
            u.albuns.push_back(a);
        }
        size_t qtdWatchlist;
        in >> qtdWatchlist;
        in.ignore();
        u.watchlist.clear();
        for (size_t i = 0; i < qtdWatchlist; ++i) {
            string w;
            getline(in, w);
            u.watchlist.push_back(w);
        }
        in.close();
        return true;
    }
    return false;
}

void menuUsuario() {
    Usuario u;
    carregarPerfil(u);
    int opcao;

    do {
        cout << "\033[1;34m╔══════════════════════════════════════════════╗\n";
        cout << "║              MENU DO PERFIL                  ║\n";
        cout << "╠══════════════════════════════════════════════╣\n";
        cout << "║ \033[1;32m1\033[1;34m - Criar/Editar Perfil                      ║\n";
        cout << "║ \033[1;32m2\033[1;34m - Adicionar Álbum                          ║\n";
        cout << "║ \033[1;32m3\033[1;34m - Ver Perfil e Álbuns                      ║\n";
        cout << "║ \033[1;32m4\033[1;34m - Adicionar à Watchlist                    ║\n";
        cout << "║ \033[1;32m5\033[1;34m - Marcar álbum da Watchlist como avaliado  ║\n";
        cout << "║ \033[1;32m6\033[1;34m - Sair                                     ║\n";
        cout << "╚══════════════════════════════════════════════╝\033[0m\n";
        cout << "Escolha: ";
        cin >> opcao;
        cin.ignore();

        switch (opcao) {
            case 1:
                cout << "Nome: ";
                getline(cin, u.nome);
                salvarPerfil(u);
                break;

            case 2: {
                Album a;
                cout << "Título do álbum: ";
                getline(cin, a.titulo);
                cout << "Nota do álbum (0 a 10): ";
                cin >> a.nota;
                cin.ignore();
                u.albuns.push_back(a);
                salvarPerfil(u);
                break;
            }

            case 3:
                cout << "\033[2J\033[H";
                u.mostrarPerfil();
                this_thread::sleep_for(chrono::seconds(3));
                cout << "\033[2J\033[H";
                break;

            case 4: {
                string nome;
                cout << "Título do álbum para Watchlist: ";
                getline(cin, nome);
                u.watchlist.push_back(nome);
                salvarPerfil(u);
                break;
            }

            case 5: {
                if (u.watchlist.empty()) {
                    cout << "Sua Watchlist está vazia.\n";
                    break;
                }

                cout << "Álbuns na Watchlist:\n";
                for (size_t i = 0; i < u.watchlist.size(); ++i) {
                    cout << i + 1 << " - " << u.watchlist[i] << endl;
                }

                cout << "Escolha o número do álbum para avaliar (0 para cancelar): ";
                int escolha;
                cin >> escolha;
                cin.ignore();

                if (escolha > 0 && static_cast<size_t>(escolha) <= u.watchlist.size()) {
                    Album a;
                    a.titulo = u.watchlist[escolha - 1];
                    cout << "Digite a nota para '" << a.titulo << "' (0 a 10): ";
                    cin >> a.nota;
                    cin.ignore();

                    u.albuns.push_back(a);
                    u.watchlist.erase(u.watchlist.begin() + (escolha - 1));
                    salvarPerfil(u);

                    cout << "Álbum '" << a.titulo << "' avaliado e movido para seus álbuns avaliados.\n";
                } else if (escolha == 0) {
                    cout << "Operação cancelada.\n";
                } else {
                    cout << "Escolha inválida.\n";
                }
                break;
            }

            case 6:
                cout << "👋 Até mais!\n";
                break;

            default:
                cout << "Opção inválida.\n";
        }

    } while (opcao != 6);
}

int main() {
    string purple = "\033[1;35m";
    string reset = "\033[0m";

    cout << purple;
    cout << "============================================" << endl;
    cout << "|                                          |" << endl;
    cout << "|     BEM-VINDO AO SEU LETTERBOXD MUSICAL  |" << endl;
    cout << "|                                          |" << endl;
    cout << "============================================" << endl;
    cout << reset;

    this_thread::sleep_for(chrono::seconds(3));
    cout << "\033[2J\033[H";
    menuUsuario();
    return 0;
}
