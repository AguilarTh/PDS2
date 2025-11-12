#ifndef PLAYLIST_HPP
#define PLAYLIST_HPP 

#include "Midia.hpp"

#include <string>
#include <vector>
#include <memory>

class Playlist {
private:
    std::string _nome;
    std::vector<std::shared_ptr<Midia>> _faixas;

public:
    Playlist(const std::string& nome);

    void add(const std::shared_ptr<Midia>& faixa);
    void list() const;
    void play_all() const;
};

#endif