/*Crie um programa contendo dois vetores (A e B), de tamanho igual, cujos valores foram lidos do teclado.
Em seguida, implemente uma função que recebe esses vetores e troque os valores do vetor A com os valores do vetor B.
Use aritmética de ponteiros para efetuar essas operações.*/

#include <stdio.h>

void troca(int *vetor1, int *vetor2)
{
    for (int i = 0; i < 5; i++)
    {
        int temp;

        temp = *(vetor1 + i);
        *(vetor1 + i) = *(vetor2 + i);
        *(vetor2 + i) = temp;
    }
    
}

int main()
{
    int vetorA[5], vetorB[5];

    printf("insira 5 valores para o vetorA: ");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", vetorA + i);
    };

    printf("insira 5 valores para o vetorB: ");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", vetorB + i);
    };

    printf("\nVetorA: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", *(vetorA + i));
    };

    printf("\nVetorB: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", *(vetorB + i));
    };

    troca(vetorA, vetorB);

    printf("\n\n Apos troca de valores\n");

    printf("\nVetorA: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", *(vetorA + i));
    };

    printf("\nVetorB: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", *(vetorB + i));
    };

    return 0;
}