#include <stdio.h>
#include <windows.h>
void anbt() {
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);
}
int multRecursiva(int numero, int multiplicador) {
    if (multiplicador == 1) {
        return numero;
    } else {
        return (numero + multRecursiva(numero, (multiplicador -1)));
    }
}
int main(){
    int mult;
    int melt;
    anbt();
    printf("insira o número a ser multiplicado - ");
    scanf("%i", &melt);
    printf("insira o número multiplicador - ");
    scanf("%i", &mult);
    printf("resultado dessa multiplicassão desnecessariamente complicada: %i\n", multRecursiva(melt, mult));
    system("pause");
}
