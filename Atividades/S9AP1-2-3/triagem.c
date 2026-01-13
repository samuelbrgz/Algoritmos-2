#include <stdio.h>
#include <stdlib.h> // Necessária para calloc e free
#include <stdbool.h>

/* * JUSTIFICATIVA: A estrutura de Fila Dinâmica Encadeada é a mais adequada para este cenário 
 * pois permite que o sistema registre um número indefinido de pacientes (alocação dinâmica), 
 * atendendo a demandas imprevisíveis como epidemias. Além disso, garante o atendimento 
 * por ordem de chegada (FIFO - First In, First Out).
 */

// definição de tipos

typedef struct
{
    int codigo; // chave
    char nome[50];
    char cpf[20];
    char sintoma[50];
} PACIENTE; // Armazena os dados brutos do paciente em um bloco único.

typedef struct item
{
    PACIENTE p;
    struct item *prox;
} ITEM; // Nó da lista: une os dados ao ponteiro que aponta para o próximo.

typedef struct
{
    ITEM *inicio;
    ITEM *fim;
} FILA; // Descritor: gerencia o acesso rápido ao início e ao fim da estrutura.

// funções

void inicializar(FILA *f)
{
    f->inicio = NULL;
    f->fim = NULL;
}

ITEM *cadastrarPaciente(PACIENTE p)
{
    ITEM *novo = (ITEM *)calloc(1, sizeof(ITEM));
    if (novo)
    {
        novo->p = p;
        novo->prox = NULL;
    }
    return novo;
}

void adicionarPaciente(FILA *f, PACIENTE p)
{
    ITEM *novo = cadastrarPaciente(p); // Corrigido: 'c' minúsculo para bater com a definição
    if (!novo)
        return;

    if (!f->fim)
    {
        f->inicio = novo;
        f->fim = novo;
    }
    else
    {
        f->fim->prox = novo;
        f->fim = novo;
    }
}

void chamar_proximo(FILA *f) {
    if (f->inicio) {
        ITEM *aux = f->inicio;

        printf("--- CHAMANDO PRÓXIMO ---\n");
        printf("Codigo: %d\n", aux->p.codigo);
        printf("Nome: %s\n", aux->p.nome);
        printf("CPF: %s\n", aux->p.cpf);
        printf("Sintoma: %s\n", aux->p.sintoma);
        printf("------------------------\n");
       
        f->inicio = f->inicio->prox;
        if (!f->inicio) {
            f->fim = NULL;
        }

        free(aux); // Libera a memória ocupada pelo paciente atendido

         
    }
    else {
        printf("Fila vazia!\n");
        
    }
}

int main (){
    FILA f;

    inicializar(&f);

    // simulando a chegada dos pacientes diretamente

    PACIENTE p1 = {1, "Samuel", "111.111.111.11", "Febre"};
    PACIENTE p2 = {2, "Vinicius", "222.222.222.22", "Tosse"};
    PACIENTE p3 = {3, "Borges", "333.333.333.33", "Dor"};

    adicionarPaciente(&f, p1);
    adicionarPaciente(&f, p2);
    adicionarPaciente(&f, p3);

    printf("Simulacao: 3 pacientes inseridos.\n\n");

    // Simulando o atendimento de 2 deles
    chamar_proximo(&f);
    chamar_proximo(&f);

    return 0;
}