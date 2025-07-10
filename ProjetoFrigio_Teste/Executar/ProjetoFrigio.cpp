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

    limparTela();
    Banner::printBannerAnimado(); // Chama a versão animada

    std::this_thread::sleep_for(std::chrono::seconds(1)); // Pausa opcional

    Menu m;
    m.menuUsuario();

    return 0;
}
