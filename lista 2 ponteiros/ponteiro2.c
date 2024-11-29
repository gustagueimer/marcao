#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
//balls 101
void anbt() {
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);
}

int main() {
    anbt();

    int v1 = 69;
    int v2 = 420;

    /*
    printf("endereço v1: %p\n", &v1);
    printf("endereço v2: %p\n", &v2);
    */

    if(&v1 > &v2) {
        printf("o endereço da variável 1 é maior: %p\n", &v1);
    } else {
        printf("o endereço da variável 2 é maior: %p\n", &v2);
    }

    system("pause");

    return 0;
}