#include "Impressora.hpp"

Impressora::Impressora()
{
    this->buffer = 0;
}

Impressora::~Impressora()
{

}

void Impressora::InterrompeProcessador(Processador *p)
{
    cout << "O buffer esta em: " << buffer << endl;

    if (buffer != 2){
        this->buffer += 1;
    }
    else if (buffer == 2){

        if (p->getNucleo2()){
            p->setNucleo2(false);
            cout << "Impressora solicitou interrupcao na CPU" << endl;
            cout << "CPU esta indo atender a solicitacao" << endl;
            sleep(4);
            p->setNucleo2(true);
            buffer = 0;
            cout << "CPU atendeu a solicitacao e foi liberada" << endl;
        }else if (p->getNucleo1())
        {
            p->setNucleo1(false);
            cout << "Impressora solicitou interrupcao na CPU" << endl;
            cout << "CPU esta indo atender a solicitacao" << endl;
            sleep(4);
            p->setNucleo1(true);
            buffer = 0;
            cout << "CPU atendeu a solicitacao e foi liberada" << endl;
        }
    }
}
