#include <iostream>
#include <string>
#include <sstream>

#include "Frota.hpp"

using namespace std;

int main() {

    Frota Localiza;

    string line;

    while (std::getline(std::cin, line)){
        if(line.empty()){
            continue;
        }
        
        string comando;
        stringstream ss(line);
        ss >> comando;

        if(comando == "add_c" 
                || comando == "add_m" 
                || comando == "add_k")
        {

            string placa;
            int ano, capacidade_kg, special;

            ss >> placa >> ano >> capacidade_kg >> special;

            if (comando == "add_c"){
                Localiza.add_carro(placa, ano, capacidade_kg, special);
            }

            if (comando == "add_m"){
                Localiza.add_moto(placa, ano, capacidade_kg, special);
            }

            if (comando == "add_k"){
                Localiza.add_caminhao(placa, ano, capacidade_kg, special);
            }
        }

        else if(comando == "list"){
            Localiza.list();
        }

        else if(comando == "find"){
            int ind;
            ss >> ind;

            Localiza.find(ind);
        }

        else if(comando == "rm"){
            int ind;
            ss >> ind;

            Localiza.remover(ind);
        }

        else if(comando == "viagem"){
            int ind, km, carga_kg;
            ss >> ind >> km >> carga_kg;

            Localiza.viagem(ind, km, carga_kg);
        }
    }
}