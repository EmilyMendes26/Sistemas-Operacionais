#include "Memoria.hpp"

Memoria::Memoria()
{
    this->livre = true;
}

void Memoria::setEstado(bool e)
{
    this->livre = e;
}

bool Memoria::getEstado()
{
    return this->livre;
}

int Memoria::getTamanhoTabela()
{
    return this->tabelaDeProcessos.size();
}

vector<Processo *>& Memoria::getTabelaProcesso()
{
    return this->tabelaDeProcessos;
}
