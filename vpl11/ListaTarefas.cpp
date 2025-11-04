#include "ListaTarefas.hpp"
#include <iostream>

ListaTarefas::ListaTarefas() : _proximo_id(1) {}

void ListaTarefas::adicionar_tarefa(std::string descricao) {
    _tarefas.emplace_back(_proximo_id++, descricao);
}

bool ListaTarefas::concluir_tarefa(int id) {
    for (auto& tarefa : _tarefas) {
        if (tarefa.get_id() == id) {
            
            tarefa.concluir();
            return true;
        }
    }
    return false;
}

void ListaTarefas::imprimir_tarefas() const {
    for (const auto& tarefa : _tarefas) {
        tarefa.imprimir();
    }
}

int ListaTarefas::total_concluidas() const {
    int count = 0;
    for (const auto& tarefa : _tarefas) {
        if (tarefa.esta_concluida()) count++;
    }
    return count;
}

int ListaTarefas::total_pendentes() const {
    return ( _tarefas.size() - total_concluidas());
}
