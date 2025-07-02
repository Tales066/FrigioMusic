#include "AlbunsOuvidos.h"
#include "Estrelas.h"

void AlbunsOuvidos:: listarAlbunsPorLinha(int porLinha) const {
    for(size_t i = 0; i < albunsOuvidos.size(); i += porLinha)
    {
        for(size_t j = i; j < i + porLinha && j < albunsOuvidos.size(); ++j)
            cout << "\033[1;31m┌───────┐ \033[0m";
        cout << "\n";

        for(size_t j = i; j < i + porLinha && j < albunsOuvidos.size(); ++j)
            cout << "\033[1;31m│\033[1;36m _|#|_ \033[1;31m│ \033[0m";
        cout << "\n";

        for(size_t j = i; j < i + porLinha && j < albunsOuvidos.size(); ++j)
            cout << "\033[1;31m│\033[1;36m |(O)| \033[1;31m│ \033[0m";
        cout << "\n";

        for(size_t j = i; j < i + porLinha && j < albunsOuvidos.size(); ++j)
            cout << "\033[1;31m│\033[1;36m ----- \033[1;31m│ \033[0m";
        cout << "\n";

        for(size_t j = i; j < i + porLinha && j < albunsOuvidos.size(); ++j)
        {
            string nome = albunsOuvidos[j].GetTitulo();
            nome = nome.substr(0, min<size_t>(7, nome.length()));
            nome.append(7 - nome.length(), ' ');
            cout << "\033[1;31m│\033[1;32m" << nome << "\033[1;31m│ \033[0m";
        }
        cout << "\n";

        for(size_t j = i; j < i + porLinha && j < albunsOuvidos.size(); ++j)
        {
            string estrelas = Estrelas::GerarEstrelas(albunsOuvidos[j].GetNota());
            estrelas = estrelas.substr(0, min<size_t>(5, estrelas.length()));
            estrelas.append(5 - estrelas.length(), ' ');
            cout << "\033[1;31m│ \033[1;33m" << estrelas << "\033[1;31m │ \033[0m";
        }
        cout << "\n";

        for(size_t j = i; j < i + porLinha && j < albunsOuvidos.size(); ++j)
            cout << "\033[1;31m└───────┘ \033[0m";
        cout << "\n";
    }
}
