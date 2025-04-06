#ifndef KERNEL_HPP
#define KERNEL_HPP

#include"Processo.hpp"
#include"ProcessoProd.hpp"
#include"ProcessoCons.hpp"

class Kernel{
    protected:
        vector<Processo*> tabelaDeProcessos;

    public:
        Kernel();

        void adicionaProcesso(Processo* processo);
        void listarProcessos();
        void criaProcesso();
        Processo* buscaProcesso(int id);
};

#endif