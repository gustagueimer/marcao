#include <stdio.h>
#include <windows.h>
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
int recursiveSommer(int vetor[], int tamanho) {
    if (tamanho == 1) {
        return vetor[0];
    } else {
        return (vetor[tamanho-1] + recursiveSommer(vetor, (tamanho-1)));
    }
}
int main() {
    anbt();
    int vSize;
    printf("defina o tamanho do vetor - ");
    scanf("%i", &vSize);
    int vector[vSize];
    printf("defina os valores do vetor: \n");
    getter(vector, vSize);
    printf("resultado da soma desnecessariamente complexa: %i\n", recursiveSommer(vector, vSize));
    system("pause");
}