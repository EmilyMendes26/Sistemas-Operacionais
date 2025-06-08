#ifndef MEMORIA_HPP
#define MEMORIA_HPP

#include"Processo.hpp"
#include"ProcessoProd.hpp"
#include"ProcessoCons.hpp"

class Memoria{
    private:
    bool recurso_1; 
    bool recurso_2;

    protected:
        vector<Processo*> tabelaDeProcessos;

    public:
    Memoria();
    void setRecurso_1(bool r1);
    void setRecurso_2(bool r2);
    bool getRecurso_1();
    bool getRecurso_2();
    int getTamanhoTabela();
    vector<Processo*>& getTabelaProcesso();
};

#endif