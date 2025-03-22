#include "ProcessoCons.hpp"

ProcessoCons::ProcessoCons()
{
    this->id = getID();
    this-> temp_proc = getTemp();

    cout << "Processo consumidor criado" << endl;
    cout << "ID: " << id << endl << "tempo de processamento: " << temp_proc << endl;

}

void ProcessoCons::setWake(bool wake)
{
    this->is_wake = wake;
}

void ProcessoCons::setTemp_proc(int temp_c)
{
    srand(time(0));

    temp_c = rand() % 5000 + 1;
    
    this->temp_proc = temp_c;
}

void ProcessoCons::setId(int id_c)
{
    srand(time(0));

    id_c = rand() % 10000 + 1;

    this->id = id_c;
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

void ProcessoCons::consome(int prod)
{
    prod -= prod;
    cout << "produto consumido" << endl;
};
