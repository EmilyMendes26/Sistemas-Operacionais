#include "includes.hpp"
#include "Memoria.hpp"

Memoria::Memoria()
{
    this->recurso_1 = true;
    this->recurso_2 = true;
}

void Memoria::setRecurso_1(bool r1)
{
    this->recurso_1 = r1;
}

void Memoria::setRecurso_2(bool r2)
{
    this->recurso_2 = r2;
}

bool Memoria::getRecurso_2()
{
    return this->recurso_2;
}

bool Memoria::getRecurso_1()
{
    return this->recurso_1;
}

int Memoria::getTamanhoTabela()
{
    return this->tabelaDeProcessos.size();
}

vector<Processo *>& Memoria::getTabelaProcesso()
{
    return this->tabelaDeProcessos;
}
