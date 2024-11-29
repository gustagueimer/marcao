#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define charConst 64    //define a constante do maximo de caracteres por string
#define VALIDO 0    //define valido como 0
#define INVALIDO 1    //define invalido como 1

//definição de variáveis relacionadas a verificação de inputs
char varTemp[charConst] = {'\0'}; //variavel char temporaria usada para validação de input

//função para limpar a variavel temporária
void varTempClean(char *varTemp) {
    char varClean[charConst] = {'\0'};
    memcpy(varTemp, varClean, charConst);
}
 
//função que valida um input apenas numérico
int validateInput(char *input, int size) {
    for (int i=0;i<size;i++) {    //for que vai percorrer o array da variável informada como parâmetro com base no tamanho passado como parametro
        // debuggng // printf("input[%d]: %c\n", i, input[i]);
        if(!isdigit(input[i]) && (input[i] != '\0')) {    //if confere se existe algum caracter no array que não seja um digito enquanto não chegar no caracter nulo (fim da string)
            if (!ispunct(input[i]) && (input[i] != '\0')) {    //caso exista um caractere que não seja um digito, passa pra esse if que confere se existe algum caractere que não seja um caractere de pontuação enquanto não chegar no digito nulo (usado pra pegar numeros decimais)
                printf("input invalido!\n");    //case exista qualquer caractere que não seja um digito ou um caractere de pontuação, informa natela que o input é invalido 
                varTempClean(input);    //chama a função que limpa a variável temporária 
                // debugging // printf("vartemp: %s\n", input);
            return INVALIDO;    //retorna invalido como resultado da verificação
            }
        }
        // debugging // printf("ainda no for\n");
    }
    // debugging // printf("saiu do for\n");
    return VALIDO;    //caso não exista qualquer caractere diferente de digitos e pontuações, retorna valido como resultado da verificação
}
