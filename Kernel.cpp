#include"Kernel.hpp"

Kernel::Kernel(){
    cout << "Sistema Operacional iniciado!" << endl;
}

void Kernel::adicionaProcesso(class Processo* processo){
    tabelaDeProcessos.push_back(processo);
}

void Kernel::criaProcesso(int qp, int qc)
{
    int tamanhoTabela = this->getTamanhoTabela();
    for (int i = tamanhoTabela; i < (tamanhoTabela + qp); i++){

        Processo* p = new ProcessoProd(i);
        adicionaProcesso(p);
    }
    for (int i = (tamanhoTabela + qp); i < (tamanhoTabela + qp + qc); i++){
        Processo* c = new ProcessoCons(i);
        adicionaProcesso(c);
    }
}

Processo* Kernel::getProcesso(int id) {
    for (Processo* p : tabelaDeProcessos) {
        if (p->getID() == id) {
            return p;
        }
    }
    return nullptr;
}

int Kernel::getTamanhoTabela()
{
    return this->tabelaDeProcessos.size();
}

void Kernel::listarProcessos(){
    int pos = 0;

    for (Processo* aux : this->tabelaDeProcessos){
        cout << "Processo de ID:" << aux->getID() << " Tempo: " << aux->getTemp() << " Estado: "<< aux->getStatus() << endl;
		pos++;
    }
}
