#include "Playlist.hpp"

Playlist::Playlist(const std::string& nome) : _nome(nome) {
}

// Entender melhor dps
void Playlist::add(const std::shared_ptr<Midia>& faixa) {
    _faixas.push_back(faixa);
}

void Playlist::list() const {
    int pos=1;
    for(const auto& faixa : _faixas) {
        std::cout   << "Info : Faixa " << pos << std::endl
                    << *faixa;
        pos++;
    }
}

void Playlist::play_all() const {
    for(const auto& faixa : _faixas) {
        faixa->play();
    }
}