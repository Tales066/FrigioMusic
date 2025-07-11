#include "AlbunsOuvidos.h"
#include "Perfil.h"
#include "Estrela.h"
#include <iostream>
#include <algorithm>

void AlbunsOuvidos::ListarAlbunsPorLinhaDentroDoQuadro(int porLinha, int largura) const
{
    const int linhasPorAlbum = 8;   // linhas que compõem cada álbum
    const int larguraAlbum = 20;    // largura fixa de cada álbum

    int totalAlbuns = (int)albunsOuvidos.size();
    int totalLinhas = (totalAlbuns + porLinha - 1) / porLinha;
    int linhasParaImprimir = std::max(2, totalLinhas);

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
                    std::string titulo = albunsOuvidos[idx].GetTitulo();
                    std::string artista = albunsOuvidos[idx].GetAutor();
                    int estrelasInt = std::max(0, std::min(5, (int)albunsOuvidos[idx].GetNota()));

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


