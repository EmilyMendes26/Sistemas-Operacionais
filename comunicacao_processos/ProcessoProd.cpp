#include "ProcessoProd.hpp"

ProcessoProd::ProcessoProd()
{
    this->id = getID();
    this-> temp_proc = getTemp();

    cout << "Processo produtor criado" << endl;
    cout << "ID: " << id << endl << "tempo de processamento: " << temp_proc << endl;

}

void ProcessoProd::setWake(bool wake)
{
    this->is_wake = wake;
}

void ProcessoProd::setTemp_proc(int temp_p)
{
    srand(time(0));

    temp_p = rand() % 5000 + 1;
    
    this->temp_proc = temp_p;
}

void ProcessoProd::setId(int id_p)
{
    srand(time(0));

    id_p = rand() % 10000 + 1;

    this->id = id_p;
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

int ProcessoProd::produz()
{
    int item;
    srand(time(0));

    item = rand() % 10000 + 1;
    
    cout << "Produto criado" << endl;
    return item;
    
}
