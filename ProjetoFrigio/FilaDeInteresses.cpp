#include "FilaDeInteresses.h"
void FilaDeInteresses:: ExibirFilaDeInteresses(int porLinha)const
{

    for(size_t i = 0; i < filaDeAlbum.size(); i += porLinha)
    {
        for(size_t j = i; j < i + porLinha && j < filaDeAlbum.size(); ++j)
            cout << "\033[1;35m????????? \033[0m";
        cout << "\n";

        for(size_t j = i; j < i + porLinha && j < filaDeAlbum.size(); ++j)
            cout << "\033[1;35m?\033[1;36m _|#|_ \033[1;35m? \033[0m";
        cout << "\n";

        for(size_t j = i; j < i + porLinha && j < filaDeAlbum.size(); ++j)
            cout << "\033[1;35m?\033[1;36m |(O)| \033[1;35m? \033[0m";
        cout << "\n";

        for(size_t j = i; j < i + porLinha && j < filaDeAlbum.size(); ++j)
            cout << "\033[1;35m?\033[1;36m ----- \033[1;35m? \033[0m";
        cout << "\n";

        for(size_t j = i; j < i + porLinha && j < filaDeAlbum.size(); ++j)
        {
            string nome = filaDeAlbum[j].GetTitulo();
            nome = nome.substr(0, min<size_t>(7, nome.length()));
            nome.append(7 - nome.length(), ' ');
            cout << "\033[1;35m?\033[1;32m" << nome << "\033[1;35m? \033[0m";
        }
        cout << "\n";

        for(size_t j = i; j < i + porLinha && j < filaDeAlbum.size(); ++j)
            cout << "\033[1;35m????????? \033[0m";
        cout << "\n";
    }
}
void FilaDeInteresses::Adicionar(const Album& addAlbum)
{

    filaDeAlbum.push_back(addAlbum);

}
