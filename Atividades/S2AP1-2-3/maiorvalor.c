/*Crie um programa contendo três vetores (A, B e C), de tamanho igual. Para os vetores A e B, os valores devem ser lidos do teclado.

Em seguida, implemente uma função que recebe os três vetores. Cada posição do vetor C deve ser preenchido com o maior valor do vetor A ou B naquela mesma posição.

Use aritmética de ponteiros para efetuar essas operações.*/

#include <stdio.h>

void troca(int *vetor1, int *vetor2, int *vetor3)
{
    for (int i = 0; i < 5; i++)
    {
        *(vetor3+i) = *(vetor1+i) >= *(vetor2+i)? *(vetor1+i):*(vetor2+i) ;
    }
    
}

int main()
{
    int vetorA[5], vetorB[5], vetorC[5];

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

    troca(vetorA, vetorB, vetorC);

    printf("\n\n Apos troca de valores\n");

    printf("\nVetorC: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", *(vetorC + i));
    };

  

    return 0;
}