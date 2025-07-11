#include "FilaDeInteresse.h"
#include "Perfil.h"
#include <iostream>
#include <algorithm>

void FilaDeInteresses::ListarWatchlistPorLinhaDentroDoQuadro(int porLinha, int largura) const
{
    const int linhasPorAlbum = 8;
    const int larguraAlbum = 20;

    int totalAlbuns = (int)filaDeAlbum.size();
    int totalLinhas = (totalAlbuns + porLinha - 1) / porLinha;
    int linhasParaImprimir = std::max(1, totalLinhas);

    for (int blocoLinha = 0; blocoLinha < linhasParaImprimir; ++blocoLinha)
    {
        for (int linhaInterna = 0; linhaInterna < linhasPorAlbum; ++linhaInterna)
        {
            int ocupado = 0;

            for (int coluna = 0; coluna < porLinha; ++coluna)
            {
                int idx = blocoLinha * porLinha + coluna;

                if (idx < totalAlbuns)
                {
                    std::string titulo = filaDeAlbum[idx].GetTitulo();
                    std::string artista = filaDeAlbum[idx].GetAutor();
                    int estrelasInt = std::max(0, std::min(5, (int)filaDeAlbum[idx].GetNota()));

                    std::string estrelas;
                    for (int i = 0; i < estrelasInt; ++i)
                        estrelas += "★";
                    estrelas.append(5 - estrelasInt, ' ');

                    if ((int)titulo.size() > 15) titulo = titulo.substr(0, 15);
                    if ((int)artista.size() > 15) artista = artista.substr(0, 15);

                    int espacoTitulo = std::max(0, larguraAlbum - 9 - (int)titulo.size());
                    int espacoArtista = std::max(0, larguraAlbum - 10 - (int)artista.size());
                    int espacoNota = std::max(0, larguraAlbum - 7 - 5);

                    switch (linhaInterna)
                    {
                        case 0: std::cout << corQuadrados << "  ▄▄████████▄▄  " << reset; break;
                        case 1: std::cout << corQuadrados << "  █  A L B U M  █  " << reset; break;
                        case 2: std::cout << corQuadrados << "  ▀▀████████▀▀  " << reset; break;
                        case 3: std::cout << corQuadrados << "  ■▲■▲■▲■▲■▲■▲■▲  " << reset; break;
                        case 4:
                            std::cout << corQuadrados << "  Título: " << "\033[1;32m" << titulo
                                      << std::string(espacoTitulo, ' ') << reset;
                            break;
                        case 5:
                            std::cout << corQuadrados << "  Artista: " << "\033[1;34m" << artista
                                      << std::string(espacoArtista, ' ') << reset;
                            break;
                        case 6:
                            std::cout << corQuadrados << "  Nota: " << "\033[1;33m" << estrelas
                                      << std::string(espacoNota, ' ') << reset;
                            break;
                        case 7:
                            std::cout << std::string(larguraAlbum, ' ');
                            break;
                    }

                    ocupado += larguraAlbum;
                    std::cout << "  ";
                    ocupado += 2;
                }
                else
                {
                    std::cout << std::string(larguraAlbum, ' ') << "  ";
                    ocupado += larguraAlbum + 2;
                }
            }

            std::cout << std::string(std::max(0, largura - ocupado), ' ') << "\n";
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
