#include "includes.hpp"
#include "Processo.hpp"
#include "kernel.hpp"

class Escalonador{
    private:
    Kernel* kernel; //agregação
    vector<Processo*> fila;

    public:
    Escalonador(Kernel* k);
    void adicionaProcesso();
    void iniciaProcesso();
    void terminaProcesso();
    void listaProcesso();
};