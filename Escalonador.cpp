#include "includes.hpp"
#include "Escalonador.hpp"

Escalonador::Escalonador(Kernel* k)
{
    this->kernel = k;
    cout << "Escalonador criado" << endl;
}

void Escalonador::adicionaProcesso()
{
    Processo* processo = kernel->getProcesso("espera");

    if (processo != nullptr) {
        fila.push_back(processo);
    }
}

void Escalonador::iniciaProcesso()
{
    for (Processo* aux : fila) {
        if (aux->getStatus() == "espera"){
            aux->setStatus("iniciado");

            cout << "Processo ID: " << aux->getID() << " Iniciado";
        }
    }
}

void Escalonador::terminaProcesso()
{    
    for (Processo* aux : fila) {
    if (aux->getStatus() == "iniciado"){
        aux->setStatus("espera");

        cout << "Processo ID: " << aux->getID() << " terminado" << endl;
    }
}
}

void Escalonador::listaProcesso()
{    
    for (Processo* aux : fila) {
        cout << "Processo ID: " << aux->getID() << " na fila de espera" << endl;
    }
}

