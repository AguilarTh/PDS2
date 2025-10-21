#ifndef MOTO_HPP
#define MOTO_HPP

#include "Veiculo.hpp"

class Moto : public Veiculo {
private:
    int _cilindradas;

public:
    Moto(const std::string& placa, int ano, int capacidade_kg, int cilindradas);
    ~Moto();

    std::string tipo() const override;
    void print_info() const override;
    double custo_viagem(double km, double carga_kg) const override;
};

#endif