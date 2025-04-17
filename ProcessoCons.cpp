#include "ProcessoCons.hpp"

ProcessoCons::ProcessoCons(int id) :Processo(id)
{
    this->id = id;
    this->status = "espera";
    this->nome = "consumidor";
    setTemp();

    cout << "Processo consumidor criado ";
    cout << "ID: " << id << endl << "tempo de processamento: " << temp_proc << endl;

}

ProcessoCons::~ProcessoCons()
{
    cout << "Processo finalizado!" << endl;
}

void ProcessoCons::setWake(bool wake)
{
    this->is_wake = wake;
}

void ProcessoCons::setTemp()
{
    int temp = rand() % 5000;
    this->temp_proc = temp;
}

void ProcessoCons::setStatus(const string status)
{
    this->status = status;
}

bool ProcessoCons::getWake()
{
    return is_wake;
}

int ProcessoCons::getTemp()
{
    return this->temp_proc;

}

int ProcessoCons::getID()
{
    return this->id;
}

string ProcessoCons::getNome()
{
    return this->nome;
}

string ProcessoCons::getStatus()
{
    return this->status;
}

void ProcessoCons::consome(int prod)
{
    prod -= prod;
    //cout << manda_mensagem() << endl;
}
void ProcessoCons::recebe_mensagem(string msg) {
    this->msgbox = msg;
    cout << "Aviso Consumidor; mensagem: " << msgbox << " Recebida" << endl;
};

string ProcessoCons::manda_mensagem() {
    return "Produto consumido";
};
