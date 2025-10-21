#include "Veiculo.hpp"
#include <algorithm>
#include <iomanip>

Veiculo::Veiculo(const std::string& placa, int ano, int capacidade_kg) : 
    _placa(placa),
    _ano(ano),
    _capacidade_kg(capacidade_kg){
}

Veiculo::~Veiculo() {
    std::cout << "Destrutor Veiculo" << std::endl;
}

std::string Veiculo::placa() const {
    return this->_placa;
}

int Veiculo::ano() const {
    return this->_ano;
}

int Veiculo::capacidade_kg() const {
    return this->_capacidade_kg;
}

// Entender melhor a aplicação do tipo() aq
void Veiculo::print_info() const {
    std::cout   << std::fixed << std::setprecision(2)
                << "Tipo: " << this->tipo() << ",  "
                << "Placa: " << this->placa() << ", "
                << "Ano: " << this->ano() << ", "
                << "Capacidade: " << this->capacidade_kg() << ", ";
}