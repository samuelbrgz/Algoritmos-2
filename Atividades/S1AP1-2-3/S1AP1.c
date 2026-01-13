/*Escreva um procedimento que utilize ponteiros para calcular quanto tempo falta para uma pessoa se aposentar.
  Esse procedimento deve receber, por ponteiro, duas variáveis do tipo inteiro:

idade: representa a idade atual da pessoa;
sexo: representa o sexo da pessoa (por exemplo, 1 para masculino e 2 para feminino).
O procedimento deve atualizar diretamente o valor apontado por idade,
 substituindo-o pelo tempo restante até a aposentadoria, conforme as regras abaixo:

Mulheres se aposentam aos 60 anos;
Homens se aposentam aos 65 anos.
Caso a pessoa já tenha atingido a idade de aposentadoria, a variável deve ser atualizada para
 0. Ao final, o método principal deve exibir o tempo necessário para a aposentadoria.*/

#include <stdio.h>

void aposento(int *idade, int *sexo)
{
    if (*sexo == 1)
    {
        *idade -= 65;
        *idade >= 0 ? *idade = 0 : 0 ;
        *idade = *idade*-1;
    } else {
        *idade -= 60;
        *idade >= 0 ? *idade = 0 : 0 ;
        *idade = *idade*-1;
    };

    printf("faltam %d anos para voce se aposentar.", *idade);

};

int main(void)
{
    int sexo, idade;

    printf("Idade: ");
    scanf("%d", &idade);

    printf("Sexo: ");
    scanf("%d", &sexo);

    aposento(&idade, &sexo);

    return 0;
}

