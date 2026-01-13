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

    Musica playlist_origem[5] = {
        {"Evidências", "Chitãozinho e Xororó", 1990},
        {"333", "Matuê", 2024},
        {"Bohemian Rhapsody", "Queen", 1975},
        {"Shape of You", "Ed Sheeran", 2017},
        {"Construção", "Chico Buarque", 1971}
    };

    FILE *arq_escrita = fopen("dados.txt", "wb");
    if (arq_escrita == NULL) {
        printf("Erro ao criar arquivo.\n");
        return 1;
    }

    fwrite(playlist_origem, sizeof(Musica), 5, arq_escrita);
    fclose(arq_escrita);

    printf("Dados gravados. Iniciando leitura...\n");

    Musica musica_lida;
    FILE *arq_leitura = fopen("dados.txt", "rb");
    if (arq_leitura == NULL) {
        printf("Erro ao abrir arquivo para leitura.\n");
        return 1;
    }

    int i = 1;
    while (fread(&musica_lida, sizeof(Musica), 1, arq_leitura) == 1) {
        printf("\nRegistro %d:\n", i);
        printf("Titulo: %s\n", musica_lida.titulo);
        printf("Artista: %s\n", musica_lida.artista);
        printf("Ano: %d\n", musica_lida.ano);
        i++;
    }

    fclose(arq_leitura);
    return 0;
}