#include"Kernel.hpp"

Kernel::Kernel(Memoria *m){
    this->memoria = m;
    cout << "Sistema Operacional iniciado!" << endl;
}

void Kernel::adicionaProcesso(class Processo* processo){
    memoria->getTabelaProcesso().push_back(processo);
}

void Kernel::criaProcesso(int qp, int qc)
{
    int tamanhoTabela = memoria->getTamanhoTabela();
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
    for (Processo* p : memoria->getTabelaProcesso()) {
        if (p->getID() == id) {
            return p;
        }
    }
    return nullptr;
}

void Kernel::listarProcessos(){
    int pos = 0;

    for (Processo* aux : memoria->getTabelaProcesso()){
        cout << "Processo de ID:" << aux->getID() << " Tempo: " << aux->getTemp() << " Estado: "<< aux->getStatus() << endl;
		pos++;
    }
}
