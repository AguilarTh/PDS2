#include "MontanhaRussa.hpp"
#include <algorithm>
#include <iomanip>

// Dica: Use a lista de inicialização do construtor para chamar o construtor da classe base (Brinquedo).
MontanhaRussa::MontanhaRussa(const std::string& cod, int ano, double kw, int cap, int loops)
    : Brinquedo(cod, ano, kw, cap), _loops(loops) {
}

std::string MontanhaRussa::tipo() const {
    return "MontanhaRussa";
}

void MontanhaRussa::imprimir_status() const {
    std::string state = this->pausado() ? "pausado" : "ativo";

    std::cout   << std::fixed << std::setprecision(2)
                << this->codigo() << " " 
                << this->tipo() << " " 
                << this->ano() << " "
                << this->capacidade() << " "
                << this->potencia_kw() << " "
                << state << " "
                << "loops " << _loops << std::endl;
}

void MontanhaRussa::operar_tick(int demanda, int& atendidos, double& receita, double& energia) {
    receita += (12.00 + 0.25 * _loops) * demanda;
    energia += 0.8 * this->potencia_kw();
    atendidos += demanda;
}