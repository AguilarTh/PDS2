#include "Midia.hpp"
#include <thread>
#include <chrono>

Midia::Midia(const std::string& titulo, int duracao_s) :
    _duracao_s(duracao_s),
    _titulo(titulo){
}

Midia::~Midia() {
}

int Midia::duracao_s() const {
    return this->_duracao_s;
}

std::string Midia::titulo() const {
    return this->_titulo;
}

void Midia::print_info() const {
    std::cout   << "Info: Midia" << std::endl 
                << "Titulo: " << this->titulo() << std::endl
                << "Duracao (s): " << this->duracao_s() << std::endl 
                << "Tipo: " << this->tipo() << std::endl;
}

// Entender melhor sobre o gap de 1 sec
void Midia::play() const {
    // Por que é uma boa pratica pegar isso antes mesmo?
    int duracao_total = this->duracao_s();
    std::string titulo_midia = this->titulo();

    // anotar sobre o i++ != ++i
    // Colocar tbm sobre quando usar cada sintaxe
    for(int i=1; i<= duracao_total; ++i){
        std::cout   << "Playing " << titulo_midia << " ["
                    << i << "/" << duracao_total << "]" 
                    << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

// Como é uma função global, nn possui o "Midia::"
std::ostream& operator<<(std::ostream& os, const Midia& m) {
    m.print_info();
    // talvez precisa disso aq:
    return os;
}