/*Implemente um programa em C que, ao iniciar, leia na função main() dois números inteiros do teclado. O primeiro representa a quantidade de linhas e o
segundo a quantidade de colunas de uma matriz que será alocada dinamicamente. Assim como feito no exercício dos vetores, implemente uma função que recebe
esses dois números inteiros como parâmetro e aloca dinamicamente uma matriz. A matriz deve, obrigatoriamente, ser iniciada com zero.
*/

#include <stdio.h>
#include <stdlib.h>

int **CriarMatriz(int linhas, int colunas)
{
    int **matriz = (int **)calloc(linhas, sizeof(int *));

    for (int i = 0; i < linhas; i++)
    {
        matriz[i] = (int *)calloc(colunas, sizeof(int));
    };

    return matriz;
};

int main()
{
    int QtdLinha, Qtdcoluna;
    printf("\nLinhas: ");
    scanf("%d", &QtdLinha);

    printf("\nColunas: ");
    scanf("%d", &Qtdcoluna);

    printf("\n");

    int **Matriz = CriarMatriz(QtdLinha, Qtdcoluna);

    for (int i = 0; i < QtdLinha; i++)
    {
        for (int j = 0; j < Qtdcoluna; j++)
        {
            printf("%2d", *(*(Matriz + i) + j));
        }
        printf("\n");
    };

    for (int i = 0; i < QtdLinha; i++)
    {
        free(Matriz[i]);
    }
    free(Matriz);

    return 0;
};