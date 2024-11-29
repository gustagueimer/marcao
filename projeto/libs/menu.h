#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include "./relatorio-maker.h"

//função do menu (administrador)
int menuAdmin(User *usuario, int *userCount, int *isRunning, listaFilmes *filmes, listaVendas *vendas) {
    int opcao; //variavél que segura o valor referente a uma opção do menu
    int subOpcao; //variável que segura o valor referente a uma opção dos submenus
    do { //do while do menu principal
        printf("\n##### MENU #####\n");
        printf("1. Adicionar Filme\n");
        printf("2. Ver filmes\n");
        printf("3. Remover filmes\n");
        printf("4. Gerenciar usuários \n");
        printf("5. Gerar relatório de vendas\n");
        printf("0. Sair\n");
        //verificação de input
        do {
            printf("Escolha uma opcao: "); //pede pro usuário digitar uma opção
            scanf("%s", &varTemp); //lê o input em uma variável string temporaria
        } while (validateInput(varTemp, charConst) == INVALIDO); //repete o do while caso a função de validação retorne invalido
        opcao = atoi(varTemp); //converte o input na variável string para a variavél de destino
        varTempClean(varTemp); //função que limpa a variável temporária após a mesma já ter sido utilizada
        switch (opcao) {
            case 1:  adicionarFilme(filmes); break; // sai do switch do menu principal
            case 2: mostrarFilmes(filmes); break; //sai do switch do menu principal
            case 3: removerFilme(filmes); break; //sai do switch do menu principal
            case 4:
                do {
                    printf("\n##### GERENCIAR USUÁRIOS #####\n");
                    printf("1. Adicionar usuário \n");
                    printf("2. Remover usuário \n");
                    printf("0. Voltar\n");
                    //verificação de input
                    do {
                        printf("Escolha uma opcao: ");
                        scanf("%s", &varTemp); //lê o input em uma variável string temporaria
                    } while (validateInput(varTemp, charConst) == INVALIDO); //repete o do while caso a função de validação retorne invalido
                    subOpcao = atoi(varTemp); //converte o input na variável string para a variavél de destino
                    varTempClean(varTemp); //função que limpa a variável temporária após a mesma já ter sido utilizada
                    switch(subOpcao) {
                        case 1: registrarUsuario(usuario, userCount); break;
                        case 2: removerUsuario(usuario, userCount); break;
                        case 0: break;
                        default: printf("opção invalida!\n");
                    }
                } while (subOpcao != 0);
                break;
            case 5: gerarRelatorioVendas(vendas); break;
            case 0: //abre o submenu com as opções para sair/fechar o sistema
                do {
                    printf("\n##### SAIR #####\n");
                    printf("1. Trocar usuário\n");
                    printf("2. Fechar o programa\n");
                    printf("0. Voltar\n");
                    //verificação de input
                    do {
                        printf("Escolha uma opcao: ");
                        scanf("%s", &varTemp); //lê o input em uma variável string temporaria
                    } while (validateInput(varTemp, charConst) == INVALIDO); //repete o do while caso a função de validação retorne invalido
                    subOpcao = atoi(varTemp); //converte o input na variável string para a variavél de destino
                    varTempClean(varTemp); //função que limpa a variável temporária após a mesma já ter sido utilizada
                    switch (subOpcao) {
                        case 1: printf("Saindo...\n"); break; //informa na tela que esta saindo do usuário logado e fecha os menus
                        case 2: printf("Fechando...\n"); *isRunning = 1; break; //informa na tela que o programa está fechando e fecha os menus
                        case 0: opcao = 1; break; //define a variável de opção do menu como 1 para retornar e não fechar o menu principal e fecha o submenu
                        default: printf("Opção invalida!\n"); //informa na tela que a opção informada é invalida
                    }
                } while ((subOpcao != 1) && (subOpcao != 2) && (subOpcao != 0)); //do while do submenu repete enquanto a variável do submenu não for 1, 2 ou 0
                break; //sai do switch do menu principal
            default:
                printf("Opcao invalida!\n"); //informa na tela que a opção informada é invalida
        }
    } while (opcao != 0); //do while repete o menu enquanto a variável de opção do menu não for igual a zero
    return 0;
}

//função do menu (padrão)
int menuDefault(int *isRunning, listaFilmes *filmes, listaVendas *vendas) {
    int opcao; //variavél que segura o valor referente a uma opção do menu
    int subOpcao; //variável que segura o valor referente a uma opção dos submenus
    do { //do while do menu principal
        printf("\n##### MENU #####\n");
        printf("1. Ver filmes\n");
        printf("2. Vender Ingresso\n");
        printf("0. Sair\n");
        //verificação de input
        do {
            printf("Escolha uma opcao: "); //pede pro usuário digitar uma opção
            scanf("%s", &varTemp); //lê o input em uma variável string temporaria
        } while (validateInput(varTemp, charConst) == INVALIDO); //repete o do while caso a função de validação retorne invalido
        opcao = atoi(varTemp); //converte o input na variável string para a variavél de destino
        varTempClean(varTemp); //função que limpa a variável temporária após a mesma já ter sido utilizada
        switch (opcao) {
            case 1: mostrarFilmes(filmes); break; // sai do switch do menu principal
            case 2: realizarVenda(filmes, vendas); break; //sai do switch do menu principal
            case 0: //abre o submenu com as opções para sair/fechar o sistema
                do {
                    printf("\n##### SAIR #####\n");
                    printf("1. Trocar usuário\n");
                    printf("2. Fechar o programa\n");
                    printf("0. Voltar\n");
                    //verificação de input
                    do {
                        printf("Escolha uma opcao: ");
                        scanf("%s", &varTemp); //lê o input em uma variável string temporaria
                    } while (validateInput(varTemp, charConst) == INVALIDO); //repete o do while caso a função de validação retorne invalido
                    subOpcao = atoi(varTemp); //converte o input na variável string para a variavél de destino
                    varTempClean(varTemp); //função que limpa a variável temporária após a mesma já ter sido utilizada
                    switch (subOpcao) {
                        case 1: printf("Saindo...\n"); break; //informa na tela que esta saindo do usuário logado e fecha os menus
                        case 2: printf("Fechando...\n"); *isRunning = 1; break; //informa na tela que o programa está fechando e fecha os menus
                        case 0: opcao = 1; break; //define a variável de opção do menu como 1 para retornar e não fechar o menu principal e fecha o submenu
                        default: printf("Opção invalida!\n"); //informa na tela que a opção informada é invalida
                    }
                } while ((subOpcao != 1) && (subOpcao != 2) && (subOpcao != 0)); //do while do submenu repete enquanto a variável do submenu não for 1, 2 ou 0
                break; //sai do switch do menu principal
            default:
                printf("Opcao invalida!\n"); //informa na tela que a opção informada é invalida
        }
    } while (opcao != 0); //do while repete o menu enquanto a variável de opção do menu não for igual a zero
    return 0;
}