#include "Frota.hpp"
#include "Carro.hpp"
#include "Moto.hpp"
#include "Caminhao.hpp"
#include <algorithm>
#include <iomanip>

Frota::Frota() {}

Frota::~Frota() {
    for (Veiculo* v : _veiculos) {
        delete v;
    }
}

void Frota::add_carro(const std::string& placa, int ano, int capacidade_kg, int num_portas) {
    _veiculos.push_back(new Carro(placa, ano, capacidade_kg, num_portas));
}

void Frota::add_moto(const std::string& placa, int ano, int capacidade_kg, int cilindradas) {
    _veiculos.push_back(new Moto(placa, ano, capacidade_kg, cilindradas));
}

void Frota::add_caminhao(const std::string& placa, int ano, int capacidade_kg, int numEixos) {
    _veiculos.push_back(new Caminhao(placa, ano, capacidade_kg, numEixos));
}

void Frota::list() {
    if(_veiculos.size() == 0){
        std::cout << "Frota vazia!" << std::endl;
    } else {
        for (Veiculo* aux : _veiculos) {
            aux->print_info();
        }
    }
}

void Frota::find(int indice) const {
    // Lembrar que o INDICE começa do 0 -> .size()= 3 // indice 0,1,2
    if(indice >= static_cast<int>(_veiculos.size()) || indice < 0){
        std::cout << "Erro: indice invalido" << std::endl;
    } else {
        _veiculos[indice]->print_info();
    }
}

void Frota::remover(int indice) {
    if(indice >= static_cast<int>(_veiculos.size()) || indice < 0){
        std::cout << "Erro: indice invalido" << std::endl;
    } else {
        Veiculo* veiculoRemover = _veiculos[indice];
        _veiculos.erase(_veiculos.begin() + indice);
        delete veiculoRemover;
    }
}

void Frota::viagem(int indice, double km, int carga_kg) {
    if(indice >= static_cast<int>(_veiculos.size()) || indice < 0){
        std::cout << "Erro: indice invalido" << std::endl;
    } else if (carga_kg > _veiculos[indice]->capacidade_kg()){
        std::cout << "Erro: carga excede capacidade" << std::endl;
    } else {
        double custo = _veiculos[indice]->custo_viagem(km, carga_kg);
        std::cout   << std::fixed << std::setprecision(2)
                    << "Custo: " << custo << std::endl;
    }
}