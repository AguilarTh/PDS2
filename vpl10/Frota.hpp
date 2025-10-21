#ifndef FROTA_HPP
#define FROTA_HPP

#include "Veiculo.hpp"
#include "Carro.hpp"
#include "Moto.hpp"
#include "Caminhao.hpp"
#include <string>
#include <vector>

class Frota {
private:
    std::vector<Veiculo*> _veiculos;

public:
// Entender direito
    Frota();
    ~Frota();


    void add_carro(const std::string& placa, int ano, int capacidade_kg, int num_portas);
    void add_moto(const std::string& placa, int ano, int capacidade_kg, int cilindradas);
    void add_caminhao(const std::string& placa, int ano, int capacidade_kg, int numEixos);
    
    void list();
    void find(int indice) const;
    void remover(int indice);

    void viagem(int indice, double km, int carga_kg);

};

#endif