#ifndef PROCESSOPROD_HPP
#define PROCESSOPROD_HPP

#include "includes.hpp"
#include "Processo.hpp"

class ProcessoProd:public Processo{
    
    public:
        ProcessoProd(int id);
        ~ProcessoProd();

        void setWake(bool wake);
        void setTemp();
        void recebe_mensagem(string msg);

        bool getWake();
        int getTemp();
        int getID();
        int produz();
        string manda_mensagem();
};

#endif