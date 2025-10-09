#include "Robo.hpp"
#include "cmath"
#include <cfloat>
#include <iostream>

    // Robo (int id, Ponto2D, bool);
    // void mover (double vel, double dir, double time);
    // double calcular_distancia (Robo* roboDois);
    // Robo* determinar_robo_mais_proximo (Robo** team, int teamSize);
    // void passar_bola (Robo** team, int teamSize);
    // void imprimir_status ();

Robo::Robo(int id, Ponto2D position, bool haveBall) {
    this->id = id;
    this->pos = position;
    this->haveBall = haveBall;
}

void Robo::mover(double vel, double dir, double time) {
    double xVel = (vel*cos(dir))*time, yVel = vel*sin(dir)*time;

    // entender melhor o "->" // "."
    this->pos.x += xVel;
    this->pos.y += yVel;

    this->energy -= sqrt( pow(xVel, 2) + pow(yVel, 2));
}

// entender melhor essa merda
double Robo::calcular_distancia (Robo* roboDois) {
    return this->pos.calcular_distancia(&(roboDois->pos));
}

Robo* Robo::determinar_robo_mais_proximo (Robo** team, int teamSize) {
    // Iniciar ptr como Nulo
    Robo* closestRobo = nullptr;

    // DBL_MAX = maior double possivel
    double closestRoboDist = DBL_MAX;

    for (int i=0; i < teamSize; i++) {
        if(team[i] == this){
            //  SE for ele mesmo, passa p/ o proximo
            continue;
        }

        // "calcular_distancia" é um METODO de ROBO, 
        // ent tem q lembrar de chamar a partir de um "this"
        double distVar = this->calcular_distancia(team[i]);

        if(distVar < closestRoboDist) {
            closestRoboDist = distVar;
            closestRobo = team[i];
        }

    }

    return closestRobo;
}

void Robo::passar_bola (Robo** team, int teamSize) {
    if(this->haveBall == false){
        std::cout << "Estou sem a bola!" << std::endl;
    }else {
        Robo* willTakeBall = this->determinar_robo_mais_proximo(team, teamSize);
       
        if (willTakeBall != nullptr) {
            willTakeBall->haveBall = true;
            this->haveBall = false;
        }else {
            std::cout << "Não há outros robos proximos" << std::endl;
        }
    }
}

void Robo::imprimir_status (){
    std::cout << this->id << " " << this->pos.x << " " << this->pos.y << " " << this->haveBall << " " << this->energy << "\t";
}