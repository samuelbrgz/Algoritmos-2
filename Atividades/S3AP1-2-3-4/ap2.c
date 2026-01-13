/*Odete, uma importante empresária brasileira, viaja bastante para diferentes capitais com um
jatinho particular fretado por uma empresa de táxi aéreo, a Agostinho Transportes Aéreos (ATA).
Dentre as capitais que Odete costuma visitar, cinco são bastante frequentes: Cuiabá, Goiânia, São Paulo, Curitiba e Rio de Janeiro
(nesta ordem, da mais frequente para a menos frequente). Joilson, estagiário de Tecnologia da Informação da empresa de Odete preparou um programa simples
para calcular o custo de cada viagem. Basicamente, ele criou um vetor que armazena o valor cobrado pela empresa de táxi aéreo para cada um desses destinos.
 A cada seis meses, entretanto, o custo é reajustado em um determinado percentual. Joilson implementou uma função/procedimento para reajustar todos os valores.
 Acontece que ele foi demitido porque chegou atrasado e, com a revolta, apagou esse recurso do programa.
 Você, que não sabia de toda essa história, entrou inocente na empresa para substituir Joilson e recebeu como primeira missão refazer este trabalho.

Considerando o enunciado apresentado, bem como a necessidade de implementação de um recurso, apresente um código em C capaz de atender, com as melhores práticas de programação,
as demandas do caso apresentado. O programa deve exibir, ao final, os valores reajustados. Para percorrer o vetor, use aritmética de ponteiros.*/

#include <stdio.h>

void proc(float *custos, float ajuste)
{
    for (int i = 0; i < 5; i++)
    {
        *(custos + i) += *(custos + i) * ajuste;
    }
};

int main(void)
{
    float custos[5] = {1000.0, 2000.0, 3000.0, 4000.0, 5000.0};
    char *destino[5] = {"Cuiaba", "Goiania", "Sao paulo", "Curitiba", "Rio de janeiro"};
    float ajuste = 0.10;

    printf("\ncustos antes do ajuste de %.2f porcento: \n", ajuste * 100);
    for (int i = 0; i < 5; i++)
    {
        printf("%s: %.2f\n ", *(destino + i), *(custos + i));
    };

    proc(custos, ajuste);

    printf("\ncustos antes do ajuste de %.2f porcento: \n", ajuste * 100);
    for (int i = 0; i < 5; i++)
    {
        printf("%s: %.2f\n", *(destino + i), *(custos + i));
    };
    return 0;
}