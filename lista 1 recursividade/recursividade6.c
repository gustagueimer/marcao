#include <stdio.h>
#include <windows.h>
//balls 101
void anbt() {
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);
}

int strangeSomer(int base) {
    if (base == 0) {
        return 0;
    } else {
        return (base % 10) + strangeSomer(base / 10);
    }
}

int main() {
    anbt();
    int numero = 0;
    printf("insista um número inteiro - ");
    scanf("%i", &numero);
    printf("resultado: %i\n", strangeSomer(numero));
    system("pause");
    return 0;
}