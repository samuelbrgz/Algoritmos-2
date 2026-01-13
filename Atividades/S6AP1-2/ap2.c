/*Implemente, em C, um programa que usa estruturas de dados para armazenar dados que representem a seguinte ocorrência do mundo real:

Um estudante de graduação pode ir à biblioteca de sua universidade para realizar o empréstimo de um livro.
O empréstimo pode estar em andamento ou já estar finalizado.

Registre os dados que possibilitem representar uma ocorrência de um empréstimo, contendo dados do estudante envolvido,
do livro e o status do empréstimo (em andamento ou finalizado). Depois, imprima os dados desse empréstimo, indicando qual livro foi emprestado por um estudante.

Por exemplo:
Joaquim (RGA 1234) emprestou o livro "AED2 é legal" (Autor: Renan).*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STATUS_ANDAMENTO 1
#define STATUS_FINALIZADO 0

typedef struct
{
    char rga[100];
    char nome[20];
    
} Estudante;

typedef struct
{
    char autor[100];
    char titulo[100];
    
} Livro;

typedef struct 
{
    Estudante estudante;
    Livro livro;
    int status;

} emprestimo;

void limparQuebra(char *str) {
    size_t i = 0;
    while (str[i] != '\0') {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
        i++;
    }
}

int main(void){

    emprestimo e;

    printf("\n---- Emprestimo de livro ----\n\n");
    printf("Nome: ");
    fgets(e.estudante.nome, 100, stdin);
    limparQuebra(e.estudante.nome);

    printf("RGA: ");
    fgets(e.estudante.rga, 100, stdin);
    limparQuebra(e.estudante.rga);

    printf("Titulo do livro: ");
    fgets(e.livro.titulo, 100, stdin);
    limparQuebra(e.livro.titulo);

    printf("Autor do livro: ");
    fgets(e.livro.autor, 100, stdin);
    limparQuebra(e.livro.autor);

    e.status = STATUS_ANDAMENTO;

    printf("\n=== Comprovante ===\n");
    printf("%s (RGA %s) emprestou o livro \"%s\" (Autor: %s).\n",
           e.estudante.nome,
           e.estudante.rga,
           e.livro.titulo,
           e.livro.autor);
    
    
    printf("Situacao: %s\n", (e.status == STATUS_ANDAMENTO) ? "Em Andamento" : "Finalizado");

    return 0;
}
