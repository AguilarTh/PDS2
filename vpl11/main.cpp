#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "ListaTarefas.hpp"


TEST_CASE("Concluir tarefa com ID inexistente") {
    ListaTarefas lista;

    // Adiciona apenas uma tarefa com ID 1
    lista.adicionar_tarefa("Teste");

    // Tenta concluir uma tarefa com ID inexistente (99)
    CHECK_FALSE(lista.concluir_tarefa(99));    // Não existe tarefa com ID 99 → deve retornar false
}

TEST_CASE("Repetir conclusão na mesma tarefa") {
    ListaTarefas lista;

    // Adiciona uma tarefa
    lista.adicionar_tarefa("Tarefa única");

    // Conclui a tarefa duas vezes
    CHECK(lista.concluir_tarefa(1));    // Primeira vez → deve retornar true
    CHECK(lista.concluir_tarefa(1));    // Segunda vez → também retorna true (idempotente)
    CHECK(lista.total_concluidas() == 1);    // Checa que apenas uma tarefa foi concluída no total
}

TEST_CASE("Lista vazia") {
    ListaTarefas lista;

    // Verifica que a lista começa vazia
    CHECK(lista.total_concluidas() == 0);    // Checa que não há nenhuma tarefa concluída
    CHECK(lista.total_pendentes() == 0);   // Checa que não há nenhuma tarefa pendente

    // Tenta concluir a tarefa 1 em uma lista vazia
    CHECK_FALSE(lista.concluir_tarefa(1));    // Tarefa 1 não existe → deve retornar false
}

TEST_CASE("Adicionar tarefas") {
    ListaTarefas lista;

    // Adiciona 3 tarefas à lista
    lista.adicionar_tarefa("Estudar PDS2");
    lista.adicionar_tarefa("Fazer compras");
    lista.adicionar_tarefa("Enviar email");

    // Verifica se o total de pendentes é 3
    CHECK(lista.total_pendentes() == 3);    // Deve haver 3 tarefas pendentes

    // Verifica se nenhuma tarefa foi concluída
    CHECK(lista.total_concluidas() == 0);    // Nenhuma foi concluída ainda
}

TEST_CASE("Concluir tarefas válidas") {
    ListaTarefas lista;

    // Adiciona duas tarefas
    lista.adicionar_tarefa("Tarefa 1");
    lista.adicionar_tarefa("Tarefa 2");

    // Conclui a tarefa 1
    CHECK(lista.concluir_tarefa(1));    // Deve retornar true (tarefa existe)
    
    CHECK(lista.total_concluidas() == 1);    // Agora há 1 tarefa concluída
    CHECK(lista.total_pendentes() == 1);    // E 1 pendente

    // Conclui a tarefa 2
    CHECK(lista.concluir_tarefa(2));    // Também deve retornar true
    
    CHECK(lista.total_concluidas() == 2);  // Agora há 2 concluídas
    CHECK(lista.total_pendentes() == 0);    // Nenhuma pendente
}
