#ifndef TAREFA_HPP
#define TAREFA_HPP

#include <string>

class Tarefa {
private:
    int _id;
    std::string _descricao;
    bool _concluida;

public:
    Tarefa(int id, std::string descricao);
    int get_id() const;
    std::string get_descricao() const;
    bool esta_concluida() const;
    void concluir();
    void imprimir() const;
};

#endif
