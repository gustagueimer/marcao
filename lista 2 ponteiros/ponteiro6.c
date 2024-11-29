#include <stdio.h>
#include <windows.h>
//balls 101
void anbt() {
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);
}

void fractured(float base, int *whole, float *sale) {
    *whole = (int)base;
    *sale = base - *whole;
}

int main() {
    anbt();

    float numero = 0;
    int intero = 0;
    float floate = 0;

    printf("insira um número quebrado - ");
    scanf("%f", &numero);

    int *ptrIntero = &intero;
    float *ptrFloate = &floate;

    fractured(numero, ptrIntero, ptrFloate);

    printf("resultados: \n");
    printf("número inteiro: %i\n", intero);
    printf("o quebrado: %.2f\n", floate);

    system("pause");

    return 0;
}