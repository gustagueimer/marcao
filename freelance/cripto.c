#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define charConst 64
#define VALIDO 0 //define valido como 0
#define INVALIDO 1 //define invalido como 1
//balls 101

char varTemp[charConst] = {'\0'}; //variavel char temporaria usada para validação de input

void anbt() {
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);
}

void varTempClean() {
    char varClean[charConst] = {'\0'};
    memcpy(varTemp, varClean, charConst);
}

int validateInput(char *input, int size) {
    for (int i=0;i<size;i++) { //for que vai percorrer o array da variável informada como parâmetro com base no tamanho passado como parametro
        // debuggng // printf("input[%d]: %c\n", i, input[i]);
        if(!isdigit(input[i]) && (input[i] != '\0')) { //if confere se existe algum caracter no array que não seja um digito enquanto não chegar no caracter nulo (fim da string)
            if (!ispunct(input[i]) && (input[i] != '\0')) { //caso exista um caractere que não seja um digito, passa pra esse if que confere se existe algum caractere que não seja um caractere de pontuação enquanto não chegar no digito nulo (usado pra pegar numeros decimais)
                printf("input invalido!\n"); //case exista qualquer caractere que não seja um digito ou um caractere de pontuação, informa natela que o input é invalido 
                varTempClean(); //chama a função que limpa a variável temporária 
                // debugging // printf("vartemp: %s\n", input);
            return INVALIDO; //retorna invalido como resultado da verificação
            }
        }
        // debugging // printf("ainda no for\n");
    }
    // debugging // printf("saiu do for\n");
    return VALIDO; //caso não exista qualquer caractere diferente de digitos e pontuações, retorna valido como resultado da verificação
}

void descriptografer(char *message, int startPos, int key) {
    if ((message[startPos] == '\0') || (startPos == charConst)) {
        printf("descriptografado com sucesso\n ");
    } else {
        if((message[startPos] >= 97) && (message[startPos] <= 122) && (message[startPos] - key) < 97){
            //printf("entrou a -> X\n"); debugging
            message[startPos] = ((message[startPos] - key) - 97) + 91;
        } else if ((message[startPos] >= 65) && (message[startPos] <= 90) && (message[startPos] - key) < 65) {
            //printf("entrou A -> 7\n"); debugging
            int temp = ((message[startPos] - key) - 65) + 58;
            if(temp < 48) {
                message[startPos] = (temp - 48) + 123;
            } else {
                message[startPos] = temp;
            }
        } else if ((message[startPos] >= 48) && (message[startPos] <= 57) && ((message[startPos] - key) < 48)) {
            //printf("entrou 0 -> x\n"); debugging
            message[startPos] = ((message[startPos] - key) - 48) + 123;
        } else {
            //printf("entrou default\n"); debugging
            message[startPos] = message[startPos] - key;
        }
        descriptografer(message, startPos+1, key);
    }
}

void criptografer(char *message, int startPos, int key) {
    if ((message[startPos] == '\0') || (startPos == charConst)) {
        printf("criptografado com sucesso\n ");
    } else {
        if((message[startPos] + key) > 122) {
            int temp = ((message[startPos] + key) - 122) + 47;
            if(temp > 57) {
                message[startPos] = (temp - 57) + 64;
            } else {
                message[startPos] = temp;
            }
        } else if ((message[startPos] >= 65) && (message[startPos] <= 90) && ((message[startPos] + key) > 90)) {
            message[startPos] = ((message[startPos] + key) - 90) + 96;
        } else if ((message[startPos] >= 48) && (message[startPos] <= 57) && ((message[startPos] + key) > 57)) {
            message[startPos] = ((message[startPos] + key) - 57) + 64;
        } else {
            message[startPos] = message[startPos] + key;
        }
        criptografer(message, startPos+1, key);
    }
}

void descript(int key) {
    char palavra[charConst];
    printf("insira a palavra - ");
    fflush(stdin);
    gets(palavra);
    descriptografer(palavra, 0, key);
    printf("resultado: %s \n", palavra);
}

void script(int key) {
    char palavre[charConst];
    printf("insira a palavra - ");
    fflush(stdin);
    gets(palavre);
    criptografer(palavre, 0, key);
    printf("resultado: %s \n", palavre);
}

void keyChanger(int *key) {
    printf("insira o tamanho da nova chave - ");
    scanf("%i", key);
    printf("chave atualizada com sucesso \n");
    printf("nova chave: %i \n", *key);
}

void menu(int *key) {
    int tempOpcao = 0;
    do {
        printf("menu deluxe \n");
        printf("1 - alterar a chave. \n");
        printf("2 - criptografar uma mensagem. \n");
        printf("3 - descriptografar um mensagem. \n");
        printf("0 - sair do programa. \n");
        do {
            printf("escolha uma opção: ");
            scanf("%s", varTemp);
        } while(validateInput(varTemp, charConst) == INVALIDO);
        tempOpcao = atoi(varTemp); //converte o input na variável string para a variavél de destino
        varTempClean(); //função que limpa a variável temporária após a mesma já ter sido utilizada
        switch(tempOpcao) {
            case 1: keyChanger(key); break;
            case 2: script(*key); break;
            case 3: descript(*key); break;
            case 0: printf("saindo...\n"); break;
            default: printf("opção inválida >:( \n");
        }
    } while(tempOpcao != 0);
}

int main() {
    anbt();
    int chave = 3;
    menu(&chave);
    return 0;
}