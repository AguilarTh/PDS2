#ifndef ROBO
#define ROBO

#include "Ponto2D.hpp"

struct Robo {
    int id;
    Ponto2D pos;
    double energy = 100;
    bool haveBall;

    Robo(int id, Ponto2D position, bool haveBall);
    void mover(double vel, double dir, double time);
    double calcular_distancia(Robo* roboDois);
    Robo* determinar_robo_mais_proximo(Robo** team, int teamSize);
    void passar_bola(Robo** team, int teamSize);
    void imprimir_status();
};

#endif
