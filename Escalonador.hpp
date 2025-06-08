#include "includes.hpp"
#include "Processo.hpp"
#include "Kernel.hpp"
#include "Memoria.hpp"

class Escalonador{
    private:
    Kernel* kernel; //agregação
    Memoria* memoria;
    vector<Processo*> fila;

    public:
    Escalonador(Kernel* k, Memoria* m);
    void adicionaProcesso();
    void iniciaProcesso();
    void iniciaProcessoId(int id);
    void terminaProcesso();
    void terminaProcessoId(int id);
    void listaProcesso();
    void wake_sleep();
    void deadlock();
};