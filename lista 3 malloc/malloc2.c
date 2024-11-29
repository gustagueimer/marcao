#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
//balls 101
void anbt() {
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);
}
void printfwithoutvowels(char *string) {
    printf("a palavra sem nenhuma vogal: ");
    for(int i=0; string[i]!='\0'; i++) {
        switch(string[i]) {
            case 'a': break;
            case 'e': break;
            case 'i': break;
            case 'o': break;
            case 'u': break;
            default: printf("%c", string[i]);
        }
    }
    printf("\n");
}
int main() {
    anbt();
    char *clm;
    int ezis;
    printf("insira o tamanho do vetor de caracteres (também conhecido como string) - ");
    scanf("%i", &ezis);
    clm = (char *) malloc ((ezis + 1) * sizeof(char));
    printf("insira a palavra - ");
    scanf("%s", clm);
    /*  //método defasado//
    for(int i=0; i<=ezis; i++) {
        if (i != ezis) {
            printf("insira uma letra :");
            scanf(" %c", &clm[i]);
        } else {
            clm[i] = '\0';
        }
    }*/
    //printf("%s\n", clm);    //mostrar a palavra normal
    printfwithoutvowels(clm);
    free(clm);
    system("pause");
    return 0;
}