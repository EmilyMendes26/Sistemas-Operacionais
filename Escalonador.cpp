#include "includes.hpp"
#include "Escalonador.hpp"

Escalonador::Escalonador(Kernel* k)
{
    this->kernel = k;
    cout << "Escalonador criado" << endl;
}

void Escalonador::adicionaProcesso()
{
    int limite = kernel->getTamanhoTabela();

    for (int i = 0; i <= limite; i++){
        Processo* processo = kernel->getProcesso(i);
        if (processo != nullptr){
            if(processo->getStatus() == "espera" || processo->getStatus() == "iniciado"){
                fila.push_back(processo);
            }
        }
    }
}

void Escalonador::iniciaProcesso()
{
    for (Processo* aux : fila) {
        if (aux->getStatus() == "espera"){
            aux->setStatus("iniciado");

            cout << "Processo ID: " << aux->getID() << " Iniciado" << endl;
            fila.clear();
            adicionaProcesso();
        }
    }
}

void Escalonador::iniciaProcessoId(int id)
{
    for (Processo* aux : fila) {
        if (aux->getID() == id){
            aux->setStatus("iniciado");

            cout << "Processo ID: " << aux->getID() << " Iniciado" << endl;
            fila.clear();
            adicionaProcesso();
        }
    }
}

void Escalonador::terminaProcesso()
{    
    for (Processo* aux : fila) {
    if (aux->getStatus() == "iniciado"){
        aux->setStatus("espera");

        cout << "Processo ID: " << aux->getID() << " terminado" << endl;
        fila.clear();
        adicionaProcesso();
    }
}
}

void Escalonador::terminaProcessoId(int id)
{    
    for (Processo* aux : fila) {
    if (aux->getID() == id){
        aux->setStatus("espera");

        cout << "Processo ID: " << aux->getID() << " terminado" << endl;
        fila.clear();
        adicionaProcesso();
    }
}
}

void Escalonador::listaProcesso()
{    
    for (Processo* aux : fila) {
        cout << "Processo ID: " << aux->getID() << " status:" << aux->getStatus() << endl;
    }
}

