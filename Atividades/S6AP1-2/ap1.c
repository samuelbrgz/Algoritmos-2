/*Imagine que você tenha sido contratado(a) por uma empresa que produz celulares para desenvolver o sistema de controle da agenda telefônica.
Como o dispositivo a ser lançado é de baixo custo, a agenda telefônica armazena apenas nome e sobrenome do contato, além do número de telefone e do endereço de e-mail.
Mostre como a linguagem C poderia ser utilizada para implementar essa solução, considerando o uso adequado de estruturas de dados. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome[10];
    char sobrenome[10];
    char numero[15];
    char email[20];

} Pessoa;

void alocarvetor(int tamanho, Pessoa **lista){
   *lista = (Pessoa*)calloc(tamanho, sizeof(Pessoa));

   if (*lista == NULL) {
        fprintf(stderr, "Erro fatal: Falha na alocacao de memoria.\n");
        exit(1);
    }
};

int main()
{
    int tamanho;
    Pessoa *lista = NULL;

    printf("\n----Lista Telefonica----\n");
    printf("Quantas pessoas deseja cadastrar?\n");
    scanf("%d", &tamanho);
    while (getchar() != '\n');

    alocarvetor(tamanho, &lista);

    printf("\n----Lista Telefonica----\n");

    for (int i = 0; i < tamanho; i++)
    {
        printf("\n-------Pessoa numero: %d-------\n", i + 1);
        printf("Nome: ");
        fgets(lista[i].nome, 10, stdin);
        lista[i].nome[strcspn(lista[i].nome, "\n")] = 0;

        printf("Sobrenome: ");
        fgets(lista[i].sobrenome, 10, stdin);
        lista[i].sobrenome[strcspn(lista[i].sobrenome, "\n")] = 0;

        printf("Numero: ");
        fgets(lista[i].numero, 15, stdin);
        lista[i].numero[strcspn(lista[i].numero, "\n")] = 0;

        printf("Email: ");
        fgets(lista[i].email, 20, stdin);
        lista[i].email[strcspn(lista[i].email, "\n")] = 0;
    }
    printf("\n----Lista Telefonica Atualizada----\n");

    for (int i = 0; i < tamanho; i++)
    {
        printf("\n------- Pessoa numero: %d -------\n", i + 1);
        printf("Nome: %s\n", lista[i].nome);
        printf("Sobrenome: %s\n", lista[i].sobrenome);
        printf("Mumero: %s\n", lista[i].numero);
        printf("Email: %s\n", lista[i].email);
    }

    free(lista);
    lista = NULL;

    return 0;
}