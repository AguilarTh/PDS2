#include <iostream>
#include <string>
#include <sstream>

#include "Parque.hpp"
#include "MontanhaRussa.hpp"
#include "Carrossel.hpp"
#include "RodaGigante.hpp"

using namespace std;

int main() {
    // preciso criar (new) de fato o parque antes
    Parque* ThiagoCarreroWorld = new Parque();

    bool isProgAtivo = true;

    // mudar o padrao do while dps
    while (isProgAtivo){
        string line, comando;
        getline(cin, line);

        stringstream ss(line);
        ss >> comando; // extrai a 1 PALAVRA -> no caso o comando principal

        // boa pratica para verificação
        if (line.empty()) {
            continue; 
        }

        else if(comando == "carregar"){
            int numNovosBrinquedos;
            ss >> numNovosBrinquedos; // pega agora a 2 PALAVRA

            for(int i=0; i<numNovosBrinquedos; i++){

                string lineBrinquedo;
                getline(cin, lineBrinquedo);
                stringstream ss_brinquedo(lineBrinquedo);

                string aux, cod;
                int ano, cap, special;
                double kw;

                ss_brinquedo >> aux >> cod >> ano >> kw >> cap >> special;

                if(aux == "mr"){
                    Brinquedo* newMr = new MontanhaRussa(cod, ano, kw, cap, special);
                    
                    ThiagoCarreroWorld->adicionar(newMr);
                }

                else if(aux == "car"){
                    Brinquedo* newCar = new Carrossel(cod, ano, kw, cap, special);
                    
                    ThiagoCarreroWorld->adicionar(newCar);
                }

                else if(aux == "rod"){
                    Brinquedo* newRod = new RodaGigante(cod, ano, kw, cap, special);
                     
                    ThiagoCarreroWorld->adicionar(newRod);
                }
            }
        }

        else if(comando == "demanda") {
            int numDemanda;
            ss >> numDemanda;
            
            ThiagoCarreroWorld->definir_demanda(numDemanda);
        }

        else if(comando == "rodar") {
            int numTicks;
            ss >> numTicks;

            ThiagoCarreroWorld->rodar(numTicks);
        }

        else if(comando == "pausar") {
            string codBrinquedo;
            ss >> codBrinquedo;

            ThiagoCarreroWorld->pausar(codBrinquedo);
        }

        else if(comando == "retomar") {
            string codBrinquedo;
            ss >> codBrinquedo;

            ThiagoCarreroWorld->retomar(codBrinquedo);
        }

        else if(comando == "status") {
            string codBrinquedo;
            ss >> codBrinquedo;

            ThiagoCarreroWorld->status(codBrinquedo);
        }

        else if(comando == "painel") {
            ThiagoCarreroWorld->painel();
        }

        else if(comando == "encerrar"){
            isProgAtivo = false;
        }
    }

    // Tudo que for iniciado tem q ser destruido
    delete ThiagoCarreroWorld;
    return 0;
}