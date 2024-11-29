#include <stdio.h>
#include <windows.h>
//balls 101
void anbt() {
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);
}

void somador(int *a, int *b) {
    *a = *a + *b;
}

int main() {
    int oliv = 12;
    int oly = 5;

    int * ptrOly = &oly;
    int * ptrOliv = &oliv;

    somador(ptrOliv, ptrOly);

    printf("resultado de todo o bagulhonson: %i\n", oliv);

    system("pause");

    return 0;
}