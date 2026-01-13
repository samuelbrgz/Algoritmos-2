#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>

#define TAM 5

// definição de tipos

typedef struct
{
    char nome[21];
    char autor[21];
} Musica;

typedef struct
{
    Musica musica[TAM];
    int topo;

} Playlist;

// funções

void inicializar(Playlist *p)
{
    p->topo = 0;
};

bool empilhar(Playlist *p, Musica m)
{
    if (p->topo < TAM)
    {
        p->musica[p->topo] = m;
        p->topo++;

        return true;
    }
    return false;
};

bool apagar(Playlist *p, Playlist *m)
{

    if (m->topo < TAM && p->topo > 0)
    {

        m->musica[m->topo] = p->musica[p->topo - 1];
        p->topo--;
        m->topo++;
        return true;
    }
    return false;
}

bool reverter(Playlist *p, Playlist *m)
{

    if (p->topo < TAM && m->topo > 0)
    {

        p->musica[p->topo] = m->musica[m->topo - 1];
        m->topo--;
        p->topo++;
        return true;
    }
    return false;
}

void imprimir(Playlist *p)
{
    printf("\n-------Playlist--------");
    for (int i = p->topo - 1; i >= 0; i--)
    {
        printf("\nMusica: %s\nAutor: %s\n", p->musica[i].nome, p->musica[i].autor);
    }
}

// função main

int main()
{
    SetConsoleOutputCP(65001);

    Playlist principal;
    Playlist apagada;
    int escolha;

    inicializar(&principal);
    inicializar(&apagada);

    empilhar(&principal, (Musica){"Evidencias", "Chitaozinho e xororo"});
    empilhar(&principal, (Musica){"333", "Matue"});
    empilhar(&principal, (Musica){"Luxuria", "Matue Ft. Xama"});
    empilhar(&principal, (Musica){"The perfect pair", "beabadoobee"});
    empilhar(&principal, (Musica){"California love", "2pac"});

    

    imprimir(&principal);


    printf("\n------- Playlist Manager --------\n");

    do {
        printf("\n[MODO REMOÇÃO] Deseja apagar a música do topo?\n");
        printf("1 - Sim\n2 - Sair deste menu\n> ");
        scanf("%d", &escolha);

        if (escolha == 1) {
            
            bool resultado = apagar(&principal, &apagada); 
            
            if (resultado == true) {
                printf(">> Sucesso: Música movida para a lixeira.\n");
                
            } else {
                printf(">> Erro: Playlist vazia ou Lixeira cheia!\n");
            }
        }
        imprimir(&principal);
        
    } while (escolha != 2);



    escolha = 0; 

    do {
        printf("\n[MODO RECUPERAÇÃO] Deseja desfazer (trazer da lixeira)?\n");
        printf("1 - Sim\n2 - Sair deste menu\n> ");
        scanf("%d", &escolha);

        if (escolha == 1) {
            
            bool resultado = reverter(&principal, &apagada);

            if (resultado == true) {
                printf(">> Sucesso: Música recuperada para a playlist!\n");
            } else {
                printf(">> Erro: Nada na lixeira ou Playlist cheia!\n");
            }
        }
        imprimir(&principal);


    } while (escolha != 2);
}