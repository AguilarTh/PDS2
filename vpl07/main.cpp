// NÃO ALTERE ESSA LINHA
#include "avaliacao_basica_controle.hpp"
#include "Processo.hpp"
#include "FilaProcessos.hpp"

using namespace std;

int main() {

    // Criando a Lista Encadeada
    FilaProcessos FilaDeProcessos;

    // Leitura dos caracteres dos comandos
    char data;
    while (cin >> data) {
        switch(data) {

            // Adicionar um Novo Processo
            case 'a': {
                string auxName;
                int auxPrio;
                cin >> auxName >> auxPrio;

                FilaDeProcessos.adicionar_processo(auxName, auxPrio);
                break;
            }

            // Remover um Processo em Ordem
            case 'r': {
                FilaDeProcessos.remover_processo_maior_prioridade();
                break;
            }

            // Remover por Id
            case 'i': {
                int auxId;
                cin >> auxId;
                FilaDeProcessos.remover_processo_por_id(auxId);
                break;
            }

            // Imprimir Estado atual 
            case 'p': {
                FilaDeProcessos.imprimir_fila();
                break;
            }

            // Imprimir Estimativa de Tempo
            case 'e': {
                int auxId;
                cin >> auxId;
                FilaDeProcessos.estimativa_tempo_para_execucao(auxId);
                break;
            }

            // Chamada da avaliação
            case 'b': {
                avaliacao_basica();
                break;
            }
        }
    }

    return 0;
}