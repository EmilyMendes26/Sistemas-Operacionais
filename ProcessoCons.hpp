#ifndef PROCESSOCONS_HPP
#define PROCESSOCONS_HPP

#include "includes.hpp"
#include "Processo.hpp"

class ProcessoCons:public Processo{
    
    public:
        ProcessoCons(int id);
        ~ProcessoCons();

        void setWake(bool wake);
        void setTemp();
        void consome(int prod);
        void recebe_mensagem(string msg);

        bool getWake();
        int getTemp();
        int getID();
        string manda_mensagem();

};

#endif