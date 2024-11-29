#include <stdio.h>
#include <windows.h>
#include <windows.h>
//balls 101
void anbt() {
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);
}
int getter(int **matrix, int linhas, int colunas) {
    for (int x=0;x<linhas;x++) {
        for (int y=0;y<colunas;y++) {
            printf("informe um elemento da tabela numérica - ");
            scanf("%i", &matrix[x][y]);
        }
    }
    return 0;
}
int printer(int **matrix, int linhas, int colunas) {
    for (int x=0; x<linhas; x++) {
        for(int y=0; y<colunas; y++) {
            printf("%d ", matrix[x][y]);
        }
        printf("\n");
    }
    return 0;
}
int finder(int **matrix, int linhas, int colunas, int procurado) {
    for(int x=0; x<linhas; x++) {
        for(int y=0; y<colunas; y++) {
            if(matrix[x][y] == procurado) {
                return 1;
            }
        }
    }
    return 0;
}
int main() {
    anbt();
    int lines = 0;
    int rows = 0;
    printf("defina a quantidade de linhas da matriz - ");
    scanf("%i", &lines);
    printf("defina a quantidade de colunas da matriz - ");
    scanf("%i", &rows);
    //alocação dinamica da matrix (deu trabalho pra descobrir com faz)
    int **arreyy = (int **) malloc(lines * sizeof(int));
    for(int i=0; i<lines; i++) {
        arreyy[i] = (int *) malloc(rows * sizeof(int));
    }
    getter(arreyy, lines, rows);
    //printer(arreyy, lines, rows); debug: mostra a matriz inteira
    int foragido = 0;
    printf("insira o número que deseja procurar - ");
    scanf("%i", &foragido);
    if(finder(arreyy,lines, rows,  foragido) == 1) {
        printf("o número se encontra dentro da matrix \n");
    } else {
        printf("o número não se encontraa dentro da matrix \n");
    }
    //liberação de memoria da matrix (não deu tanto trabalho pra descobrir)
    printf("limpando a memória\n");
    free(*arreyy);
    printf("memória limpa :D \n");
    system("pause");
    return 0;
}