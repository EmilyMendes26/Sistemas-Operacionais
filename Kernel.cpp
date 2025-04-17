#include"Kernel.hpp"

Kernel::Kernel(){
    cout << "Sistema Operacional iniciado!" << endl;
}

void Kernel::adicionaProcesso(class Processo* processo){
    tabelaDeProcessos.push_back(processo);
}

void Kernel::criaProcesso(int qp, int qc)
{
    for (int i = 0; i < qp; i++){

        Processo* p = new ProcessoProd(i);
        adicionaProcesso(p);
    }
    for (int i = qp; i < (qp + qc); i++){
        Processo* c = new ProcessoCons(i);
        adicionaProcesso(c);
    }
}

Processo* Kernel::getProcesso(string status) {
    for (Processo* p : tabelaDeProcessos) {
        if (p->getStatus() == status) {
            return p;
        }
    }
    return nullptr;
}

void Kernel::listarProcessos(){
    int pos = 0;

    for (Processo* aux : this->tabelaDeProcessos){
        cout << "Processo de ID:" << aux->getID() << " Tempo: " << aux->getTemp() << " Estado: "<< aux->getStatus() << endl;
		pos++;
    }
}
