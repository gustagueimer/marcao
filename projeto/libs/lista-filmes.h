#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "./usuarios.h"

typedef struct Filme {
    char nome[100];
    char genero[100];
    int classificacaoAvaliativa;
    int duracao;
    float valorIngresso;
    struct Filme *nextFilme;
} filme;

typedef struct filme *listaFilmes;

listaFilmes* criarCatalogo() {
    listaFilmes *newLista = (listaFilmes*) malloc (sizeof(listaFilmes));
    if(newLista == NULL) {
        printf("erro na alocação :( \n");
        exit(0);
    } else {
        *newLista = NULL;
    }
    return newLista;
}

int adicionarFilme(listaFilmes *lista) {
    filme *novoFilme = (filme*) malloc (sizeof(filme));
    if(novoFilme == NULL) {
        printf("erro na alocação :( \n");
        exit(0);
    } else {
        printf("Insira o nome do filme: ");
        scanf("%s", novoFilme->nome);

        printf("Insira o genero do filme: ");
        scanf("%s", novoFilme->genero);

        do {
            printf("Insira a classificação indicativa do filme: \n");
            printf("1- Livre \n");
            printf("2- Não recomendado para menores de 10 anos \n");
            printf("3- Não recomendado para menores de 12 anos \n");
            printf("4- Não recomendado para menores de 14 anos \n");
            printf("5- Não recomendado para menores de 16 anos \n");
            printf("6- Não recomendado para menores de 18 anos \n");
            do {
                scanf("%s", &varTemp); //lê o input em uma variável string temporaria
            } while (validateInput(varTemp, charConst) == INVALIDO); //repete o do while caso a função de validação retorne invalido
            novoFilme->classificacaoAvaliativa = atoi(varTemp); //converte o input na variável string para a variavél de destino
            varTempClean(varTemp); //função que limpa a variável temporária após a mesma já ter sido utilizada
        } while (novoFilme->classificacaoAvaliativa <= 0 || novoFilme->classificacaoAvaliativa > 6);

        do {
            printf("Informe a duração em minutos do filme: ");
            scanf("%s", &varTemp); //lê o input em uma variável string temporaria
        } while (validateInput(varTemp, charConst) == INVALIDO); //repete o do while caso a função de validação retorne invalido
        novoFilme->duracao = atoi(varTemp); //converte o input na variável string para a variavél de destino
        varTempClean(varTemp); //função que limpa a variável temporária após a mesma já ter sido utilizada

        do {
            printf("Informe o valor do ingresso do filme: R$");
            scanf("%s", &varTemp); //lê o input em uma variável string temporaria
        } while (validateInput(varTemp, charConst) == INVALIDO); //repete o do while caso a função de validação retorne invalido
        novoFilme->valorIngresso = atof(varTemp); //converte o input na variável string para a variavél de destino
        varTempClean(varTemp); //função que limpa a variável temporária após a mesma já ter sido utilizada

        novoFilme->nextFilme = NULL;
        if (*lista == NULL) {
            *lista = novoFilme;
        } else {
            filme *temp;
            temp = (*lista);
            while (temp->nextFilme != NULL) {
                temp = temp->nextFilme;
            }
            temp->nextFilme = novoFilme;
        }
    }
    return 0;
}

int mostrarFilmes(listaFilmes *lista) {
    filme *temp = *lista;
    int counter = 0;
    if(*lista == NULL) {
        printf("não há nenhum filme em cartaz :P ");
    } else {
        printf("\n###### FILMES EM CARTAZ ######\n");
        while(temp->nextFilme != NULL) {
            counter++;
            printf("\n---------------- // ----------------\n\n");
            printf("%i° Filme\n", counter);
            printf("Nome: %s \n", temp->nome);
            printf("Genero: %s \n", temp->genero);
            switch(temp->classificacaoAvaliativa) {
                case 1: printf("Classificação Indicativa: Livre\n"); break;
                case 2: printf("Classificação Indicativa: Não recomendado para menores de 10 anos\n"); break;
                case 3: printf("Classificação Indicativa: Não recomendado para menores de 12 anos \n"); break;
                case 4: printf("Classificação Indicativa: Não recomendado para menores de 14 anos\n"); break;
                case 5: printf("Classificação Indicativa: Não recomendado para menores de 16 anos\n"); break;
                case 6: printf("Classificação Indicativa: Não recomendado para menores de 18 anos\n"); break;
                default: printf("Classificação Indicativa: N/A\n");
            }
            printf("Duração: %ihr %imin\n", (temp->duracao / 60), (temp->duracao % 60));
            printf("Valor do ingresso: R$%.2f\n", temp->valorIngresso);
            temp = temp->nextFilme;
        };
        counter++;
            printf("\n---------------- // ----------------\n\n");
            printf("%i° Filme\n", counter);
            printf("Nome: %s \n", temp->nome);
            printf("Genero: %s \n", temp->genero);
            switch(temp->classificacaoAvaliativa) {
                case 1: printf("Classificação Indicativa: Livre\n"); break;
                case 2: printf("Classificação Indicativa: Não recomendado para menores de 10 anos\n"); break;
                case 3: printf("Classificação Indicativa: Não recomendado para menores de 12 anos \n"); break;
                case 4: printf("Classificação Indicativa: Não recomendado para menores de 14 anos\n"); break;
                case 5: printf("Classificação Indicativa: Não recomendado para menores de 16 anos\n"); break;
                case 6: printf("Classificação Indicativa: Não recomendado para menores de 18 anos\n"); break;
                default: printf("Classificação Indicativa: N/A\n");
            }
            printf("Duração: %ihr %imin\n", (temp->duracao / 60), (temp->duracao % 60));
            printf("Valor do ingresso: R$%.2f\n", temp->valorIngresso);
            printf("\n---------------- // ----------------\n");
    }
    printf("\n");
    return 0;
}

