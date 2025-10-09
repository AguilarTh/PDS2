#ifndef FilaProcessos_2D
#define FilaProcessos_2D

#include "Processo.hpp"

struct Node {
    Processo Processos;
    Node* NextProcessos;
};

struct FilaProcessos {
    Node* head = nullptr;
    Node* tail = nullptr;
    int nodeCount = 1;

    int localizar_posicao_prioridade(int priority);
    void adicionar_processo(std::string name, int priority);
    Processo* remover_processo_maior_prioridade();
    Processo* remover_processo_por_id(int id);
    void estimativa_tempo_para_execucao(int id);
    void imprimir_fila();
};

#endif