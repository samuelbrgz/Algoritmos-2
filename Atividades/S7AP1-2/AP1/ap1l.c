#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef struct {
    char titulo[50];
    char artista[50];
    int ano;
} Musica;

int main() {
    SetConsoleOutputCP(65001);

    Musica m;
    FILE *arquivo = fopen("dados.txt", "rb");

    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo. Execute o gravador primeiro.\n");
        return 1;
    }

    int i = 1;
    while (fread(&m, sizeof(Musica), 1, arquivo) == 1) {
        printf("\nRegistro %d:\n", i);
        printf("Titulo: %s\n", m.titulo);
        printf("Artista: %s\n", m.artista);
        printf("Ano: %d\n", m.ano);
        i++;
    }

    fclose(arquivo);
    return 0;
}