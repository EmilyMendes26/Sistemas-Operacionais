#include "ProcessoProd.hpp"

ProcessoProd::ProcessoProd(int id) : Processo(id)
{
    this->id = id;
    this->status = "espera";
    this->nome = "produtor";
    setTemp();

    cout << "Processo produtor criado ";
    cout << "ID: " << id << endl << "tempo de processamento: " << temp_proc << endl;

}

ProcessoProd::~ProcessoProd()
{
    cout << "Processo finalizado!" << endl;
}

void ProcessoProd::setWake(bool wake)
{
    this->is_wake = wake;
}

void ProcessoProd::setTemp()
{
    int temp = rand() % 5000;
    this->temp_proc = temp;

}

void ProcessoProd::setStatus(const string status)
{
    this->status = status;
}

bool ProcessoProd::getWake()
{
    return is_wake;
}

int ProcessoProd::getTemp()
{
    return this->temp_proc;

}

int ProcessoProd::getID()
{
    return this->id;
}

string ProcessoProd::getNome()
{
    return this->nome;
}

string ProcessoProd::getStatus()
{
    return status;
}

int ProcessoProd::produz()
{
    int item;

    item = rand() % 10000;
    
    //cout << manda_mensagem() << endl;
    return item;
    
}

void ProcessoProd::recebe_mensagem(string msg) {
    this->msgbox = msg;
    cout << "Aviso produtor; mensagem: " << msgbox << " Recebida" << endl;
};

string ProcessoProd::manda_mensagem() {
    return "Produto produzido";
};