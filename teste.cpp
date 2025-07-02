#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>
using namespace std;

// Variáveis globais para cores
string corQuadrados = "\033[1;31m";  // cor padrão para álbuns e watchlist (vermelho)
string corMenu = "\033[1;34m";       // cor padrão para o menu (azul)
string reset = "\033[0m";

// Função que converte nome de cor para código ANSI
string corParaCodigo(const string& cor) {
    if (cor == "vermelho") return "\033[1;31m";
    if (cor == "roxo")     return "\033[1;35m";
    if (cor == "azul")     return "\033[1;34m";
    if (cor == "verde")    return "\033[1;32m";
    if (cor == "amarelo")  return "\033[1;33m";
    if (cor == "ciano")    return "\033[1;36m";
    return "\033[0m";
}

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
                cout << corQuadrados << "┌───────┐ " << reset;
            cout << "\n";

            for (size_t j = i; j < i + porLinha && j < albuns.size(); ++j)
                cout << corQuadrados << "│" << "\033[1;36m _|#|_ " << corQuadrados << "│ " << reset;
            cout << "\n";

            for (size_t j = i; j < i + porLinha && j < albuns.size(); ++j)
                cout << corQuadrados << "│" << "\033[1;36m |(O)| " << corQuadrados << "│ " << reset;
            cout << "\n";

            for (size_t j = i; j < i + porLinha && j < albuns.size(); ++j)
                cout << corQuadrados << "│" << "\033[1;36m ----- " << corQuadrados << "│ " << reset;
            cout << "\n";

            for (size_t j = i; j < i + porLinha && j < albuns.size(); ++j) {
                string nome = albuns[j].titulo.substr(0, 7);
                int espacos = 7 - (int)nome.length();
                if (espacos > 0) {
                    nome.append(espacos, ' ');
                }
                cout << corQuadrados << "│" << "\033[1;32m" << nome << corQuadrados << "│ " << reset;
            }
            cout << "\n";

            for (size_t j = i; j < i + porLinha && j < albuns.size(); ++j) {
                // Verificação de validade da nota
                int estrelasCount = static_cast<int>(albuns[j].nota);
                if (estrelasCount < 0) estrelasCount = 0;
                if (estrelasCount > 5) estrelasCount = 5;

                string estrelas(estrelasCount, '*');
                estrelas.append(5 - estrelasCount, ' ');  // Preenche com espaços
                cout << corQuadrados << "│ " << "\033[1;33m" << estrelas << corQuadrados << " │ " << reset;
            }
            cout << "\n";

            for (size_t j = i; j < i + porLinha && j < albuns.size(); ++j)
                cout << corQuadrados << "└───────┘ " << reset;
            cout << "\n";
        }
    }

    void listarWatchlistPorLinha(int porLinha) const {
        for (size_t i = 0; i < watchlist.size(); i += porLinha) {
            for (size_t j = i; j < i + porLinha && j < watchlist.size(); ++j)
                cout << corQuadrados << "┌───────┐ " << reset;
            cout << "\n";

            for (size_t j = i; j < i + porLinha && j < watchlist.size(); ++j)
                cout << corQuadrados << "│" << "\033[1;36m _|#|_ " << corQuadrados << "│ " << reset;
            cout << "\n";

            for (size_t j = i; j < i + porLinha && j < watchlist.size(); ++j)
                cout << corQuadrados << "│" << "\033[1;36m |(O)| " << corQuadrados << "│ " << reset;
            cout << "\n";

            for (size_t j = i; j < i + porLinha && j < watchlist.size(); ++j)
                cout << corQuadrados << "│" << "\033[1;36m ----- " << corQuadrados << "│ " << reset;
            cout << "\n";

            for (size_t j = i; j < i + porLinha && j < watchlist.size(); ++j) {
                string nome = watchlist[j].substr(0, 7);
                int espacos = 7 - (int)nome.length();
                if (espacos > 0) {
                    nome.append(espacos, ' ');
                }
                cout << corQuadrados << "│" << "\033[1;32m" << nome << corQuadrados << "│ " << reset;
            }
            cout << "\n";

            for (size_t j = i; j < i + porLinha && j < watchlist.size(); ++j)
                cout << corQuadrados << "└───────┘ " << reset;
            cout << "\n";
        }
    }
};

void salvarPerfil(const Usuario& u) {
    ofstream out("perfil_com_albuns.txt");
    if (out.is_open()) {
        out << u.nome << endl;
        out << u.albuns.size() << endl;
        for (const auto& a : u.albuns) {
            out << a.titulo << endl << a.nota << endl;
        }
        out << u.watchlist.size() << endl;
        for (const auto& w : u.watchlist) {
            out << w << endl;
        }
        cout << "✅ Perfil salvo!\n";
    }
}

bool carregarPerfil(Usuario& u) {
    ifstream in("perfil_com_albuns.txt");
    if (in.is_open()) {
        getline(in, u.nome);
        size_t qtdAlbuns, qtdWatchlist;
        in >> qtdAlbuns;
        in.ignore();
        for (size_t i = 0; i < qtdAlbuns; ++i) {
            Album a;
            getline(in, a.titulo);
            in >> a.nota;

            // Validação da nota antes de adicionar ao perfil
            if (a.nota < 1 || a.nota > 5) {
                cout << "Nota inválida no álbum '" << a.titulo << "', ajustando para 1.\n";
                a.nota = 1;  // Ou você pode ignorar o álbum, se preferir
            }

            in.ignore();
            u.albuns.push_back(a);
        }
        in >> qtdWatchlist;
        in.ignore();
        for (size_t i = 0; i < qtdWatchlist; ++i) {
            string w;
            getline(in, w);
            u.watchlist.push_back(w);
        }
        return true;
    }
    return false;
}

