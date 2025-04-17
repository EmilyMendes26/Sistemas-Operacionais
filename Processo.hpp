#ifndef PROCESSO_HPP
#define PROCESSO_HPP

#include "includes.hpp"

class Processo
{
    protected:
        int id;
        int temp_proc;
        bool is_wake;
        string msgbox;
        string status;
        string nome;

    public:
        Processo(int id);
        virtual int getID() = 0;
        virtual int getTemp() = 0;
        virtual string getStatus() = 0;
        virtual void setStatus(const string status) = 0;
};

Processo::Processo(int id)
{
    this->id = id;
}


#endif