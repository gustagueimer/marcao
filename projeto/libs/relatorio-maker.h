#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "./file-system.h"

//função que vai gerar um relatório de vendas (não tenho tempo de explicar)
int gerarRelatorioVendas(listaVendas *vendas) {
    if(*vendas == NULL) {
        printf("Não há nenhum registro para gerar um relatório :P\n");
        return 1;
    }

    //muito trampo pra criar o nome do arquivo
    char nomeRelatorio[charConst] = {"./relatorios/Relatorio de Vendas "};
    char nomePlaceholder[charConst];
    char dataPlaceholder[charConst];
    time_t data = time(NULL);
    strcat(nomeRelatorio, asctime(localtime(&data)));
    strtok(nomeRelatorio, "\n");
    strcpy(nomePlaceholder, nomeRelatorio);
    strcat(nomeRelatorio, ".txt"); 
    for (int i=0; i<charConst; i++) {
        if (nomeRelatorio[i] != '\0') {
            if (nomeRelatorio[i] == ' ') {
                nomeRelatorio[i] = '_';
            }
            if (nomeRelatorio[i] == ':') {
                nomeRelatorio[i] = '-';
            }
        }
    }

    FILE *file_novoRelatorio; //cria a variável que gerencia os arquivos
    file_novoRelatorio = fopen(nomeRelatorio, "w"); //cria o arquivo com o nome bolado
    printf("criou o file\n");

    venda *temp = *vendas;
    int count = 1;
    while (temp->nextVenda != NULL) {
        temp = temp->nextVenda;
        count++;
    }

    printf("calculou o count: %i\n", count);

    temp = *vendas;
    for (int i=0; i<count; i++) { //for pra percorrer o array da variável inteira
    printf("entrou no for\n");
            //faz o print no arquivo das informações da variável do controle de vendas
            fprintf(file_novoRelatorio, "\n ------ VENDA ------ \n");printf("1\n");

            fprintf(file_novoRelatorio, "\nFilme: %s\n", temp->filme->nome); printf("2\n");
            fprintf(file_novoRelatorio, "Genero: %s\n", temp->filme->genero); printf("3\n");
            switch(temp->filme->classificacaoAvaliativa) {
                case 1: fprintf(file_novoRelatorio, "Classificação Indicativa: Livre\n"); break;
                case 2: fprintf(file_novoRelatorio, "Classificação Indicativa: Não recomendado para menores de 10 anos\n"); break;
                case 3: fprintf(file_novoRelatorio, "Classificação Indicativa: Não recomendado para menores de 12 anos \n"); break;
                case 4: fprintf(file_novoRelatorio, "Classificação Indicativa: Não recomendado para menores de 14 anos\n"); break;
                case 5: fprintf(file_novoRelatorio, "Classificação Indicativa: Não recomendado para menores de 16 anos\n"); break;
                case 6: fprintf(file_novoRelatorio, "Classificação Indicativa: Não recomendado para menores de 18 anos\n"); break;
                default: fprintf(file_novoRelatorio, "Classificação Indicativa: N/A\n");
            }; printf("4\n");
            fprintf(file_novoRelatorio, "Duração: %ihr %imin\n", (temp->filme->duracao / 60), (temp->filme->duracao % 60)); printf("5\n"); 

            fprintf(file_novoRelatorio, "Poltrona: %i  Sala: %i\n", temp->poltrona, temp->sala); printf("6\n");
            fprintf(file_novoRelatorio, "Data da sessão: 19:30, %02d-%02d-%d\n", temp->tm.tm_mday, temp->tm.tm_mon + 1, temp->tm.tm_year + 1900); printf("7\n");
            fprintf(file_novoRelatorio, "Nome do comprador: %s\n", temp->nomeComprador); printf("8\n");
            fprintf(file_novoRelatorio, "CPF do comprador: %s\n", temp->cpfComprador); printf("9\n");
            fprintf(file_novoRelatorio, "Valor Final: R$%.2f\n", temp->valor); printf("10\n");
            fprintf(file_novoRelatorio, "Data da venda: %s\n", temp->dataVenda);
            temp = temp->nextVenda;
    }
    fclose(file_novoRelatorio); //fecha o gerenciador de arquivo
    printf("\n##### RELATÓRIO CRIADO COM SUCESSO #####\n");
    return 0;
}