/*Implemente, na linguagem de programação C, um programa que contenha duas variáveis: uma do tipo inteiro e outra com ponto flutuante. Compare os endereços
 dessas variáveis e exiba, de uma só vez, o maior endereço de memória, junto ao valor que ele armazena.*/

#include <stdio.h>

int main(void)
{
    int var1=1;
    float var2=2;

    int *p1 = &var1;
    float *p2 = &var2;

    if ((void*)p1 > (void*)p2)
    {
        
        printf("%p %d", p1, *p1);
        
    } else{
        printf("%p %f", p2, *p2);
    };

    return 0;
}
