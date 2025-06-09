#include "Kernel.cpp"
#include "Escalonador.cpp"
#include "ProcessoCons.cpp"
#include "ProcessoProd.cpp"
#include "Memoria.cpp"
#include "Processador.cpp"
#include "Impressora.cpp"


void sleepClear(){
    sleep(2);
    system("cls");
}

int main(){
    bool sair = false;
    system("cls");
    while(sair != true){
        int opc;
        cout << "Digite 0 para sair" << endl;
        cout << "Digite 1 para iniciar o sistema" << endl;
        cin >> opc;

        if (opc == 0){
            cout << "Encerrando!" << endl;
            sair = true;
        }
        if (opc == 1){
            Impressora* i = new Impressora();
            Memoria m;
            Processador i2;
            Kernel sistema(&m);
            Escalonador escalona(&sistema, &m, &i2);
            int opc2;
            sleepClear();
            

            do {
                cout << "Digite 0 para sair" << endl;
                cout << "Digite 1 para criar processos" << endl;
                cout << "Digite 2 para iniciar todos os processo" << endl;
                cout << "Digite 3 para encerrar todos os processo" << endl;
                cout << "Digite 4 para iniciar processo por ID" << endl;
                cout << "Digite 5 para encerrar processo por ID" << endl;
                cout << "Digite 6 para visualizar os processos" << endl;
                cout << "Digite 7 para visualizar a fila do escalonador" << endl;
                cout << "Digite 8 para visualizar escalonamento wake and sleep" << endl;
                cout << "Digite 9 para gerar 5 processos" << endl;
                cout << "Digite 10 para simular o deadlock" << endl;
                cout << "Digite 11 para simular E/S" << endl;

                cin >> opc2;
                system("cls");

                if (opc2 == 0){
                    opc2 = 0;
                    break;
                }
                if (opc2 == 1){
                    
                    int qP = 0;
                    int qC = 0;
                    cout << "Quantos processos produtor vai criar?" << endl;
                    cin >> qP;

                    cout << "Quantos processos consumidor vai criar?" << endl;
                    cin >> qC;
                    sistema.criaProcesso(qP, qC);
                    escalona.adicionaProcesso();
                    sleepClear();
                }
                if (opc2 == 2){
                    escalona.iniciaProcesso();
                    sleepClear();
                }
                if (opc2 == 3){
                    escalona.terminaProcesso();
                    sleepClear();
                }

                if (opc2 == 4){
                    int id;
                    cout << "Qual o id do processo a ser iniciado: " << endl;
                    cin >> id;
                    escalona.iniciaProcessoId(id);
                    sleepClear();
                }
                if (opc2 == 5){
                    int id;
                    cout << "Qual o id do processo a ser finalizado: " << endl;
                    cin >> id;
                    escalona.terminaProcessoId(id);
                    sleepClear();
                }

                if (opc2 == 6){
                    sistema.listarProcessos();
                    sleepClear();
                }

                if (opc2 == 7){
                    escalona.listaProcesso();
                    sleepClear();
                }

                if (opc2 == 9){
                    sistema.criaProcesso(3,2);
                    escalona.adicionaProcesso();
                    sleepClear();
                }

                if (opc2 == 8){
                    escalona.wake_sleep();
                    sleepClear();
                }

                if (opc2 == 10){
                    escalona.deadlock();
                    sleepClear();
                }

                if (opc2 == 11){
                    i->InterrompeProcessador(&i2);
                    sleepClear();
                }
            

            } while (opc2 != 0);
        }
    }
    return 0;
}