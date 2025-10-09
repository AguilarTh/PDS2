#include "Parque.hpp"
#include <iostream>
#include <iomanip>

Parque::Parque() :
    _num_brinquedos(0),
    _demanda(0),
    _energia_acum(0),
    _receita_acum(0),
    _atendidos_acum(0)
{
    // Não pode ser feito na lista de inicialização

    for(int i=0; i < MAX_BRINQUEDOS; i++){
        _brinquedos[i] = nullptr;
    }
}

Parque::~Parque() {
    for (int i=0; i<_num_brinquedos; i++){
        delete _brinquedos[i];
        // boa pratica -> evita usar ele acidentalmente dnv
        _brinquedos[i] = nullptr;
    }
}

Brinquedo* Parque::find_brinquedo(const std::string& cod) const {
    for (int i=0; i<_num_brinquedos; i++){
        if (_brinquedos[i]->codigo() == cod){
            return _brinquedos[i];
        }
    }
    // tratamento de erro deve ser feito em outro lugar
    return nullptr;
}

void Parque::adicionar(Brinquedo* b) {
    // Confundi a função, adicionar deve apenar colocar um brinquedo JA CRIADO no array
    if(_num_brinquedos < MAX_BRINQUEDOS){
        _brinquedos[_num_brinquedos] = b;
        _num_brinquedos++;
    } else {
        std::cout << "PARQUE LOTADO" << std::endl;
        delete b;
    }
}

void Parque::definir_demanda(int d) {
    this->_demanda = d;
}

void Parque::pausar(const std::string& cod) {
    Brinquedo* b_pra_pausar = find_brinquedo(cod);

    if (b_pra_pausar != nullptr){
        b_pra_pausar->pausar();
    } else {
        std::cout << "Brinquedo informado nao existe." << std::endl;
    }
}

void Parque::retomar(const std::string& cod) {
    Brinquedo* b_pra_retomar = find_brinquedo(cod);

    if (b_pra_retomar != nullptr){
        b_pra_retomar->retomar();
    } else {
        std::cout << "Brinquedo informado nao existe." << std::endl;
    }
}

void Parque::rodar(int T) {
    for (int i=0; i<T; i++){
        int demanda_pendente = _demanda;

        for (int k=0; k<_num_brinquedos; k++){
            if(_brinquedos[k]->pausado() == false){
                int cap = _brinquedos[k]->capacidade();

                if(cap < demanda_pendente) {
                    _brinquedos[k]->operar_tick(
                        cap, 
                        _atendidos_acum, 
                        _receita_acum, 
                        _energia_acum); 
                    demanda_pendente -= cap;
                       
                } else if (demanda_pendente > 0) {
                    _brinquedos[k]->operar_tick(
                        demanda_pendente,
                        _atendidos_acum, 
                        _receita_acum, 
                        _energia_acum);
                    demanda_pendente = 0;
                }
            } else {
                continue;
            }
        }
    }
}

void Parque::status(const std::string& cod) const {
    Brinquedo* b_pra_imprimir = find_brinquedo(cod);

    if (b_pra_imprimir != nullptr){
        b_pra_imprimir->imprimir_status();
    } else {
        std::cout << "Brinquedo informado nao existe." << std::endl;
    }
}

void Parque::painel() const {
    std::cout   << std::fixed << std::setprecision(2)   
                << this->_energia_acum << " " 
                << this->_receita_acum << " " 
                << this->_atendidos_acum << std::endl;
}