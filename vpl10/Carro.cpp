#include "Carro.hpp"

Carro::Carro(const std::string& placa, int ano, int capacidade_kg, int numPortas)
    : Veiculo(placa, ano, capacidade_kg), _numPortas(numPortas) {
}

Carro::~Carro() {
    std::cout << "Destrutor Carro." << std::endl;
}

std::string Carro::tipo() const {
    return "Carro";
}

void Carro::print_info() const {
    Veiculo::print_info();
    std::cout   << "Portas: " << this->_numPortas
                << std::endl;
}

double Carro::custo_viagem(double km, double carga_kg) const {
    return (1.2* km + 40.0* carga_kg);
}