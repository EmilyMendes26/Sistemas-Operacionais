#include "ProcessoCons.cpp"
#include "ProcessoProd.cpp"

#define Fila_buffer 15


int buffer=0;
int produto;


int main(){
    ProcessoCons c;
    ProcessoProd p;

    while(true){
        if (buffer == Fila_buffer){
            p.setWake(false);
        }else{
            p.setWake(true);
        }

        if (buffer >= 1){
            c.setWake(true);
        }else{
            c.setWake(false);
        }
        
        if (buffer == 0){
            c.setWake(false);
        }

        if (buffer == (Fila_buffer - 1)){
            c.setWake(true);
        }
        
        if (p.getWake() == true){
            cout << "Produtor acordado" << endl;
            produto = p.produz();
            cout << "Produto produzido: " << produto << endl;
            cout << "buffer: " << (buffer += 1) << endl;
            this_thread::sleep_for(chrono::seconds(5));
        }else{
            cout << "Produtor dormindo" << endl;
        }
        
        if (c.getWake() == true){
            cout << "Consumidor acordado" << endl;
            c.consome(produto);
            cout << "buffer: " << (buffer -= 1) << endl;
            this_thread::sleep_for(chrono::seconds(5));
        }else{
            cout << "Consumidor dormindo" << endl;
        }

    }



    return 0;
}