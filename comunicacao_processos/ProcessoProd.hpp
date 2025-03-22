#ifndef PROCESSOPROD_HPP
#define PROCESSOPROD_HPP

#include "includes.hpp"
#include "Processo.hpp"

class ProcessoProd:public Processo{
    
    public:
        ProcessoProd();

        void setWake(bool wake);
        void setTemp_proc(int temp_p);
        void setId(int id_p);

        bool getWake();
        int getTemp();
        int getID();

        int produz();
};

#endif