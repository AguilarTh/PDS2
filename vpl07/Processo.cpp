#include "Processo.hpp"

Processo::Processo(int id, int priority, int pos, std::string name) {
    this->id = id;
    this->priority = priority;
    this->pos = pos;
    this->name = name;
}

double Processo::tempo_reservado_processo() {
    switch (this->priority) {
        case 0:
            return 0.5;
            break;
        case 1:
            return 1.5;
            break;
        case 2:
            return 3;
            break;
        default:
            break;;
    }
}

void Processo::imprimir_dados() {
    std::string priorityStatus;
    switch (this->priority) {
        case 0:
            priorityStatus = "BAIXA";
            break;
        case 1:
            priorityStatus = "MEDIA";
            break;
        case 2:
            priorityStatus = "ALTA";
            break;
    }
    std::cout << this->id << " " << this->name << " " << priorityStatus << std::endl;
}
