#include "perfil.h"
#include "cores.h"
#include <iostream>
#include <fstream>

void Usuario::mostrarPerfil() const {
    const int largura = 52;

    std::cout << "\n" << corQuadrados;

    // Linha superior
    std::cout << "╔";
    for (int i = 0; i < largura; ++i)
        std::cout << "═";
    std::cout << "╗\n";

    // Título centralizado
    std::cout << "║" << std::string((largura - 17) / 2, ' ') << "PERFIL DO USUARIO"
              << std::string(largura - 17 - (largura - 17) / 2, ' ') << "║\n";

              
    // Linha separadora
    std::cout << "╠";
    for (int i = 0; i < largura; ++i)
        std::cout << "═";
    std::cout << "╣\n";

    // Nome centralizado
    std::cout << "║" << std::string((largura - nome.length()) / 2, ' ') << nome
              << std::string(largura - nome.length() - (largura - nome.length()) / 2, ' ') << "║\n";

    // Linha separadora
    std::cout << "╠";
    for (int i = 0; i < largura; ++i)
        std::cout << "═";
    std::cout << "╣\n";

    if (albuns.empty()) {
        std::cout << "║ Nenhum album avaliado." << std::string(largura - 23, ' ') << "║\n";
    } else {
        std::cout << "║ Meus albuns avaliados:" << std::string(largura - 22, ' ') << "║\n";
        listarAlbunsPorLinhaDentroDoQuadro(3, largura);
    }

    std::cout << "╠";
    for (int i = 0; i < largura; ++i)
        std::cout << "═";
    std::cout << "╣\n";

    if (watchlist.empty()) {
        std::cout << "║ Nenhuma Watchlist cadastrada." << std::string(largura - 29, ' ') << "║\n";
    } else {
        std::cout << "║ Minha Watchlist:" << std::string(largura - 17, ' ') << "║\n";
        listarWatchlistPorLinhaDentroDoQuadro(3, largura);
    }

    std::cout << "╚";
    for (int i = 0; i < largura; ++i)
        std::cout << "═";
    std::cout << "╝" << reset << "\n";
}

void Usuario::listarAlbunsPorLinhaDentroDoQuadro(int porLinha, int largura) const {
    for (size_t i = 0; i < albuns.size(); i += porLinha) {
        for (int linha = 0; linha < 6; linha++) {
            std::cout << "║ ";
            int ocupado = 0;
            for (size_t j = i; j < i + porLinha && j < albuns.size(); ++j) {
                if (linha == 0) std::cout << corQuadrados << "┌───────┐ " << reset;
                if (linha == 1) std::cout << corQuadrados << "│" << "\033[1;36m _|#|_ " << corQuadrados << "│ " << reset;
                if (linha == 2) std::cout << corQuadrados << "│" << "\033[1;36m |(O)| " << corQuadrados << "│ " << reset;
                if (linha == 3) std::cout << corQuadrados << "│" << "\033[1;36m ----- " << corQuadrados << "│ " << reset;
                if (linha == 4) {
                    std::string nome = albuns[j].titulo.substr(0, 7);
                    nome.append(7 - nome.length(), ' ');
                    std::cout << corQuadrados << "│" << "\033[1;32m" << nome << corQuadrados << "│ " << reset;
                }
                if (linha == 5) {
                    int estrelas = std::max(0, std::min(5, (int)albuns[j].nota));
                    std::string est(estrelas, '*');
                    est.append(5 - estrelas, ' ');
                    std::cout << corQuadrados << "│ " << "\033[1;33m" << est << corQuadrados << " │ " << reset;
                }
                ocupado += 10;
            }
            std::cout << std::string(largura - ocupado, ' ') << "║\n";
        }
    }
}

void Usuario::listarWatchlistPorLinhaDentroDoQuadro(int porLinha, int largura) const {
    for (size_t i = 0; i < watchlist.size(); i += porLinha) {
        for (int linha = 0; linha < 5; linha++) {
            std::cout << "║ ";
            int ocupado = 0;
            for (size_t j = i; j < i + porLinha && j < watchlist.size(); ++j) {
                if (linha == 0) std::cout << corQuadrados << "┌───────┐ " << reset;
                if (linha == 1) std::cout << corQuadrados << "│" << "\033[1;36m _|#|_ " << corQuadrados << "│ " << reset;
                if (linha == 2) std::cout << corQuadrados << "│" << "\033[1;36m |(O)| " << corQuadrados << "│ " << reset;
                if (linha == 3) std::cout << corQuadrados << "│" << "\033[1;36m ----- " << corQuadrados << "│ " << reset;
                if (linha == 4) {
                    std::string nome = watchlist[j].substr(0, 7);
                    nome.append(7 - nome.length(), ' ');
                    std::cout << corQuadrados << "│" << "\033[1;32m" << nome << corQuadrados << "│ " << reset;
                }
                ocupado += 10;
            }
            std::cout << std::string(largura - ocupado, ' ') << "║\n";
        }
    }
}

void salvarPerfil(const Usuario& u) {
    std::ofstream out("perfil.txt");
    if (out.is_open()) {
        out << u.nome << "\n" << u.albuns.size() << "\n";
        for (const auto& a : u.albuns) out << a.titulo << "\n" << a.nota << "\n";
        out << u.watchlist.size() << "\n";
        for (const auto& w : u.watchlist) out << w << "\n";
    }
}

bool carregarPerfil(Usuario& u) {
    std::ifstream in("perfil.txt");
    if (in.is_open()) {
        std::getline(in, u.nome);
        size_t qtd;
        in >> qtd; in.ignore();
        for (size_t i = 0; i < qtd; ++i) {
            Album a;
            std::getline(in, a.titulo);
            in >> a.nota;
            in.ignore();
            u.albuns.push_back(a);
        }
        in >> qtd; in.ignore();
        for (size_t i = 0; i < qtd; ++i) {
            std::string w;
            std::getline(in, w);
            u.watchlist.push_back(w);
        }
        return true;
    }
    return false;
}
