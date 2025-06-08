#ifndef KERNEL_HPP
#define KERNEL_HPP

#include"Processo.hpp"
#include"ProcessoProd.hpp"
#include"ProcessoCons.hpp"
#include "Memoria.hpp"

class Kernel{
    private:
        Memoria* memoria;

    public:
        Kernel(Memoria* m);

        void adicionaProcesso(Processo* processo);
        void listarProcessos();
        void criaProcesso(int qp, int qc);
        Processo* getProcesso(int id);
};

#endif