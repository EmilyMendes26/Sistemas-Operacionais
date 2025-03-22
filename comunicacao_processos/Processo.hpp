#ifndef PROCESSO_HPP
#define PROCESSO_HPP

#include "includes.hpp"

class Processo
{
    protected:
        int id;
        int temp_proc;
        bool is_wake;

    public:
        Processo();
        virtual void setId(int id) = 0;
        virtual void setTemp_proc(int temp) = 0;
};

Processo::Processo()
{
}


#endif