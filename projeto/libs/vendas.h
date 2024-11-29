#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "./lista-filmes.h"

typedef struct Venda {
    filme *filme;
    char nomeComprador[charConst];
    char cpfComprador[15];
    int poltrona;
    int sala;
    float valor;
    char dataVenda[charConst];
    struct tm tm;
    struct Venda *nextVenda;
} venda;

typedef struct Venda *listaVendas;

listaVendas* criarHistoricoDeVendas() {
    listaVendas *newLista = (listaVendas*) malloc (sizeof(listaVendas));
    if(newLista == NULL) {
        printf("erro na alocação :( \n");
        exit(0);
    } else {
        *newLista = NULL;
    }
    return newLista;
}

int limparListaVendas(listaVendas *lista) {
    if (*lista == NULL) {
        free(lista);
        return 0;
    }
    venda *next;
    venda *temp;
    temp = *lista;
    while (temp->nextVenda != NULL) {
        next = temp->nextVenda;
        free(temp);
        temp = next;
    }
    free(temp);
    free(lista);
    return 0;
}

//função que faz o print de uma nota fiscal
void impressorNotaFiscal(venda *venda, int numeroNF) {
    printf("\n##### Comprovante Fiscal #####\n"); 
    printf("Filme: %s\n", venda->filme->nome);
    printf("Genero: %s\n", venda->filme->genero);
    switch(venda->filme->classificacaoAvaliativa) {
        case 1: printf("Classificação Indicativa: Livre\n"); break;
        case 2: printf("Classificação Indicativa: Não recomendado para menores de 10 anos\n"); break;
        case 3: printf("Classificação Indicativa: Não recomendado para menores de 12 anos \n"); break;
        case 4: printf("Classificação Indicativa: Não recomendado para menores de 14 anos\n"); break;
        case 5: printf("Classificação Indicativa: Não recomendado para menores de 16 anos\n"); break;
        case 6: printf("Classificação Indicativa: Não recomendado para menores de 18 anos\n"); break;
        default: printf("Classificação Indicativa: N/A\n");
    }; 
    printf("Duração: %ihr %imin\n", (venda->filme->duracao / 60), (venda->filme->duracao % 60));
    printf("Poltrona: %i  Sala: %i\n", venda->poltrona, venda->sala);
    printf("Data da sessão: 19:30, %02d-%02d-%d\n", venda->tm.tm_mday, venda->tm.tm_mon + 1, venda->tm.tm_year + 1900);
    printf("Nome do comprador: %s\n", venda->nomeComprador);
    printf("CPF do comprador: %s\n", venda->cpfComprador);
    printf("Valor Final: R$%.2f\n", venda->valor);
    printf("Nota Fiscal n°%i\n", numeroNF); 
    printf("%s", venda->dataVenda);
    printf("#####  CINEMA 2  #####\n");
}

//função que realiza vendas
int realizarVenda(listaFilmes *filmes, listaVendas *vendas) {
    if (*filmes == NULL) {
        printf("não há filmes em cartaz no momento :C\n");
        return 1;
    } 
    filme *temp = *filmes;
    int count = 1;
        while(temp->nextFilme != NULL) {
        temp = temp->nextFilme;
        count++;
    };
    printf("count: %i\n", count);
    printf("\n#### REALIZAÇÃO DE VENDA ####\n");
    mostrarFilmes(filmes);
    int tempOpcao = 0; //variável temporária de seleção de opção
    do {
        do {
            printf("Escolha um filme: "); //pede pro usuário informar o id do produto a ser vendido
            scanf("%s", &varTemp); //lê o input em uma variável string temporaria
        } while (validateInput(varTemp, charConst) == INVALIDO); //repete o do while caso a função de validação retorne invalido
        tempOpcao = atoi(varTemp); //converte o input na variável string para a variavél de destino
        varTempClean(varTemp); //função que limpa a variável temporária após a mesma já ter sido utilizada
        if(tempOpcao <= 0 || tempOpcao > count) {
            printf("opção inválida >:(\n");
        }
    } while (tempOpcao <= 0 || tempOpcao > count);
    temp = *filmes;
    count = 1;
    while (count != tempOpcao) {
        temp = temp->nextFilme;
        count++;
    };
    printf("Filme selecionado: %s\n", temp->nome);
    venda *novaVenda = (venda*) malloc(sizeof(venda));
    if(novaVenda == NULL) {
        printf("erro na alocação :( \n");
        exit(0);
    } else {
        time_t horaVenda = time(NULL);
 
        filme *newFilme = (filme*) malloc (sizeof(filme));
        strcpy(newFilme->nome, temp->nome);
        strcpy(newFilme->genero, temp->genero);
        newFilme->classificacaoAvaliativa = temp->classificacaoAvaliativa;
        newFilme->duracao = temp->duracao;
        newFilme->valorIngresso = temp->valorIngresso;
        novaVenda->filme = newFilme;

        printf("Informe o nome do comprador: ");
        scanf("%s", novaVenda->nomeComprador);

        printf("Informe o CPF do comprador [XXX.XXX.XXX-XX]: ");
        scanf("%s", novaVenda->cpfComprador);

        do {
            printf("Informe o assento: ");
            scanf("%s", &varTemp); //lê o input em uma variável string temporaria
        } while (validateInput(varTemp, charConst) == INVALIDO); //repete o do while caso a função de validação retorne invalido
        novaVenda->poltrona = atoi(varTemp); //converte o input na variável string para a variavél de destino
        varTempClean(varTemp); //função que limpa a variável temporária após a mesma já ter sido utilizada

        do {
            printf("Informe a sala da sessão: ");
            scanf("%s", &varTemp); //lê o input em uma variável string temporaria
        } while (validateInput(varTemp, charConst) == INVALIDO); //repete o do while caso a função de validação retorne invalido
        novaVenda->sala = atoi(varTemp); //converte o input na variável string para a variavél de destino
        varTempClean(varTemp); //função que limpa a variável temporária após a mesma já ter sido utilizada

        novaVenda->valor = temp->valorIngresso;

        strcpy(novaVenda->dataVenda, asctime(localtime(&horaVenda)));

        time_t hrSessao = time(NULL);
        novaVenda->tm= *localtime(&hrSessao);

        novaVenda->nextVenda = NULL;

        venda *temp = *vendas;
        int numeroNF = 1;
        if (*vendas != NULL) {
            while (temp->nextVenda != NULL) {
                temp = temp->nextVenda;
                numeroNF++;
            }
        numeroNF++;
        }

        impressorNotaFiscal(novaVenda, numeroNF);
    }
    if (*vendas == NULL) {
        *vendas = novaVenda;
    } else {
        venda *vendaTemp = (*vendas);
        while (vendaTemp->nextVenda != NULL) {
            vendaTemp = vendaTemp->nextVenda;
        }
        vendaTemp->nextVenda = novaVenda;
    }
    printf("\nVenda registrada com sucesso.\n");
    return 0;
}