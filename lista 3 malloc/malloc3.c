#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
//balls 101
void anbt() {
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);
}
int getter(int vetor[], int tamanho) {
    for (int i=0;i<tamanho;i++) {
        printf("informe um elemento da tabela numérica - ");
        scanf("%i", &vetor[i]);
    }
    return 0;
}
int leChecker(int vetor[], int tamanho) {
    int cheker = 0;
    printf("insira o número de comparação - ");
    scanf("%i", &cheker);
    printf("números que são multiplos de %i: \n", cheker);
    for (int i=0;i<tamanho;i++) {
        if (vetor[i] % cheker == 0) {
            printf("número %i\n", vetor[i]);
        }
    }
    return 0;
}
int main() {
    anbt();
    int tam;
    int *gol;
    printf("insira o tamanho do array - ");
    scanf("%i", &tam);
    gol = (int *) malloc(tam * sizeof(int));
    getter(gol, tam);
    leChecker(gol, tam);
    free(gol);
    system("pause");
    return 0;
}