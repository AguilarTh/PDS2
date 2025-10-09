#include "FilaProcessos.hpp"
#include <iomanip>  

int FilaProcessos::localizar_posicao_prioridade(int priority){
    // Node* aux = new Node; 
    // Não precisa desse node aux por que so uso ele para pegar a prioridade
    // pode ser um int simples passado como parametro

    Node *current = head;

    if(head == nullptr){
        return 1; // retorna como se fosse o primeiro
    } else {
        while(current != nullptr){
            if(current->Processos.priority < priority){
                return current->Processos.pos;
            }
            current = current->NextProcessos;
        }
    }
    
    return -1; // sem niguem com prioridade menor;
}

void FilaProcessos::adicionar_processo(std::string name, int priority) {
    Node* aux = new Node;

    aux->Processos.name = name;
    aux->Processos.priority = priority;
    aux->Processos.id = nodeCount++;
    aux->NextProcessos = nullptr;

    // Fila Vazia
    if(head == nullptr){
        aux->Processos.pos = 1;
        head = aux;
        tail = aux;
        return;
    } 

    int lastPriorityNode = localizar_posicao_prioridade(priority);

    // CASE 1 = MAIOR PRIORIDADE DA FILA 

    if(lastPriorityNode == head->Processos.pos) {
        aux->NextProcessos = head;
        head = aux;

        // Add +1 no ID de cada um da fila
        Node* current = head;
        int posicao = 1;
        while (current != nullptr) {
            // Olhar ess trem de valor pre incrementado e pos incrementado
            current->Processos.pos = posicao++;
            current = current->NextProcessos;
        }
        return;
    }

    //  CASE 2 = MENOR PRIORIDADE DA FILA 

    if(lastPriorityNode == -1) {
        aux->Processos.pos = tail->Processos.pos + 1;
        tail->NextProcessos = aux;
        tail = aux;
        return;
    }

    // CASE 3 = MEIO DA FILA

    Node* current = head;
    Node* previous = nullptr;

    while (current != nullptr){
        if(current->Processos.pos == lastPriorityNode){
            // 1 - Insiro no meio

            previous->NextProcessos = aux;
            aux->NextProcessos = current;

            // 2 - ReAtribui os ID's

            Node* sec = head;
            int posicao = 1;
            while (sec != nullptr){
                sec->Processos.pos = posicao++;
                sec = sec->NextProcessos;
            }

            return;      
        }

        previous = current;
        current = current->NextProcessos;
    }
}

Processo* FilaProcessos::remover_processo_maior_prioridade() {

    if(head == nullptr) {
        return nullptr;
    } 

    Node* deletedProcesso = head;
    head = head->NextProcessos;

    // Mudança de Pos
    Node* current = head;
    while(current != nullptr) {
        current->Processos.pos--;
        current = current->NextProcessos;
    }

    // O -> tem precedencia sobre o &, logo nn precisa de parantese 
    return &deletedProcesso->Processos;
}

Processo* FilaProcessos::remover_processo_por_id(int id) {
    Node* current = head;
    Node* previous = nullptr;

    while(current != nullptr){
        if(current->Processos.id == id){

            if (previous == nullptr) {  // CASE POS = HEAD 
                head = current->NextProcessos;
            } else {
                previous->NextProcessos = current->NextProcessos;
            }
        
            Node* aux = current->NextProcessos;
            int posicao = current->Processos.pos;
            while (aux != nullptr){
                aux->Processos.pos = posicao++;
                aux = aux->NextProcessos;
            }

            return &current->Processos;
        }
        previous = current;
        current = current->NextProcessos;
    }
    return nullptr;
}

void FilaProcessos::estimativa_tempo_para_execucao(int id){
    double totalTime = 0; 

    Node* aux = head;
    while (aux->Processos.id != id) {
        totalTime += aux->Processos.tempo_reservado_processo();
        aux = aux->NextProcessos;
    }

    std::cout << std::fixed << std::setprecision(1); 
    std::cout << "Tempo estimado para execução do processo " << aux->Processos.name << " (id=" << aux->Processos.id << ") eh " << totalTime << " segundos." << std::endl; 
}

void FilaProcessos::imprimir_fila() {
    Node* aux = head;
    // pode-se usar o "FOR" tambem
    // >> for (Node* aux = head; aux != nullptr; aux = aux->NextProcessos) <<
    while (aux != nullptr) {
        aux->Processos.imprimir_dados();
        aux = aux->NextProcessos;
    }
}