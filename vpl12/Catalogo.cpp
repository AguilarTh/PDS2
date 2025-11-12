#include "Catalogo.hpp"

// bool add_musica(std::string titulo, int duracao_s, std::string artista, std::string genero);

bool Catalogo::add_musica(  const std::string& titulo, 
                            int duracao_s, 
                            const std::string& artista, 
                            const std::string& genero) {  
    for(const auto& musica_listada : _itens) {
        if(titulo == musica_listada->titulo()){
            return false;
        }
    }

    // make_xxx -> new
    _itens.push_back(std::make_shared<Musica>(titulo,duracao_s, artista, genero));
    
    // sempre voltar como true/false nn 0/1
    return true;
}

bool Catalogo::add_podcast( const std::string& titulo, 
                            int duracao_s,
                            const std::string& host,
                            int episodio) {
    for(const auto& podcast_listado : _itens) {
        if(titulo == podcast_listado->titulo()){
            return false;
        }
    }

    _itens.push_back(std::make_shared<Podcast>(titulo, duracao_s, host, episodio));
    return true;
}

std::shared_ptr<Midia> Catalogo::get(const std::string& titulo) const {
    for(const auto& item : _itens) {
        if(titulo == item->titulo()) {
            // compreender um pouco melhor esse return
            return item;
        }   
    }
    
    return nullptr;
}

void Catalogo::list_all() const {
    // Mais "clean" checar o empty antes
    if(_itens.empty()) {
        std::cout << "Info: (vazio)." << std::endl;
        return;
        
    }

    for(const auto& item : _itens) {
        // Tem q deferenciar -> eu quero o conteudo do item
        std::cout << *item;
    }
}