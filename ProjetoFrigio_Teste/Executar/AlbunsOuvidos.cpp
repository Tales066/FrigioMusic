#include "AlbunsOuvidos.h"
#include "Perfil.h"
#include "Estrela.h"
#include <iostream>
#include <algorithm>

void AlbunsOuvidos::ListarAlbunsPorLinhaDentroDoQuadro(int porLinha, int largura) const
{
    for (size_t i = 0; i < albunsOuvidos.size(); i += porLinha)
    {
        for (int linha = 0; linha < 7; linha++) // Agora são 7 linhas
        {
            std::cout << "║ ";
            int ocupado = 0;

            for (size_t j = i; j < i + porLinha && j < albunsOuvidos.size(); ++j)
            {
                if (linha == 0)
                    std::cout << corQuadrados << "┌───────┐ " << reset;

                else if (linha == 1)
                    std::cout << corQuadrados << "│" << "\033[1;36m _|#|_ " << corQuadrados << "│ " << reset;

                else if (linha == 2)
                    std::cout << corQuadrados << "│" << "\033[1;36m |(O)| " << corQuadrados << "│ " << reset;

                else if (linha == 3)
                    std::cout << corQuadrados << "│" << "\033[1;36m ----- " << corQuadrados << "│ " << reset;

                else if (linha == 4)
                {
                    std::string nome = albunsOuvidos[j].GetTitulo().substr(0, 7);
                    nome.append(7 - nome.length(), ' ');
                    std::cout << corQuadrados << "│" << "\033[1;32m" << nome << corQuadrados << "│ " << reset;
                }

                else if (linha == 5)
                {
                    std::string artista = albunsOuvidos[j].GetAutor().substr(0, 7);
                    artista.append(7 - artista.length(), ' ');
                    std::cout << corQuadrados << "│" << "\033[1;34m" << artista << corQuadrados << "│ " << reset;
                }

                else if (linha == 6)
                {
                    int estrelas = std::max(0, std::min(5, (int)albunsOuvidos[j].GetNota()));
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
