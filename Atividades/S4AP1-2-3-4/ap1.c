/*Implemente um programa que define três variáveis (int ou float), sem atribuir valores a elas. Em seguida, o programa define um vetor de ponteiros, que contém os endereços
dessas três variáveis. Após essa operação, o programa solicita que o usuário digite o valor a ser atribuído para cada uma das variáveis. Terminada a leitura,
o programa deve fazer a impressão dos valores das variáveis a partir do vetor, percorrendo-o com aritmética de ponteiros. */

#include <stdio.h>

int main(void)
{
    int var1, var2, var3;
    int *vetPont[3] = {&var1, &var2, &var3};

    printf("\nValor da primeira variavel: ");
    scanf("%d", &var1);

    printf("\nValor da segunda variavel: ");
    scanf("%d", &var2);

    printf("\nValor da terceira variavel: ");
    scanf("%d", &var3);

    printf("\nValores lidos: ");
    for (int i = 0; i < 3; i++)
    {
        printf("%d ", *(*(vetPont + i)));
    };
    
}
