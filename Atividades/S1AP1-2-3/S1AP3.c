/*O CuiaBank é um banco digital criado por estudantes da UFMT, incluindo você, que ficou responsável por implementar uma função para controle de saques.
O banco oferece aos clientes um saldo especial (limite de crédito) que pode ser usado quando o saldo da conta não for suficiente para a operação.

Implemente uma função chamada sacar() que receba, por ponteiro, os endereços das variáveis saldo e saldo_especial, além do valor do saque solicitado.
Esta função deve:

Verificar se o valor do saque é menor ou igual à soma de saldo e saldo_especial;

Caso o saque seja possível, atualizar os valores apontados por esses ponteiros, descontando primeiro do saldo da conta e, se necessário, do saldo especial;

Retornar um valor que indique se o saque foi realizado com sucesso ou não.

Ao final das operações, o programa principal deve exibir o extrato bancário, mostrando o saldo restante e o saldo especial disponível.*/

#include <stdio.h>

int sacar(float *saque, float *saldo, float *saldo_especial)
{
    if (*saque <= *saldo)
    {
        *saldo -= *saque;
        return 1;
    }

    if (*saque <= *saldo + *saldo_especial)
    {
        *saque -= *saldo;
        *saldo = 0;
        *saldo_especial -= *saque;
        return 1;
    }

    printf("Saldo insuficiente!\n");

    return 0;
};

int main(void)
{
    float saldo = 1000, saldo_especial = 500, saque;
    printf("Digite o valor do saque: ");
    scanf("%f", &saque);

    int resultado = sacar(&saque, &saldo, &saldo_especial);

    if (resultado == 1)
    {
        printf("Saque realizado com sucesso!\n");
    }
    else
    {
        printf("Não foi possível realizar o saque!\n");
    }

    printf("Saldo: %.2f\nSaldo especial: %.2f\n", saldo, saldo_especial);

    return 0;
}
