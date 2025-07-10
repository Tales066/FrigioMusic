#pragma once
#include "Cores.h"
#include "Plataforma.h"
#include <string>

class Banner
{
    public:
        static void printLineWithStars(bool stars[]);
        static void printBanner(const std::string& texto, bool comEstrela, bool borderStars[]);
};
