#include <stdio.h>
#include <windows.h>
void anbt() {
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);
}
int grupoFormer(int n, int k) {
    if (k==1) {
        return n;
    } else if (k==n) {
        return 1;
    } else {
        return grupoFormer(n - 1, k - 1) + grupoFormer(n-1, k);
    }
 }
int main() {
    anbt();
    int pessoas;
    int grupos;
    printf("insira a quantidade de pessoas - ");
    scanf("%i", &pessoas);
    printf("insira a quantidades de grupos - ");
    scanf("%i", &grupos);
    printf("resultado? %i", grupoFormer(pessoas, grupos));
}