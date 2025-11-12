#ifndef CATALOGO_HPP
#define CATALOGO_HPP

#include "Midia.hpp"
#include "Musica.hpp"
#include "Podcast.hpp"
#include <string>
#include <vector>
#include <memory>

class Catalogo {
private:
    // Entender melhor o sharedptr
    std::vector<std::shared_ptr<Midia>> _itens;

public:
    // Como nn tenho atributos novos, nn precisa de construtor
    // Nao preciso do destrutor com o for ja que uso ponteiro inteligente

    bool add_musica(const std::string& titulo, 
                    int duracao_s, 
                    const std::string& artista, 
                    const std::string& genero);
    bool add_podcast(const std::string& titulo, 
                    int duracao_s, 
                    const std::string& host, 
                    int episodio);

    // Lembrar de usar o get por & aq
    std::shared_ptr<Midia> get(const std::string& titulo) const;

    void list_all() const;
};

#endif