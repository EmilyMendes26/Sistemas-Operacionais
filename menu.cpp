#include "Kernel.cpp"
#include "Escalonador.cpp"
#include "ProcessoCons.cpp"
#include "ProcessoProd.cpp"


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
            Kernel sistema;
            Escalonador escalona(&sistema);
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
                    #define Fila_buffer 15

                    int buffer = 0;
                    int produto;

                    ProcessoProd p(0);
                    ProcessoCons c(1);

                    while(true){
                        if (buffer == Fila_buffer){
                            p.setWake(false);
                        } else {
                            p.setWake(true);
                        }

                        if (buffer >= 1){
                            c.setWake(true);
                        } else {
                            c.setWake(false);
                        }

                        if (buffer == 0){
                            c.setWake(false);
                        }

                        if (buffer == (Fila_buffer - 1)){
                            c.setWake(true);
                        }

                        if (p.getWake()){
                            cout << "Produtor acordado" << endl;
                            produto = p.produz();
                            c.recebe_mensagem(p.manda_mensagem());
                            cout << "buffer: " << ++buffer << endl;
                            sleep(5);
                        } else {
                            cout << "Produtor dormindo" << endl;
                        }

                        if (c.getWake()){
                            cout << "Consumidor acordado" << endl;
                            c.consome(produto);
                            p.recebe_mensagem(c.manda_mensagem());
                            cout << "buffer: " << --buffer << endl;
                            sleep(5);  // Coloca o consumidor para dormir
                        } else {
                            cout << "Consumidor dormindo" << endl;
                        }
                    }
                }

            } while (opc2 != 0);
        }
    }
    return 0;
}