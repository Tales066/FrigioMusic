#include "banner.h"

#include <iostream>

const int WIDTH = 71;

void Banner::printLineWithStars(bool stars[])
{
    std::cout << "     *";
    for(int i = 0; i < WIDTH - 4; i++)
    {
        if(stars[i])
            std::cout << "*";
        else
            std::cout << " ";
    }
    std::cout << "*" << std::endl;
}

void Banner::printBanner(const std::string& texto, bool comEstrela, bool borderStars[])
{
    std::cout << "\033[1;36m";

    std::cout << "     ***********************************************************************" << std::endl;
    printLineWithStars(borderStars);

    std::cout << "     *  ______        _         _                                 _        *" << std::endl;
    std::cout << "     * |  ____|      (_)       (_)                               (_)       *" << std::endl;
    std::cout << "     * | |__    _ __  _   __ _  _   ___    _ __ ___   _   _  ___  _   ___  *" << std::endl;
    std::cout << "     * |  __|  | '__|| | / _` || | / _ \\  | '_ ` _ \\ | | | |/ __|| | / __| *" << std::endl;
    std::cout << "     * | |     | |   | || (_| || || (_) | | | | | | || |_| |\\__ \\| || (__  *" << std::endl;
    std::cout << "     * |_|     |_|   |_| \\__, ||_| \\___/  |_| |_| |_| \\__,_||___/|_| \\___| *" << std::endl;
    std::cout << "     *                   __/ |                                            *" << std::endl;
    std::cout << "     *                  |___/                                             *" << std::endl;
    std::cout << "     *                                                                     *" << std::endl;

    int larguraUtil = 65;
    int espacosAntes = (larguraUtil - (int)texto.size()) / 2;

    std::string linhaTexto = std::string(espacosAntes, ' ') + texto;
    if(comEstrela) linhaTexto += "  *";

    while((int)linhaTexto.size() < larguraUtil)
    {
        linhaTexto += " ";
    }

    std::cout << "     *" << linhaTexto << "*" << std::endl;

    printLineWithStars(borderStars);
    std::cout << "     ***********************************************************************" << std::endl;
    std::cout << "\033[0m";
}

