#ifndef MIDIA_HPP
#define MIDIA_HPP

#include <string>
#include <iostream>

class Midia {
protected: 
    int _duracao_s;
    std::string _titulo;

    Midia(const std::string &titulo, int duracao_s);

public:
    virtual ~Midia();

    int duracao_s() const;
    std::string titulo() const;

    virtual void print_info() const;
    virtual void play() const;
    virtual std::string tipo() const = 0;
};

// É uma função global, nn um metodo
std::ostream& operator<<(std::ostream& os, const Midia& m);

#endif