#include "banner.h"
#include "menu.h"
#include "plataforma.h"
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <string>

int main() {
    srand(time(nullptr));
    bool borderStars[71 - 4] = {false};
    std::string textoCompleto = "O seu app de musica";

    for (size_t i = 1; i <= textoCompleto.size(); i++) {
        limparTela();
        for (int j = 0; j < 71 - 4; j++) {
            borderStars[j] = (rand() % 10) < 3;
        }
        printBanner(textoCompleto.substr(0, i), false, borderStars);
        std::this_thread::sleep_for(std::chrono::milliseconds(150));
    }

    for (int i = 0; i < 10; i++) {
        limparTela();
        for (int j = 0; j < 71 - 4; j++) {
            borderStars[j] = (rand() % 10) < 3;
        }
        printBanner(textoCompleto, i % 2 == 0, borderStars);
        std::this_thread::sleep_for(std::chrono::milliseconds(400));
    }

    for (size_t i = textoCompleto.size(); i > 0; i--) {
        limparTela();
        for (int j = 0; j < 71 - 4; j++) {
            borderStars[j] = (rand() % 10) < 3;
        }
        printBanner(textoCompleto.substr(0, i - 1), false, borderStars);
        std::this_thread::sleep_for(std::chrono::milliseconds(150));
    }

    // Após o banner, ele chama o menu do usuário. 
    menuUsuario();

    return 0;
}