void alterarCores() {
    cout << "Escolha a cor dos quadrados dos Álbuns e Watchlist (vermelho, azul, verde, amarelo, roxo, ciano): ";
    string corQ;
    cin >> corQ;
    corQuadrados = corParaCodigo(corQ);

    cout << "Escolha a cor do menu (vermelho, azul, verde, amarelo, roxo, ciano): ";
    string corM;
    cin >> corM;
    corMenu = corParaCodigo(corM);
}

void menuUsuario() {
    Usuario u;
    carregarPerfil(u);
    int opcao;

    do {
        cout << corMenu << "╔══════════════════════════════════════════════╗\n";
        cout << "║              MENU DO PERFIL                  ║\n";
        cout << "╠══════════════════════════════════════════════╣\n";
        cout << "║ \033[1;32m1\033[0m" << corMenu << " - Criar/Editar Perfil                      ║\n";
        cout << "║ \033[1;32m2\033[0m" << corMenu << " - Adicionar Álbum                          ║\n";
        cout << "║ \033[1;32m3\033[0m" << corMenu << " - Ver Perfil e Álbuns                      ║\n";
        cout << "║ \033[1;32m4\033[0m" << corMenu << " - Adicionar à Watchlist                    ║\n";
        cout << "║ \033[1;32m5\033[0m" << corMenu << " - Marcar álbum da Watchlist como avaliado  ║\n";
        cout << "║ \033[1;32m6\033[0m" << corMenu << " - Remover álbum dos favoritos              ║\n";
        cout << "║ \033[1;32m7\033[0m" << corMenu << " - Alterar Cores dos Quadrados              ║\n";
        cout << "║ \033[1;32m8\033[0m" << corMenu << " - Sair                                     ║\n";
        cout << "╚══════════════════════════════════════════════╝" << reset << "\n";
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
                cout << "Título: ";
                getline(cin, a.titulo);
                do {
                    cout << "Nota (1 a 5): ";
                    cin >> a.nota;
                } while (a.nota < 1 || a.nota > 5);
                cin.ignore();
                u.albuns.push_back(a);
                salvarPerfil(u);
                break;
            }
            case 3:
                cout << "\033[2J\033[H";
                u.mostrarPerfil();
                cout << "Pressione Enter...\n";
                cin.ignore();
                break;
            case 4: {
                string nome;
                cout << "Título para Watchlist: ";
                getline(cin, nome);
                u.watchlist.push_back(nome);
                salvarPerfil(u);
                break;
            }
            case 5: {
                if (u.watchlist.empty()) {
                    cout << "Watchlist vazia.\n";
                    break;
                }
                for (size_t i = 0; i < u.watchlist.size(); ++i)
                    cout << i + 1 << " - " << u.watchlist[i] << endl;
                cout << "Escolha nº do álbum para avaliar (0 cancela): ";
                int esc;
                cin >> esc;
                cin.ignore();
                if (esc > 0 && esc <= (int)u.watchlist.size()) {
                    Album a;
                    a.titulo = u.watchlist[esc - 1];
                    do {
                        cout << "Nota para '" << a.titulo << "' (1 a 5): ";
                        cin >> a.nota;
                    } while (a.nota < 1 || a.nota > 5);
                    cin.ignore();
                    u.albuns.push_back(a);
                    u.watchlist.erase(u.watchlist.begin() + esc - 1);
                    salvarPerfil(u);
                }
                break;
            }
            case 6:
                if (u.albuns.empty()) {
                    cout << "Sem álbuns para remover.\n";
                    break;
                }
                for (size_t i = 0; i < u.albuns.size(); ++i)
                    cout << i + 1 << " - " << u.albuns[i].titulo << " (" << u.albuns[i].nota << ")\n";
                cout << "Digite nº do álbum para remover (0 cancela): ";
                int rem;
                cin >> rem;
                cin.ignore();
                if (rem > 0 && rem <= (int)u.albuns.size()) {
                    cout << "Álbum '" << u.albuns[rem - 1].titulo << "' removido.\n";
                    u.albuns.erase(u.albuns.begin() + rem - 1);
                    salvarPerfil(u);
                }
                break;
            case 7:
                alterarCores();
                break;
            case 8:
                cout << "Até mais!\n";
                break;
            default:
                cout << "Opção inválida.\n";
        }
    } while (opcao != 8);
}

int main() {
    cout << "\033[1;35m";
    cout << "============================================\n";
    cout << "|                                          |\n";
    cout << "|     BEM-VINDO AO SEU LETTERBOXD MUSICAL  |\n";
    cout << "|                                          |\n";
    cout << "============================================\n";
    cout << reset;
    this_thread::sleep_for(chrono::seconds(2));
    cout << "\033[2J\033[H";
    menuUsuario();
    return 0;
}
