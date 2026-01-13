/*Implemente, em C, uma função que recebe um número inteiro como entrada.
Este valor representará a quantidade de itens que serão armazenados em um vetor. Esta função deve alocar na memória,
de forma dinâmica, espaço suficiente para armazenar essa quantidade de itens. Mesmo que o vetor tenha sido criado por
uma função que não seja a `main()`, ele deve ser acessível e manipulável por qualquer outra função do programa.
Também é necessário que as demais funções tenham alguma forma (via programação) de saber se o vetor foi criado com sucesso ou não.

Na função `main()`, caso o vetor tenha sido alocado corretamente na memória,
você deve preencher o vetor com valores lidos pelo teclado. Após o preenchimento do vetor,
imprima o seu conteúdo considerando o seguinte formato:

[0] => 20
[1] => 10

É importante lembrar que este vetor deve ser alocado de forma dinâmica pela função criada neste exercício, não podendo ser alocado automaticamente.*/

#include <stdio.h>
#include <stdlib.h>

void criarvetor(int tam, int **vet)
{
    *vet = malloc(tam * sizeof(int));
}


int main(void)
{

    int tam, *vet = NULL;

    printf("\nQual tamanho você deseja para o vetor? ");
    scanf("%d", &tam);

    criarvetor(tam, &vet);

    if (vet == NULL)
    {
        printf("\nFalha na alocaçao de memória!\n");
        return 1;
    };


    // preenchendo o vetor

    printf("\nDigite os elementos do vetor: \n");

    for (int i = 0; i < tam; i++)
    {
        printf("[%d] => ", i);
        scanf("%d", (vet + i));

    }

    //printando 
    printf("\nElementos do vetor:\n");

    for (int i = 0; i < tam; i++)
    {
        printf("[%d] => %d\n", i, *(vet + i));
        
    }
    
    free(vet);


}
