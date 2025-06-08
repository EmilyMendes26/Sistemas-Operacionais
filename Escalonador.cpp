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

    bool recurso1_livre = true;
    bool recurso2_livre = true;
    
    if (p.getWake() && recurso1_livre){
        recurso1_livre = false;
        cout << "Recurso 1 esta bloqueado" << endl;
    }else{
        cout << "Esperando recurso 1" << endl;
    }

    if (p.getWake() && recurso2_livre){
        
    }
}
