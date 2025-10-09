#include "Brinquedo.hpp"

// Dica: O construtor deve inicializar todos os atributos.
// Lembre-se que um brinquedo começa sempre no estado ativo (_pausado = false).
Brinquedo::Brinquedo(const std::string& codigo, int ano, double potencia_kw, int capacidade) : 
    _codigo(codigo),
    _ano(ano),
    _potencia_kw(potencia_kw),
    _capacidade(capacidade),
    _pausado(false){
}

Brinquedo::~Brinquedo() {
    // Destrutor virtual vazio é suficiente aqui.
}

// Dica: As funções "getter" abaixo apenas retornam o valor do atributo correspondente.
std::string Brinquedo::codigo() const {
    return this->_codigo;
}

int Brinquedo::ano() const {
    return this->_ano;
}

double Brinquedo::potencia_kw() const {
    return this->_potencia_kw;
}

int Brinquedo::capacidade() const {
    return this->_capacidade;
}

bool Brinquedo::pausado() const {
    return this->_pausado;
}

void Brinquedo::pausar() {
    if (this->_pausado == true) {
        std::cout << "Brinquedo ja esta pausado." << std::endl;
    } else {
        this->_pausado = true;
    }  
}

void Brinquedo::retomar() {
    if (this->_pausado == false) {
        std::cout << "Brinquedo ja esta em operacao." << std::endl;
    } else {
        this->_pausado = false;
    }  
}