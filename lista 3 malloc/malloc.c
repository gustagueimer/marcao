#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
//balls 101
void anbt() {
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);
}
int main() {
    anbt();
    int * mlc;
    int size;
    printf("insira o valor do vetor - ");
    scanf("%i", &size);
    mlc = (int *) malloc (size * sizeof(int));
    for(int i=0; i<size; i++) {
        printf("insira um número para o vetor[%i] - ", i+1);
        scanf("%i",  &mlc[i]);
    }
    int par = 0;
    int impar = 0;
    for(int i=0; i<size; i++) {
        if(mlc[i] % 2 == 0) {
            par++;
        } else {
            impar++;
        }
    }
    printf("quantidade de números pares no vetor: %i\n", par);
    printf("quantidade de números impares no vetor: %i\n", impar);
    free(mlc);
    system("pause");
    return 0;
}