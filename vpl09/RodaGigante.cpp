#include "RodaGigante.hpp"
#include <algorithm>
#include <iomanip>

RodaGigante::RodaGigante(const std::string& cod, int ano, double kw, int cap, int cabines)
    : Brinquedo(cod, ano, kw, cap), _cabines(cabines) {
}

std::string RodaGigante::tipo() const {
    return "RodaGigante";
}

void RodaGigante::imprimir_status() const {
    std::string state = this->_pausado ? "pausado" : "ativo";

    std::cout   << std::fixed << std::setprecision(2)
                << this->codigo() << " " 
                << this->tipo() << " " 
                << this->ano() << " "
                << this->capacidade() << " "
                << this->potencia_kw() << " "
                << state << " "
                << "cabines " << _cabines << std::endl;
}

void RodaGigante::operar_tick(int demanda, int& atendidos, double& receita, double& energia) {
    receita += (8.00 + 0.50 * _cabines) * demanda;
    energia += 0.5 * this->potencia_kw();
    atendidos += demanda;
}