#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TAM 10

typedef struct
{
    int idade;
    int chave;
    char nome[50];
    char motivo[300];
} PACIENTE;

typedef struct
{
    PACIENTE pac[TAM];
    int inicio;
    int qtde;
} FILA;

void inicializaFila(FILA *f)
{
    f->inicio = 0;
    f->qtde = 0;
}

int filaVazia(FILA *f)
{
    return (f->qtde == 0);
}

int filaCheia(FILA *f)
{
    return (f->qtde == TAM);
}

bool inserirfila(FILA *f, PACIENTE p)
{
    if (f->qtde < TAM)
    {
        int pos = (f->inicio + f->qtde) % TAM;
        f->pac[pos] = p;
        f->qtde++;
        return true;
    };
    return false;
}

bool AtenderPaciente(FILA *f, PACIENTE *p)
{
    if (f->qtde > 0)
    {

        *p = f->pac[f->inicio];

        printf("\nPaciente atendido:\n");
        printf("Nome: %s\n", p->nome);
        printf("Idade: %d\n", p->idade);
        printf("Motivo da consulta: %s\n", p->motivo);

        f->inicio = (f->inicio + 1) % TAM;
        f->qtde--;
        return true;
    }

    return false;
}

bool consultarinfo(FILA *f)
{
    if (f->qtde > 0)
    {
        printf("\n----Informações---\n");
        printf("Nome: %s\n", f->pac[f->inicio].nome);
        printf("Idade: %d\n", f->pac[f->inicio].idade);
        printf("Motivo da Consulta: %s\n", f->pac[f->inicio].motivo);

        return true;
    }
    printf("A fila está vazia!");
    return false;
}

int main()
{

    FILA fila;
    inicializaFila(&fila);

    int opcao;
    PACIENTE p_temp;

    do
    {
        printf("\n--- CLINICA MEDICA ---\n");
        printf("1. Inserir Paciente\n");
        printf("2. Chamar Proximo\n");
        printf("3. Consultar Proximo (Espiar)\n");
        printf("4. Encerrar\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao)
        {
        case 1: // inserir
            if (!filaCheia(&fila))
            {
                printf("Nome: ");
                scanf("%49s", p_temp.nome);

                printf("Idade: ");
                scanf("%d", &p_temp.idade);
                getchar();

                printf("Motivo da consulta: ");
                fgets(p_temp.motivo, sizeof(p_temp.motivo), stdin);

                inserirfila(&fila, p_temp);
            }
            else
            {
                printf("Erro: A fila esta cheia.");
            };

            break;

        case 2: //"Remover"
            if (!filaVazia(&fila))
            {
                AtenderPaciente(&fila, &p_temp);
            }
            else
            {
                printf("Erro: A fila vazia");
            }
            break;

        case 3:

            if (!filaVazia(&fila))
            {
                consultarinfo(&fila);
            }
            else
            {
                printf("Erro: A fila vazia");
            }
            break;

        case 4:
            printf("Encerrando...");
            break;
        default:
            break;
        }

    } while (opcao != 4);
}