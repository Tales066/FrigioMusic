#include "CorDaLinha.h"
static std::string Obter(const std::string& cor)
{
    if(cor == "vermelho") return "\033[1;31m";
    if(cor == "verde")    return "\033[1;32m";
    if(cor == "amarelo")  return "\033[1;33m";
    if(cor == "azul")     return "\033[1;34m";
    if(cor == "roxo")     return "\033[1;35m";
    if(cor == "ciano")    return "\033[1;36m";
    if(cor == "reset")    return "\033[0m";//cor padrão
    return "";
}
