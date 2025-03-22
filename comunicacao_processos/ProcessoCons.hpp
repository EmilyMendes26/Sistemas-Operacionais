#ifndef PROCESSOCONS_HPP
#define PROCESSOCONS_HPP

#include "includes.hpp"
#include "Processo.hpp"

class ProcessoCons:public Processo{
    
    public:
        ProcessoCons();

        void setWake(bool wake);
        void setTemp_proc(int temp_c);
        void setId(int id_c);

        bool getWake();
        int getTemp();
        int getID();

        void consome(int prod);
};

#endif