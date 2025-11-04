#include "Tarefa.hpp"
#include <iostream>

Tarefa::Tarefa(int id, std::string descricao)
    : _id(id), _descricao(descricao), _concluida(false) {}

int Tarefa::get_id() const {
    return _id;
}

std::string Tarefa::get_descricao() const {
    return _descricao;
}

bool Tarefa::esta_concluida() const {
    return _concluida;
}

void Tarefa::concluir() {
    _concluida = true;
}

void Tarefa::imprimir() const {
    std::string status = _concluida ? "X" : " ";
    std::cout << "[" << status << "] " << _id << ": " << _descricao << std::endl;
}
