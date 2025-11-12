#include "Musica.hpp"

Musica::Musica(const std::string &titulo, int duracao_s, const std::string& artista, const std::string& genero)
    : Midia(titulo, duracao_s),
    _artista(artista),
    _genero(genero) {
}

std::string Musica::artista() const {
    return this->_artista;
}

std::string Musica::genero() const {
    return this->_genero;
}

std::string Musica::tipo() const {
    return "Musica";
}

void Musica::print_info() const {
    Midia::print_info();
    std::cout   << "Artista: " << this->artista() << std::endl 
                << "Genero: " << this->genero() << std::endl;
}

