#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef struct {
    char titulo[100];
    char canal[50];
    char link[100];
    int duracao;
} Video;

int main() {
    SetConsoleOutputCP(65001);

    Video lista_videos[5] = {
        {"Aprenda C em 10 Minutos", "Codigo Facil", "youtube.com/v1", 600},
        {"Meme do Gato", "Shorts Clips", "youtube.com/v2", 45},
        {"Tutorial de Ponteiros", "Engenharia Raiz", "youtube.com/v3", 180},
        {"Dicas de Produtividade", "Dev Life", "youtube.com/v4", 110},
        {"Review de Teclado", "Tech World", "youtube.com/v5", 900}
    };

    FILE *arquivo = fopen("videos.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo.\n");
        return 1;
    }

    for (int i = 0; i < 5; i++) {
        fprintf(arquivo, "%s,%s,%s,%d\n", 
                lista_videos[i].titulo, 
                lista_videos[i].canal, 
                lista_videos[i].link, 
                lista_videos[i].duracao);
    }

    printf("Dados gravados em 'videos.txt'.\n");
    fclose(arquivo);
    return 0;
}