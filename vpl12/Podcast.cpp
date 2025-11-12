#include "Podcast.hpp"

Podcast::Podcast(const std::string& titulo, int duracao_s, const std::string& host, int episodio)
    : Midia(titulo, duracao_s),
    _episodio(episodio),
    _host(host) {
}

std::string Podcast::host() const {
    return this->_host;
}

int Podcast::episodio() const {
    return this->_episodio;
}

std::string Podcast::tipo() const {
    return "Podcast";
}

void Podcast::print_info() const {
    Midia::print_info();
    std::cout   << "Host: " << this->host() << std::endl 
                << "Episodio: " << this->episodio() << std::endl;
}
