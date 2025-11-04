#ifndef LISTATAREFAS_HPP
#define LISTATAREFAS_HPP

#include "Tarefa.hpp"
#include <vector>
#include <string>

class ListaTarefas {
private:
    std::vector<Tarefa> _tarefas;
    int _proximo_id;

public:
    ListaTarefas();
    void adicionar_tarefa(std::string descricao);
    bool concluir_tarefa(int id);
    void imprimir_tarefas() const;
    int total_concluidas() const;
    int total_pendentes() const;
};

#endif
