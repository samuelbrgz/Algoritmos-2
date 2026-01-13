#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define TAM 10

// definição de tipos e estruturas
typedef struct 
{
    int apt;
    char placa[10];
} Carro;

typedef struct 
{
    Carro carro[TAM];
    int topo;
} Pilha;

// inicializa pilha
void inicializarpilha(Pilha *p){
    p->topo = 0;
}

// empilha carro
bool empilhar(Pilha *p, Carro c){
    if (p->topo < TAM){
        p->carro[p->topo] = c;
        p->topo++;
        return true;
    }
    return false;
}

// desempilha carro
bool apagar(Pilha *p, Pilha *c){
    if (p->topo > 0){
        c->carro[p->topo] = p->carro[p->topo - 1];
        p->topo--;
        return true;
    }
    return false;
}

// função principal do problema
void estacionamento(char *P, Pilha *p)
{
    Carro removido;
    int i = 1;

    // Retira carros até achar a placa
    while (p->topo > 0 && strcmp(P, p->carro[p->topo - 1].placa) != 0)
    {
        desempilhar(p, &removido);
        printf("Retirar carro %d (apt %d) para liberar passagem.\n",
               i, removido.apt);
        i++;
    }

    // Se chegou ao fim e não achou o carro
    if (p->topo == 0)
    {
        printf("Carro com placa %s nao encontrado.\n", P);
        return;
    }
}

// MAIN
int main(void){

    Pilha p;
    char placa[10];

    inicializarpilha(&p);

    // carros cadastrados
    empilhar(&p, (Carro){1 , "ABC123"});
    empilhar(&p, (Carro){2 , "ABC193"});
    empilhar(&p, (Carro){3 , "ABC113"});
    empilhar(&p, (Carro){4 , "APC103"});
    empilhar(&p, (Carro){5 , "AKC143"});
    empilhar(&p, (Carro){6 , "AJC133"});
    empilhar(&p, (Carro){7 , "AMC183"});
    empilhar(&p, (Carro){8 , "AHC173"});
    empilhar(&p, (Carro){9 , "AVC163"});
    empilhar(&p, (Carro){10 , "AMC193"});

    printf("Insira a placa do carro a ser retirado: ");
    scanf("%9s", placa);

    estacionamento(placa, &p);

    return 0;
}
