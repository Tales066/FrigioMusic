#include "Animacao.h"
#include "Plataforma.h"
#include <iostream>
#include <thread>
#include <chrono>


void printColor(const std::string& text, int colorCode) {
    std::cout << "\033[1;" << colorCode << "m" << text << "\033[0m";
}

void printDigitando(const std::string& text, int delayMs = 50) {
    for (char c : text) {
        std::cout << c << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(delayMs));
    }
    std::cout << std::endl;
}

void mostrarAnimacaoAranha() {
    std::string arte = R"(░░░░░░░░░░░║
░░▄█▀▄░░░░░║░░░░░░▄▀▄▄
░░░░░░▀▄░░░║░░░░▄▀
░▄▄▄░░░░█▄▄▄▄▄▄█░░░░▄▄▄
▀░░░▀█░█▀░░▐▌░░▀█░█▀░░░▀
░░░░░░██░░▀▐▌▀░░██
░▄█▀▀▀████████████▀▀▀█
█░░░░░░██████████░░░░░▀▄
█▄░░░█▀░░▀▀▀▀▀▀░░▀█░░░▄█
░▀█░░░█░░░░░░░░░░█░░░█▀)";

    std::string frase = "Até a sua próxima avaliação";

    int cores[] = {31, 33, 37}; // vermelho, amarelo, branco

    for (int ciclo = 0; ciclo < 3; ++ciclo) {
        for (int cor : cores) {
            limparTela();
            printColor(arte + "\n\n", cor);
            printDigitando(frase, 50);
            std::this_thread::sleep_for(std::chrono::milliseconds(400));
        }
    }
    limparTela();
}
