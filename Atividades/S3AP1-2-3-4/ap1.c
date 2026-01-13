/*José e Maria são estudantes de programação e gostam de lançar desafios um para o outro. Certo dia, Maria lançou o seguinte desafio para José:

José, quero que você altere o valor armazenado por uma variável, que receberá o produto de sua multiplicação por um valor inteiro, 
a ser informado pelo usuário. Na tarefa, você poderá colocar mais linhas no código e usar a variável em uma operação matemática, 
desde que ela apareça após o sinal de igual. No entanto, você não pode usar essa variável antes do sinal de igual. 
O uso de um operador de indireção também é obrigatório. 

Por exemplo:

int resultado = variavel + 1; // ✅ pode, pois o nome `variavel` foi usado após o sinal de igual;
variavel = 2 + 2; ❌ // não pode, pois a `variavel` está à esquerda do sinal de igual.

Ao final, o seu programa deve exibir o valor de `variavel` após a multiplicação.

O código-base compartilhado por Mariana é:


#include<stdio.h>
#include<stdlib.h>
int main(void){
 float variavel = 7;
 int multiplicando;
 scanf("%d", &multiplicando);
 
 return 0;
}

Como ele deve ficar após a conclusão do desafio?*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    float variavel = 7;
    void *pvariavel = &variavel;

    int multiplicando;
    scanf("%d", &multiplicando);


    *((float*)pvariavel) *= multiplicando;

    printf("Variavel: %.2f", variavel);

    return 0;
}
