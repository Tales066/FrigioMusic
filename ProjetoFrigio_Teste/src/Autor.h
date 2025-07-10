#pragma once
#include <string>
#include <vector>

class Album;           
class Autor
{
    public:
    std::string nome;
    std::vector<Album*> albuns;   
};