#include "includes.hpp"
#include "Escalonador.hpp"
#include "Memoria.hpp"

Escalonador::Escalonador(Kernel* k, Memoria* m)
{
    this->kernel = k;
    this->memoria = m;
    cout << "Escalonador criado" << endl;
}

void Escalonador::adicionaProcesso()
{
    int limite = memoria->getTamanhoTabela();

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

void Escalonador::wake_sleep()
{
    #define Fila_buffer 15
    int buffer = 0;
    int produto;
    ProcessoProd p(0);
    ProcessoCons c(1);
    while(true){
    if (buffer == Fila_buffer){
    p.setWake(false);
    } else {
    p.setWake(true);
    }
    if (buffer >= 1){
    c.setWake(true);
    } else {
    c.setWake(false);
    }
    if (buffer == 0){
    c.setWake(false);
    }
    if (buffer == (Fila_buffer - 1)){
    c.setWake(true);
    }
    if (p.getWake()){
    cout << "Produtor acordado" << endl;
    produto = p.produz();
    c.recebe_mensagem(p.manda_mensagem());
    buffer += 1;
    cout << "buffer: " << buffer << endl;
    sleep(5);
    } else {
    cout << "Produtor dormindo" << endl;
    }
    if (c.getWake()){
    cout << "Consumidor acordado" << endl;
    c.consome(produto);
    p.recebe_mensagem(c.manda_mensagem());
    buffer -= 1;
    cout << "buffer: " << buffer << endl;
    sleep(5);  // Coloca o consumidor para dormir
    } else {
    cout << "Consumidor dormindo" << endl;
    }
}

}

void Escalonador::deadlock()
{
    ProcessoProd p(0);
    ProcessoCons c(1);

    if (p.getWake() && memoria->getRecurso_1()){
        memoria->setRecurso_1(false);
        cout << "Recurso 1 da memoria alocado para o produtor" << endl;
    }else{
        cout << "Processo produtor aguardando recurso 1" << endl;
    }

    if (c.getWake() && memoria->getRecurso_2()){
        memoria->setRecurso_2(false);
        cout << "Recurso 2 da memoria alocado para o consumidor" << endl;
    }else{
        cout << "Processo consumidor aguardando recurso 2" << endl;
    }

    if (p.getWake() && memoria->getRecurso_2()){
        memoria->setRecurso_2(false);
        cout << "Recurso 2 da memoria alocado para o produtor" << endl;
    }else{
        cout << "Processo produtor aguardando recurso 2" << endl;
    }

    if (c.getWake() && memoria->getRecurso_1()){
        memoria->setRecurso_1(false);
        cout << "Recurso 1 da memoria alocado para o consumidor" << endl;
    }else{
        cout << "Processo consumidor aguardando recurso 1" << endl;
    }

    sleep(3);

}
