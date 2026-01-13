#include <stdio.h>

void troca(int (*matriz1)[2], int (*matriz2)[2])
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            int temp;
            temp = *(*(matriz1 + i) + j);
            *(*(matriz1 + i) + j) = *(*(matriz2 + i) + j);
            *(*(matriz2 + i) + j) = temp;
        }
    }
}

int main()
{
    int matrizA[2][2], matrizB[2][2];

    printf("Insira os valores para a Matriz A:\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("A[%d][%d]: ", i, j);
            scanf("%d", (*(matrizA + i) + j));
        }
    }

    printf("Insira os valores para a Matriz B:\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("B[%d][%d]: ", i, j);
            scanf("%d", (*(matrizB + i) + j));
        }
    }

    printf("\nMatriz A antes da troca:\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("[%d][%d] => %d\n", i, j, *(*(matrizA + i) + j));
        }
    }

    printf("\nMatriz B antes da troca:\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("[%d][%d] => %d\n", i, j, *(*(matrizB + i) + j));
        }
    }

    // 🔄 Faz a troca
    troca(matrizA, matrizB);

    printf("\nMatriz A depois da troca:\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("[%d][%d] => %d\n", i, j, *(*(matrizA + i) + j));
        }
    }

    printf("\nMatriz B depois da troca:\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("[%d][%d] => %d\n", i, j, *(*(matrizB + i) + j));
        }
    }

    return 0;
}
