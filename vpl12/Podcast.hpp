#ifndef PODCAST_HPP
#define PODCAST_HPP

#include "Midia.hpp"

class Podcast : public Midia {
private:
    int _episodio;
    std::string _host;

public:
    Podcast(const std::string& titulo, int duracao_s, const std::string& host, int episodio);
    
    std::string host() const;
    int episodio() const;
    std::string tipo() const override;
    void print_info() const override;
};

#endif