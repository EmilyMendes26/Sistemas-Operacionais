#include"Kernel.hpp"

Kernel::Kernel(){
    cout << "Sistema Operacional iniciado!" << endl;
}

void Kernel::adicionaProcesso(class Processo* processo){
    tabelaDeProcessos.push_back(processo);
}

void Kernel::criaProcesso()
{
    int qP = 0;
    int qC = 0;
    cout << "Quantos processos produtor vai criar?" << endl;
    cin >> qP;

    cout << "Quantos processos consumidor vai criar?" << endl;
    cin >> qC;

    for (int i = 0; i < qP; i++){

        Processo* p = new ProcessoProd(i);
        adicionaProcesso(p);
    }
    for (int i = qP; i < (qP + qC); i++){
        Processo* c = new ProcessoCons(i);
        adicionaProcesso(c);
    }
}

void Kernel::listarProcessos(){
    int pos = 0;

    for (Processo* aux : this->tabelaDeProcessos){
        cout << "Processo de ID:" << aux->getID() << " Tempo: " << aux->getTemp() << endl;
		pos++;
    }
}

Processo* Kernel::buscaProcesso(int id)
{
    int pos = 0;
    
    for (Processo* aux : this->tabelaDeProcessos) {
        if (aux->getID() != id) {
            pos++;
        }
    
        else {
            return aux;
        }
    }
}
