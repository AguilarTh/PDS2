#ifndef VEICULO_HPP
#define VEICULO_HPP

#include <string>
#include <iostream>

class Veiculo {
protected:
    std::string _placa;
    int _ano;
    int _capacidade_kg;

    Veiculo(const std::string& placa, int ano, int capacidade_kg);

public:
    virtual ~Veiculo();

    // Como são metodos so de consulta colocar o CONST após
    std::string placa() const;
    int ano() const;
    int capacidade_kg() const;

    virtual std::string tipo() const = 0;
    virtual void print_info() const ;
    virtual double custo_viagem(double km, double carga_kg) const = 0;
};

#endif