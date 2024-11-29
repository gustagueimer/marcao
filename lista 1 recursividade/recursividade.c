#include <stdio.h>
#include <windows.h>
void anbt() {
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);
}
int somadorDeluxe(int numero) {
    if (numero == 1) {
        return 1;
    } else {
        return (numero + somadorDeluxe(numero-1));
    }
}
int main() {
    int liv;
    anbt();
    printf("somador de números de maneira recursiva deluxe\n");
    printf("escolha um número maior que 1 - ");
    scanf("%d", &liv);
    if (liv <= 1) {
        printf("numero não é maior que um >:(\n");
    } else {
        printf("resultado do somador deluxe: %d", somadorDeluxe(liv));
    }
    system("pause");
    return 0;
}