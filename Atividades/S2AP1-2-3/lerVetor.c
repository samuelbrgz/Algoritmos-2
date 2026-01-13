#include <stdio.h>

int main()
{
    int vetor[5];

    printf("insira 5 valores para o vetor: ");

    for (int i = 0; i < 5; i++)
    {
        scanf("%d", vetor + i);
    };

    printf("Vetor: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", *(vetor + i));
    };

    return 0;
}