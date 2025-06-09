#include "Processador.hpp"

Processador::Processador()
{
    this->nucleo1 = true;
    this->nucleo2 = true;
}

void Processador::setNucleo1(bool n)
{
    this->nucleo1 = n;
}

void Processador::setNucleo2(bool n)
{
    this->nucleo2 = n;
}

bool Processador::getNucleo1()
{
    return this->nucleo1;
}

bool Processador::getNucleo2()
{
    return this->nucleo2;
}
