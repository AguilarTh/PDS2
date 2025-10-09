#ifndef PONTO_2D
#define PONTO_2D

struct Ponto2D {
    double x, y;
    Ponto2D(double xInicial = -1, double yInicial = -1);

    // Entender melhor o uso de Const dps
    double calcular_distancia(Ponto2D* pontoDois);

};

#endif