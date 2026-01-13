#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define MAX_VIDEOS 100

typedef struct {
    char titulo[100];
    char canal[50];
    char link[100];
    int duracao;
} Video;

int main() {
    SetConsoleOutputCP(65001);

    Video banco[MAX_VIDEOS];
    int qtd = 0;
    FILE *arquivo = fopen("videos.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo. Execute o registrador primeiro.\n");
        return 1;
    }

    while (fscanf(arquivo, "%[^,],%[^,],%[^,],%d\n", 
                  banco[qtd].titulo, 
                  banco[qtd].canal, 
                  banco[qtd].link, 
                  &banco[qtd].duracao) != EOF) {
        qtd++;
    }
    fclose(arquivo);

    printf("--- TODOS OS VIDEOS ---\n");
    for (int i = 0; i < qtd; i++) {
        printf("Titulo: %s | Canal: %s | Duracao: %ds\n", banco[i].titulo, banco[i].canal, banco[i].duracao);
    }

    char opcao;
    printf("\n--- FILTRO ---\n");
    printf("a) Duracao > 120s\n");
    printf("b) Duracao <= 120s\n");
    printf("Escolha: ");
    scanf(" %c", &opcao);

    printf("\n--- RESULTADO ---\n");
    for (int i = 0; i < qtd; i++) {
        if (opcao == 'a' || opcao == 'A') {
            if (banco[i].duracao > 120) {
                printf("%s (%ds)\n", banco[i].titulo, banco[i].duracao);
            }
        } 
        else if (opcao == 'b' || opcao == 'B') {
            if (banco[i].duracao <= 120) {
                printf("%s (%ds)\n", banco[i].titulo, banco[i].duracao);
            }
        }
    }

    return 0;
}