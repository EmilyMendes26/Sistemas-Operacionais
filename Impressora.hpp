#ifndef IMPRESSORA_HPP
#define IMPRESSORA_HPP

#include "Processador.hpp"
#include "includes.hpp"

class Impressora{
    private:
        int buffer;
    public:
        Impressora();
        ~Impressora();
        void InterrompeProcessador(Processador* p);
};

#endif