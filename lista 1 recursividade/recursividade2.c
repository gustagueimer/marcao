#include <stdio.h>
#include <windows.h>
void anbt() {
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);
}
int que(int n1, int n2) {
    if (n2 == 0) {
        return 1;
    } else {
        printf("operação %i: %i x %i\n", n2, n1, n2);
        return (n1 * que(n1, (n2-1)));
    }
}
int main() {
    int taco;
    int bell;
    anbt();
    printf("AÔÔÔÔÔÔÔ POTÊNCIA recursivo deluxe\n");
    printf("insira o número a ser potênciado - ");
    scanf("%i", &taco);
    printf("insira o número potênciador - ");
    scanf("%i", &bell);
    printf("aôôôôôôô potência: %d\n", que(taco, bell));
    system("pause");
}