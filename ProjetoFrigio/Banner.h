#pragma once
#include "cores.h"
#include "plataforma.h"
#include <string>
class Banner
{
    public:
        static void printLineWithStars(bool stars[]);
        static void printBanner(const std::string& texto, bool comEstrela, bool borderStars[]);
};
