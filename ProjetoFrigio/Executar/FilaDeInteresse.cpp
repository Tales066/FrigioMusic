#include "FilaDeInteresse.h"
#include "Perfil.h"

void FilaDeInteresses:: ListarWatchlistPorLinhaDentroDoQuadro(int porLinha, int largura) const
{
    for(size_t i = 0; i < filaDeAlbum.size(); i += porLinha)
    {
        for(int linha = 0; linha < 5; linha++)
        {
            std::cout << "║ ";
            int ocupado = 0;
            for(size_t j = i; j < i + porLinha && j < filaDeAlbum.size(); ++j)
            {
                if(linha == 0) std::cout << corQuadrados << "┌───────┐ " << reset;
                if(linha == 1) std::cout << corQuadrados << "│" << "\033[1;36m _|#|_ " << corQuadrados << "│ " << reset;
                if(linha == 2) std::cout << corQuadrados << "│" << "\033[1;36m |(O)| " << corQuadrados << "│ " << reset;
                if(linha == 3) std::cout << corQuadrados << "│" << "\033[1;36m ----- " << corQuadrados << "│ " << reset;
                if(linha == 4)
                {
                    std::string nome = filaDeAlbum[j].GetTitulo().substr(0, 7);
                    nome.append(7 - nome.length(), ' ');
                    std::cout << corQuadrados << "│" << "\033[1;32m" << nome << corQuadrados << "│ " << reset;
                }
                ocupado += 10;
            }
            std::cout << std::string(largura - ocupado, ' ') << "║\n";
        }
    }

}

void FilaDeInteresses::Adicionar(const Album& addAlbum)
{

    filaDeAlbum.push_back(addAlbum);

}
void FilaDeInteresses::Remover(const std::string& titulo)
{
    for(auto it = filaDeAlbum.begin(); it != filaDeAlbum.end(); ++it)
    {
        if(it->GetTitulo() == titulo)
        {
            filaDeAlbum.erase(it);
            std::cout << titulo << " Removido com sucesso";
            return;
        }
    }
    std::cout << titulo << " Não encontrado, verifique se você escreveu corretamente o nome do álbum.";
}

