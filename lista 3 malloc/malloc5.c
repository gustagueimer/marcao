#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
//balls 101
void anbt() {
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);
}
int printer(int vetor[], int tamanho) {
    for (int i=0;i<tamanho;i++) {
        printf("%i° número: %i\n", i+1, vetor[i]);
    }
    return 0;
}
int main() {
    anbt();
    int size = 0;
    int *realok = malloc((size+1) * sizeof(int));
    printf("pegador de valores até o usuário digitar qualquer número negativo deluxe\n");
    if(realok != NULL) {
        int input = 0;
        while(input >= 0) {
            printf("insira um número (negativo para) - ");
            scanf("%i", &input);
            if(input >= 0) {
                realok[size] = input;
                size++;
                realok = realloc(realok, (size+1) * sizeof(int));
            }
        }
    }
    printf("números digitados salvos na memória: \n");
    printer(realok, size);
    free(realok);
    system("pause");
    return 0;
}