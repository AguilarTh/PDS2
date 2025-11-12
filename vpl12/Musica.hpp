#ifndef MUSICA_HPP
#define MUSICA_HPP

#include "Midia.hpp"

class Musica : public Midia {
private:
    std::string _artista, _genero;

public:
    Musica(const std::string& titulo, int duracao_s, const std::string& artista, const std::string& genero);
    
    std::string artista() const;
    std::string genero() const;
    std::string tipo() const override;
    void print_info() const override;
    // Como ja implementei tudo no pai so nn faço nd
    // void play() const override;
};

#endif