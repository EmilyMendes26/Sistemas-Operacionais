#include "includes.hpp"
#include "Processo.hpp"
#include "Kernel.hpp"
#include "Memoria.hpp"
#include "Processador.hpp"

class Escalonador{
    private:
    Kernel* kernel; //agregação
    Memoria* memoria;
    Processador* processador;
    vector<Processo*> fila;

    public:
    Escalonador(Kernel* k, Memoria* m, Processador* p);
    void adicionaProcesso();
    void iniciaProcesso();
    void iniciaProcessoId(int id);
    void terminaProcesso();
    void terminaProcessoId(int id);
    void listaProcesso();
    void wake_sleep();
    void deadlock();
};