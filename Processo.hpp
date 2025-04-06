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

    public:
        Processo(int id);
        virtual int getID() = 0;
        virtual int getTemp() = 0;
};

Processo::Processo(int id)
{
    this->id = id;
}


#endif