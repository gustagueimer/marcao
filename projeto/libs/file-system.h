#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "./vendas.h"

//função que formata uma string para ser inserida no arquivo
char  *stringFormatter(char *stringOriginal) {
    for (int i=0; i<charConst; i++) {
        if (stringOriginal[i] == '\0') {
            break;
        }
        if (stringOriginal[i] == ' ') {
            stringOriginal[i] = '_';
        }
    }
    return stringOriginal;
}

//função que desformata uma string após ela ser lida de um arquivo
char *stringUnformatter(char *stringOriginal) {
    for (int i=0; i<charConst; i++) {
        if (stringOriginal[i] == '\0') {
            break;
        }
        if (stringOriginal[i] == '_') {
            stringOriginal[i] = ' ';
        }
    }
    return stringOriginal;
}

//funções relacionadas ao sistema de arquivos

    //função que lê o arquivo que armazena o valor de quantas vezes o programa já foi rodado
    int getTimesRunnedValue(int *timesRunned) {
        FILE *file_timesRunned;
        file_timesRunned = fopen("./arquivos/TimesRunned.txt", "r");
        if (file_timesRunned != NULL) {
            fscanf(file_timesRunned, "%d", timesRunned);
        }
        fclose(file_timesRunned);
        return 0;
    }

    //função que cria um arquivo com o valor de quantas vezes o programa já foi rodado
    int saveTimesRunnedValue(int timesRunned) {
        FILE *file_timesRunned;
        file_timesRunned = fopen("./arquivos/TimesRunned.txt", "w");
        fprintf(file_timesRunned, "%d\n", timesRunned);
        fclose(file_timesRunned);
        return 0;
    }

        //função que lê o arquivo que armazena as informações relacionadas aos usuários
    int getUsersValues(User *usuarios, int *userCount) {
        FILE *file_usuarios;
        file_usuarios = fopen("./arquivos/Usuarios.txt", "r");
        if (file_usuarios != NULL) {
            fscanf(file_usuarios, "%i", userCount);
            for (int i=0; i<LimiteMaxUser; i++) {
                fscanf(file_usuarios, "%s", &usuarios[i].user);
                fscanf(file_usuarios, "%s", &usuarios[i].password);
                fscanf(file_usuarios, "%i", &usuarios[i].accessLevel);
            }
        }
        fclose(file_usuarios);
        return 0;
    }

    //função que cria um arquivo com as informações relacionadas aos usuários
    int saveUsersValues(User *usuarios, int userCount) {
        FILE *file_usuarios;
        file_usuarios = fopen("./arquivos/Usuarios.txt", "w");
        fprintf(file_usuarios, "%d\n", userCount);
        for (int i=0; i<LimiteMaxUser; i++) {
            fprintf(file_usuarios, "%s\n", usuarios[i].user);
            fprintf(file_usuarios, "%s\n", usuarios[i].password);
            fprintf(file_usuarios, "%d\n", usuarios[i].accessLevel);
        }
        fclose(file_usuarios);
        return 0;
    }

    //função que lê o arquivo que armazena as informações relacionadas aos filmes cadastrados
    int getFilmesValues(listaFilmes *filmes) {
        FILE *file_filmes;
        file_filmes = fopen("./arquivos/Filmes.txt", "r");
        
        int count;
        fscanf(file_filmes, "%d\n", &count);

        for (int i=0; i<count; i++) {
            filme *temp = (filme*) malloc (sizeof(filme));
            fscanf(file_filmes, "%s\n", &temp->nome);
            fscanf(file_filmes, "%s\n", &temp->genero);
            fscanf(file_filmes, "%d\n", &temp->classificacaoAvaliativa);
            fscanf(file_filmes, "%d\n", &temp->duracao);
            fscanf(file_filmes, "%f\n", &temp->valorIngresso);
            temp->nextFilme = NULL;
            if (*filmes == NULL) {
                *filmes = temp;
            } else {
                filme *last;
                last = (*filmes);
                while (last->nextFilme != NULL) {
                    last = last->nextFilme;
                }
                last->nextFilme = temp;
            }
        }
        return 0;
    }

    //função que cria um arquivo com as informações relacionadas aos filmes cadastrados
    int saveFilmesValues(listaFilmes *filmes) {
        if (*filmes == NULL) {
            return 0;
        }
        filme *temp = *filmes;
        int count = 1;
        while (temp->nextFilme != NULL) {
            temp = temp->nextFilme;
            count++;
        }
        temp = *filmes;
        FILE *file_filmes;
        file_filmes = fopen("./arquivos/Filmes.txt", "w");
        fprintf(file_filmes, "%d\n", count);
        for (int i=0; i<count; i++) {
            fprintf(file_filmes, "%s\n", temp->nome);
            fprintf(file_filmes, "%s\n", temp->genero);
            fprintf(file_filmes, "%d\n", temp->classificacaoAvaliativa);
            fprintf(file_filmes, "%d\n", temp->duracao);
            fprintf(file_filmes, "%f\n", temp->valorIngresso);
            temp = temp->nextFilme;
        }
        fclose(file_filmes);
        return 0;
    }
    
    //função que lê o arquivo que armazena as informações relacionadas aos filmes cadastrados
    int getVendasValues(listaVendas *vendas) {
        FILE *file_vendas;
        file_vendas = fopen("./arquivos/Vendas.txt", "r");
        
        int count;
        fscanf(file_vendas, "%d\n", &count);

        for (int i=0; i<count; i++) {
            venda *temp = (venda*) malloc (sizeof(venda));
            
            filme *tempFilme = (filme*) malloc (sizeof(filme));
            fscanf(file_vendas, "%s\n", &tempFilme->nome);
            fscanf(file_vendas, "%s\n", &tempFilme->genero);
            fscanf(file_vendas, "%i\n", &tempFilme->classificacaoAvaliativa);
            fscanf(file_vendas, "%i\n", &tempFilme->duracao);
            fscanf(file_vendas, "%f\n", &tempFilme->valorIngresso);
            tempFilme->nextFilme = NULL;

            temp->filme = tempFilme;

            fscanf(file_vendas, "%s\n", &temp->nomeComprador);
            fscanf(file_vendas, "%s\n", &temp->cpfComprador);
            fscanf(file_vendas, "%d\n", &temp->poltrona);
            fscanf(file_vendas, "%d\n", &temp->sala);
            fscanf(file_vendas, "%f\n", &temp->valor);

            fscanf(file_vendas, "%s\n", &temp->dataVenda);
            strcpy(temp->dataVenda, stringUnformatter(temp->dataVenda));
            
            fscanf(file_vendas, "%d\n", &temp->tm.tm_mday);
            fscanf(file_vendas, "%d\n", &temp->tm.tm_mon);
            fscanf(file_vendas, "%d\n", &temp->tm.tm_year);
            temp->nextVenda = NULL;
            if (*vendas == NULL) {
                *vendas = temp;
            } else {
                venda *last;
                last = (*vendas);
                while (last->nextVenda != NULL) {
                    last = last->nextVenda;
                }
                last->nextVenda = temp;
            }
        }
        return 0;
    }

    //função que cria um arquivo com as informações relacionadas aos filmes cadastrados
    int saveVendasValues(listaVendas *vendas) {
        if (*vendas == NULL) {
            return 0;
        }

        venda *temp = *vendas;
        int count = 1;
        while (temp->nextVenda != NULL) {
            temp = temp->nextVenda;
            count++;
        }

        temp = *vendas;

        FILE *file_vendas;
        file_vendas = fopen("./arquivos/Vendas.txt", "w");
        fprintf(file_vendas, "%d\n", count);
        for (int i=0; i<count; i++) {

            fprintf(file_vendas, "%s\n", temp->filme->nome);
            fprintf(file_vendas, "%s\n", temp->filme->genero);
            fprintf(file_vendas, "%i\n", temp->filme->classificacaoAvaliativa);
            fprintf(file_vendas, "%i\n", temp->filme->duracao);
            fprintf(file_vendas, "%f\n", temp->filme->valorIngresso);

            fprintf(file_vendas, "%s\n", temp->nomeComprador);
            fprintf(file_vendas, "%s\n", temp->cpfComprador);
            fprintf(file_vendas, "%d\n", temp->poltrona);
            fprintf(file_vendas, "%d\n", temp->sala);
            fprintf(file_vendas, "%f\n", temp->valor);
            
            //improviso para remover o caractere de nova linha, caso a string contennha um
            for (int i=0; i<charConst; i++) {
                if (temp->dataVenda[i] == '\0') {
                    break;
                }
                if (temp->dataVenda[i] == '\n') {
                    temp->dataVenda[i] = '\0';
                    break;
                }
            }
            fprintf(file_vendas, "%s\n", stringFormatter(temp->dataVenda));
            
            fprintf(file_vendas, "%d\n", temp->tm.tm_mday);
            fprintf(file_vendas, "%d\n", temp->tm.tm_mon);
            fprintf(file_vendas, "%d\n", temp->tm.tm_year);

            if(temp->filme->nextFilme == NULL) {
                free(temp->filme);
            }

            temp = temp->nextVenda;
        }
        fclose(file_vendas);
        return 0;
    }