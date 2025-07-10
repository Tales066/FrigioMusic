#include "Banner.h"
#include "Menu.h"
#include "Plataforma.h"
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <string>

int main()
{
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    bool borderStars[71 - 4] = { false };
    std::string textoCompleto = "O seu app de musica";

    // anima a digitação
    for(size_t i = 1; i <= textoCompleto.size(); ++i)
    {
        limparTela();
        for(bool& b : borderStars) b = (std::rand() % 10) < 3;
        Banner::printBanner(textoCompleto.substr(0, i), false, borderStars);
        std::this_thread::sleep_for(std::chrono::milliseconds(150));
    }

    // piscando
    for(int i = 0; i < 10; ++i)
    {
        limparTela();
        for(bool& b : borderStars) b = (std::rand() % 10) < 3;
        Banner::printBanner(textoCompleto, i % 2 == 0, borderStars);
        std::this_thread::sleep_for(std::chrono::milliseconds(400));
    }

    // “apagando” o texto
    for(size_t i = textoCompleto.size(); i > 0; --i)
    {
        limparTela();
        for(bool& b : borderStars) b = (std::rand() % 10) < 3;
        Banner::printBanner(textoCompleto.substr(0, i - 1), false, borderStars);
        std::this_thread::sleep_for(std::chrono::milliseconds(150));
    }

    // chama o menu de usuário
    Menu m;
    m.menuUsuario();

    return 0;
}
