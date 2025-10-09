#ifndef Processo_2D
#define Processo_2D

#include <iostream>

struct Processo {
    int id, priority, pos;
    std::string name;

    // Entender melhor esse contrutor padrao
    Processo(int id=0, int priority=0, int pos=0, std::string name="");
    double tempo_reservado_processo();
    void imprimir_dados();
};

#endif