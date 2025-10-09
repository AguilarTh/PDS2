#include "Ponto2D.hpp"
#include "iostream"
#include <math.h>

Ponto2D::Ponto2D(double xInicial, double yInicial) {
    this->x = xInicial;
    this->y = yInicial;
}

double Ponto2D::calcular_distancia(Ponto2D* pontoDois) {
    if (pontoDois == NULL) {
        std::cout << "Ponto Dois Invalido" << std::endl;
        exit(1);
    }

    double dx = pow((this->x - pontoDois->x),2); 
    double dy = pow((this->y - pontoDois->y),2);

    return sqrt(dx + dy);
}