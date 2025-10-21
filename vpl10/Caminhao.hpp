#ifndef CAMINHAO_HPP
#define CAMINHAO_HPP

#include "Veiculo.hpp"

class Caminhao : public Veiculo {
private:
    int _numEixos;

public:
    Caminhao(const std::string& placa, int ano, int capacidade_kg, int numEixos);
    ~Caminhao();

    std::string tipo() const override;
    void print_info() const override;
    double custo_viagem(double km, double carga_kg) const override;
};

#endif