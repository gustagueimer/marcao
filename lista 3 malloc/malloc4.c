#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
//balls 101
void anbt() {
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);
}
int getter(int vetor[], int tamanho) {
    for (int i=0;i<tamanho;i++) {
        printf("informe um número de 1 a 9 - ");
        scanf("%i", &vetor[i]);
    }
    return 0;
}
int printer(int vetor[], int tamanho) {
    for (int i=0;i<tamanho;i++) {
        printf("%i° número: %i\n", i+1, vetor[i]);
    }
    return 0;
}
int loteriaOnline(int *aposta) {
    srand(time(NULL));
    int loterry[6] =  {0}; 
    for(int i=0; i<6; i++) {
        loterry[i] = rand() % 9;
    }
    int phoenix = 0;
    for(int i=0; i<6; i++) {
        if(loterry[i] == aposta[i]) {
            phoenix++;
        }
    }
    int *storage = malloc(phoenix * sizeof(int));
    int strpos = 0;
    for(int i=0; i<6; i++) {
        if(loterry[i] == aposta[i]) {
            storage[strpos] = aposta[i];
            strpos++;
        }
    }
    printf("números sorteados:\n");
    printer(loterry, 6);
    printf("números apostados:\n");
    printer(aposta, 6);
    printf("números corretos:\n");
    if (phoenix != 0) {
        for(int i=0; i<phoenix; i++) {
            printf("número %i \n", storage[i]);
        }
    } else {
        printf("nenhum número acertado :(\n");
    }
    free(storage);
    return 0;
}
int main() {
    anbt();
    int aposta[6] = {0};
    printf("loteria online deluxe\n");
    printf("escolha os seus números da sorte:\n");
    getter(aposta, 6);
    loteriaOnline(aposta);
    system("pause");
    return 0;
}