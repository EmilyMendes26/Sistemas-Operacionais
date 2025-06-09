#ifndef MEMORIA_HPP
#define MEMORIA_HPP

#include"Processo.hpp"
#include"ProcessoProd.hpp"
#include"ProcessoCons.hpp"
#include "includes.hpp"

class Memoria{
    private:
    bool livre;

    protected:
        vector<Processo*> tabelaDeProcessos;

    public:
    Memoria();
    void setEstado(bool e);
    bool getEstado();
    int getTamanhoTabela();
    vector<Processo*>& getTabelaProcesso();
};

#endif