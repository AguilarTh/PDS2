#include "Caminhao.hpp"

Caminhao::Caminhao(const std::string& placa, int ano, int capacidade_kg, int numEixos)
    : Veiculo(placa, ano, capacidade_kg), _numEixos(numEixos){
}

Caminhao::~Caminhao() {
    std::cout << "Destrutor Caminhao." << std::endl;
}

std::string Caminhao::tipo() const {
    return "Caminhao";
}

void Caminhao::print_info() const {
    Veiculo::print_info();
    std::cout   << "Eixos: " << this->_numEixos
                << std::endl;
}

double Caminhao::custo_viagem(double km, double carga_kg) const {
    return (2.5* km + 60.0* carga_kg);
}