int limparFilme(listaFilmes *lista, int pos) {
    filme *temp = *lista;
    // Remove o filme se ele for o único na lista e sai da função
    if(temp->nextFilme == NULL) {
        free(temp);
        *lista = NULL;
        return 0;
    }
    filme *next;
    int counter = 1;
    printf("counter: %i / pos: %i\n", counter, pos);
    while(counter != pos) {
        temp = temp->nextFilme;
        counter++;
    };
    if((counter == 1) && (temp->nextFilme != NULL)) { // Se o filme a ser removido for o primeiro da lista e houver um próximo filme na lista, guarda o endereço do próximo filme, remove o primeiro filme e insere o endereço do segundo filme no ínicio da lista
        next = temp->nextFilme;
        free(temp);
        *lista = next;
        return 0;
    }
    if (temp->nextFilme != NULL) { //Se houver um próximo filme na frente do filme sendo removido, guarda o endereço do próximo filme, remove o filme selecionado e substitui o endereço no ponteiro do filme anterior da lista
        next = temp->nextFilme;
        free(temp);
        temp = *lista;
        counter = 1;
        while(counter != (pos - 1)) {
            temp = temp->nextFilme;
            counter++;
        }
        temp->nextFilme = next;
    } else { // Se não houver um próximo filme na frente do filme sendo removido, remove o filme selecionado e marca como vazio no ponteiro do filme anterior
        free(temp);
        temp = *lista;
        counter = 1;
        while(counter != (pos - 1)) {
            temp = temp->nextFilme;
            counter++;
        }
        temp->nextFilme = NULL; 
    }
    return 0;
}

int limparListaFilmes(listaFilmes *lista) {
    if(*lista == NULL) {
        free(lista);
        return 0;
    }
    filme *next;
    filme *temp = *lista;
    while (temp->nextFilme != NULL) {
        next = temp->nextFilme;
        free(temp);
        temp = next;
    }
    free(temp);
    free(lista);
    return 0;
}

int removerFilme(listaFilmes *lista) {
    if(*lista == NULL) {
        printf("não há nenhum filme em cartaz :P \n");
    } else {
        mostrarFilmes(lista);
        filme *temp = *lista;
        int counter = 1;
        while(temp->nextFilme != NULL) {
            temp = temp->nextFilme;
            counter++;
        };
        int opcao = 0;
        do {
            do { 
                printf("Informe o numero do filme que deseja remover: "); //pede pro usuário informar uma opção
                scanf("%s", &varTemp); //lê o input em uma variável string temporaria
            } while (validateInput(varTemp, charConst) == INVALIDO); //repete o do while caso a função de validação retorne invalido
            opcao = atoi(varTemp); //converte o input na variável string para a variavél de destino
            varTempClean(varTemp); //função que limpa a variável temporária após a mesma já ter sido utilizada
            if((opcao <= 0) || (opcao > counter)){
                printf("Opção invalida >:(\n");
            } else {
                temp = *lista;
                counter = 1;
                while (counter != opcao) {
                    temp = temp->nextFilme;
                    counter++;
                };
                opcao = 0;
                printf("Deseja remover o filme \"%s\"? \n", temp->nome);
                printf("1. Sim\n");
                printf("0. Não\n");
                do { 
                    printf("Escolha uma opção: "); //pede pro usuário informar uma opção
                    scanf("%s", &varTemp); //lê o input em uma variável string temporaria
                } while (validateInput(varTemp, charConst) == INVALIDO); //repete o do while caso a função de validação retorne invalido
                opcao = atoi(varTemp); //converte o input na variável string para a variavél de destino
                varTempClean(varTemp); //função que limpa a variável temporária após a mesma já ter sido utilizada
                if(opcao == 1) {
                    printf("pindamonhangaba\n");
                    printf("counter: %i\n", counter);
                    limparFilme(lista, counter);
                }
                break;
            }
        } while (TRUE);
    }
    return 0;
}