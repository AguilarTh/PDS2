#ifndef CARRO_HPP
#define CARRO_HPP

#include "Veiculo.hpp"

class Carro : public Veiculo {
private:
    int _numPortas;

public:
    Carro(const std::string&placa, int ano, int capacidade_kg, int numPortas);
    ~Carro();

    // Lembrar de colocar o const + override 
    std::string tipo() const override;
    void print_info() const override;
    double custo_viagem(double km, double carga_kg ) const override;
};

#endif