#include "Carrossel.hpp"
#include <algorithm>
#include <iomanip>

Carrossel::Carrossel(const std::string& cod, int ano, double kw, int cap, int bichos)
    : Brinquedo(cod, ano, kw, cap), _bichos(bichos) {
}

std::string Carrossel::tipo() const {
    return "Carrossel";
}

void Carrossel::imprimir_status() const {
    std::string state = this->_pausado ? "pausado" : "ativo";

    std::cout   << std::fixed << std::setprecision(2)
                << this->codigo() << " " 
                << this->tipo() << " " 
                << this->ano() << " "
                << this->capacidade() << " "
                << this->potencia_kw() << " "
                << state << " "
                << "bichos " << _bichos << std::endl;
}

void Carrossel::operar_tick(int demanda, int& atendidos, double& receita, double& energia) {
    receita += (6.00 + 0.75 * _bichos) * demanda;
    energia += 0.3 * this->potencia_kw();
    atendidos += demanda;
}