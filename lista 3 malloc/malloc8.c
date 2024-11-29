#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define charConst 64
typedef struct aluno {
    char nome[charConst];
    char sobrenome[charConst];
    int matricula;
    char dataNascimento[11];
} aluno;
//balls 101
void anbt() {
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);
}
int getAlunos(aluno *alunos, int qnt) {
    for(int i=0; i<qnt; i++) {
        printf("insira o nome do aluno - ");
        scanf("%s", alunos[i].nome);
        printf("insira o sobrenome do aluno (apenas um) - ");
        scanf("%s", alunos[i].sobrenome);
        printf("insira a data de nascimento do aluno (xx/xx/xxxx) - ");
        scanf("%s", alunos[i].dataNascimento);
        printf("insira o número da matricula - ");
        scanf("%i", &alunos[i].matricula);
    }
    return 0;
}
void showAlunos(aluno *alunos, int qnt) {
    for(int i=0; i<qnt; i++) {
        printf("aluno %i - nome: %s, sobrenome: %s, data de nascimento: %s, n° da matricula: %i \n", i+1, alunos[i].nome, alunos[i].sobrenome, alunos[i].dataNascimento, alunos[i].matricula);
    }
}
int main() {
    anbt();
    int size = 0;
    printf("defina o número de alunos a serem cadastrados - ");
    scanf("%i", &size);
    aluno *alunos =  malloc(size * sizeof(aluno));
    if(alunos == NULL) {
        printf("deu não \n");
    } else {
        getAlunos(alunos, size);
        showAlunos(alunos, size);
    }
    free(alunos);
    printf("limpou a memória\n");
    system("pause");
    return 0;
}