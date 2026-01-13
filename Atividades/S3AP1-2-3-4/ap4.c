#include <stdio.h>

int main(void)
{
    int lin, col;

    printf("escolha o numero de linhas: ");
    scanf("%d", &lin);
    printf("escolha o numero de colunas: ");
    scanf("%d", &col);

    int matriz[lin][col];

    printf("\nDigite os elementos da matriz:\n");
    for (int i = 0; i < lin; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("Elemento[%d][%d]: ", i+1, j+1);
            scanf("%d", (*(matriz + i) + j));
        };
    };

     printf("\nElementos da matriz:\n");
    for (int i = 0; i < lin; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%4d", *(*(matriz + i) + j));
        };
        printf("\n");
    };
    return 0;
}