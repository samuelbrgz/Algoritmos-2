#include <stdio.h>

int main()
{
    int matriz[3][3];

    printf("insira 3 valores para as 3 colunas da Matriz: ");

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", (*(matriz + i) + j));
        };
    };

    printf("Matriz: ");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("matriz[%d][%d] => %d\n", i, j, *(*(matriz + i) + j));
        };
    };

    return 0;
}