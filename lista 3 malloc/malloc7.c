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
int showBiggests(int **matrix, int linhas, int colunas, int biggests) {
    for(int x=0; x<linhas; x++) {
        for(int y=0; y<colunas; y++) {
            if(matrix[x][y] == biggests) {
                printf(" maior número: %i, posição na matriz: [%i][%i] \n", biggests, x+1, y+1);
                return 0;
            }
        }
    }
    return 1;
}
int findBiggests(int **matrix, int linhas, int colunas) {
    int biggest[2] = {0};
    for(int x=0; x<linhas; x++) {
        for(int y=0; y<colunas; y++) {
            if(matrix[x][y] > biggest[0]) biggest[0] = matrix[x][y];
        }
    }
    for(int x=0; x<linhas; x++) {
        for(int y=0; y<colunas; y++) {
            if(matrix[x][y] > biggest[1] && matrix[x][y] != biggest[0]) biggest[1] = matrix[x][y];
        }
    }
    printf("maior");
    showBiggests(matrix, linhas, colunas, biggest[0]);
    printf("menor");
    showBiggests(matrix, linhas, colunas, biggest[1]);
    return 0;
}
int main() {
    anbt();
    int lines = 0;
    int rows = 0;
    printf("defina o número de linhas da matriz - ");
    scanf("%i", &lines);
    printf("defina o número de colunas da matriz - ");
    scanf("%i", &rows);
    int **table = (int**) malloc(lines * sizeof(int));
    for(int i=0; i<lines; i++) {
        table[i] = (int *) malloc(rows * sizeof(int));
    }
    getter(table, lines, rows);
    //printer(table, lines, rows); debug: mostra a matriz inteira
    findBiggests(table, lines, rows);
    free(*table);
    system("pause");
    return 0;
}