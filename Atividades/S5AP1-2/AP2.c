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

int **RealocarMatriz(int **matriz, int linhas_antigas, int linhas, int colunas)
{

    if (linhas < linhas_antigas)
    {
        for (int i = linhas; i < linhas_antigas; i++)
        {
            free(matriz[i]);
        }
    }

    

    matriz = (int **)realloc(matriz, linhas * sizeof(int *));

    int limite = (linhas < linhas_antigas) ? linhas : linhas_antigas;

    for (int i = 0; i < limite; i++)
    {
        matriz[i] = (int *)realloc(matriz[i], colunas * sizeof(int));

        for (int j = 0; j < colunas; j++)
        {

            matriz[i][j] = 0;
        }
    }

    for (int i = linhas_antigas; i < linhas; i++)
    {
        matriz[i] = (int *)calloc(colunas, sizeof(int));
    };

    return matriz;
};

void imprimirmatriz(int **matriz, int linhas, int colunas)
{
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            printf("%2d", *(*(matriz + i) + j));
        }
        printf("\n");
    };
};

int main()
{
    int QtdLinha, Qtdcoluna;
    printf("\nLinhas: ");
    scanf("%d", &QtdLinha);

    printf("Colunas: ");
    scanf("%d", &Qtdcoluna);

    printf("\n");

    int **Matriz = CriarMatriz(QtdLinha, Qtdcoluna);

    imprimirmatriz(Matriz, QtdLinha, Qtdcoluna);

    int QtdLinha2;

    printf("\nLinhas: ");
    scanf("%d", &QtdLinha2);

    printf("Colunas: ");
    scanf("%d", &Qtdcoluna);

    printf("\n");

    Matriz = RealocarMatriz(Matriz, QtdLinha, QtdLinha2, Qtdcoluna);

    imprimirmatriz(Matriz, QtdLinha2, Qtdcoluna);

    for (int i = 0; i < QtdLinha2; i++)
    {
        free(Matriz[i]);
    }
    free(Matriz);

    return 0;
};