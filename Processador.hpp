#ifndef PROCESSADOR_HPP
#define PROCESSADOR_HPP

class Processador{
    private:
    bool nucleo1;
    bool nucleo2;

    public:
    Processador();
    void setNucleo1(bool n);
    void setNucleo2(bool n);
    bool getNucleo1();
    bool getNucleo2();
};

#endif