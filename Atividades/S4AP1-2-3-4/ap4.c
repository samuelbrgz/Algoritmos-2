#include <stdio.h>
#include <stdlib.h>

void criarvetor(int tam, int **vet)
{
    *vet = malloc(tam * sizeof(int));
}

int mudartamanhovetor(int newtam, int **vet)
{
    int *vet_temp = NULL;

    vet_temp = realloc(*vet, newtam * sizeof(int));
    if (vet_temp == NULL)
    {
        return 0;
    }
    *vet = vet_temp;
    return 1;
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

    // printando
    printf("\nElementos do vetor:\n");

    for (int i = 0; i < tam; i++)
    {
        printf("[%d] => %d\n", i, *(vet + i));
    }

    int newtam;

    printf("\nQual o novo tamanho que você deseja para o vetor? ");
    scanf("%d", &newtam);

    int sucesso = mudartamanhovetor(newtam, &vet);

    if (sucesso == 0)
    {
        free(vet);
        return 1;
    }

    // preenchendo o vetor

    printf("\nDigite os elementos do novo vetor: \n");

    for (int i = 0; i < newtam; i++)
    {
        printf("[%d] => ", i);
        scanf("%d", (vet + i));
    }

    printf("\nElementos do vetor:\n");

    for (int i = 0; i < newtam; i++)
    {
        printf("[%d] => %d\n", i, *(vet + i));
    }
    free(vet);
}
