#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include "./validacao.h"

#define LimiteMaxUser 10 //define a constante que representa o limite maximo de usuario

// Estrutura que representa um usuário do sistema
typedef struct {
    char user[charConst]; //elemento que representa o login/id do usuário
    char password[charConst]; //elemento que representa a senha do usuário
    int accessLevel; //elemento que define o nível de acesso do usuário |1 = normal|2= admin|
} User;

//função de login
int login(User *usuario) {
    char tempUser[charConst]; //variável temporária pra pegar o id/login/username e fazer a comparação com a base de dados
    char tempPassword[charConst]; //variável temporária pra pegar a senha e fazer a comparação com a base de dados
    printf("\n##### ID DO USUARIO #####\n");
    scanf("%s", tempUser); //lê o id/login/username do usuário na variável temporaria
    printf("##### SENHA #####\n");
    scanf("%s", tempPassword); //lê a senha do usuário na variável temporária
    for (int i = 0; i < LimiteMaxUser; i++) { //estrutura for pra percorrer o array de usuários
        if (strcmp(tempUser, usuario[i].user) == 0) { //if comparando o id do usuário informado com a base de dados, caso encontre o usuário, procede pra checkagem de senha
            if (strcmp(tempPassword, usuario[i].password) == 0) { //compara a senha informada com a senha do usuário encontrado na base de dados, caso esteja correta, procede para retornar sucesso
                if (usuario[i].accessLevel == 2) { //checa se o usuário encontrado tem nivel de accesso de administrador ou não
                    printf("\nlogado com sucesso!\n"); //mensagem de login bem sucedido
                    return 2; //retorna 2 (login admin bem sucedido)
                }
                printf("\nlogado com sucesso!\n"); //mensagem de login bem sucedido
                return 0; //retorna 0 (login bem sucedido)
            }
        }
    }
    printf("\nusuário ou senha incorretos"); //mensagem de erro de login
    return 1; //retorna 1 (login mal sucedido)
}

int comparacaoUsuarios(User *usuario, char *comparativo) {
    for (int i; i < LimiteMaxUser; i++) {
        if (strcmp(usuario[i].user, comparativo) == 1) {
            return 1;
        }
    }
    return 0;
}

//função que pede se o usuário quer fechar o programa ou tentar o login novamente
int retry(int *isRunning) {
    int retry = 0; //variável que serve para selecionar uma opção do menu de tentar novamente
    do { //abre um menuzinho de opções relacionadas a repetir o login
        printf("\ntentar novamente?\n");
        printf("1. sim\n");
        printf("2. não\n");
        //verificação de input
        do { 
            printf("Escolha uma opcao: "); //pede pro usuário informar uma opção
            scanf("%s", &varTemp); //lê o input em uma variável string temporaria
        } while (validateInput(varTemp, charConst) == INVALIDO); //repete o do while caso a função de validação retorne invalido
        retry = atoi(varTemp); //converte o input na variável string para a variavél de destino
        varTempClean(varTemp); //função que limpa a variável temporária após a mesma já ter sido utilizada
        switch (retry) {
            case 1: break; //fehca o switch e encerra a função sem mudar o valor da variável que determina se o programa deve rodar de novo
            case 2: *isRunning = 1; break; //muda o valor da variável que determina se o programa deve rodar de novo, sai do switch e encerra a função
            default: printf("opção invalida!\n"); //informa na tela que a opção escolhida é invalida
                     retry = 0; //redefine o valor da variável de tentar novamente para 0 fazendo o do while repetir
        } 
    } while (retry == 0); //do while do menuzinho de tentar novamnete repete caso a variável de tentar novamente seja igual a 0
    return 0;
}

//função que cadastra o primeiro usuário do sistema (admin)
int registrarAdmin(User *usuario, int *userCount) {
    printf("\n#### CADASTRAMENTO DE ADMIN ####\n");
    printf("informe o login do administrador - "); //pede pro usuário definir o id/login/username do primeiro usuário
    scanf("%s", usuario[0].user); //lê o input do usuário
    printf("informe a senha do administrador - "); //pede pro usuário definir a senha do primeiro usuário
    scanf("%s", usuario[0].password); //lê a senha definida
    usuario[0].accessLevel = 2; //garante o nivel de acesso de administrador para o primeiro usuário cadastrado automaticamente
    puts("\nadiministrador registrado com sucesso"); //printa na tela que a operação foi bem sucedida
    *userCount = *userCount + 1; //sobe o contador de usuários cadastrados (0 -> 1)
    return 0;
}

//função que cadastra um novo usuário no sistema
int registrarUsuario(User *usuario, int *userCount) {
    int tempOpcao; //varivale temporaria para escolher uma opção
    int tempCount = 0; //gambiarra pq usar o parametro pra definir a posição do array não estava funcionando por algum ferrenho motivo
    for (int index=0; index<LimiteMaxUser; index++) {
        if (strcmp(usuario[index].user, "inutilizado") == 0) {
            break;
        }
        tempCount++;
    }
    printf("\n#### CADASTRAMENTO DE USUÁRIO ####\n");
    printf("informe o login do novo usuário - "); //pede pro usuário definir o id/login/username do novo usuario
    scanf("%s", usuario[tempCount].user); //lê o login inserido na seção de nome da variavel de usuarios
    printf("informe a senha do novo usuário - "); //pede pro usuário definir a senha do novo usuário
    scanf("%s", usuario[tempCount].password); //lê a senha inserida pelo usuário na seção de senha da variavel de usuários
    //loop pra repetir o pedido de input até o usuário inserir uma opção valida
    do {
        printf("informe o nivel de acesso do novo usuário\n"); //pede pro usuário definir o nivel de acesso do novo usuário
        printf("1. vendedor\n");
        printf("2. administador");
        //verificação de input
        do {
            printf("\nEscolha uma opção: "); 
            scanf("%s", &varTemp); //lê o input em uma variável string temporaria
        } while (validateInput(varTemp, charConst) == INVALIDO); //repete o do while caso a função de validação retorne invalido
        tempOpcao = atoi(varTemp); //converte o input na variável string para a variavél de destino
        varTempClean(varTemp); //função que limpa a variável temporária após a mesma já ter sido utilizada 
        switch (tempOpcao) { //switch do menu de opções disponíveis
            case 1: usuario[tempCount].accessLevel = 1; tempOpcao = -1; break; //define o novo usuário com o nivel de accesso de usuário normal e redefine a variável temporária de opção pra -1
            case 2: usuario[tempCount].accessLevel = 2; tempOpcao = -1; break; //define o novo usuário com o nivel de accesso de administrador e redefine a variável temporária de opção pra -1
            default: puts("opção invalida"); break; //bota na tela que a opção escolhida é invalida
        }
    } while (tempOpcao != -1); //fecha o loop do menu quando a variável temporária de seleção e opção for -1
    puts("usuário registrado com sucesso"); //informa na tela que o cadastro do novo usuário foi bem sucedido;
    if (tempCount == *userCount) {
        *userCount += 1; //sobe o contador de usuários cadastrados
    }
    return 0;
}

int removerUsuario(User *usuario, int *userCount) {
    int tempCount = 1;
    if(tempCount == *userCount) {
        printf("não há usuários cadastrados para remover :P\n");
        return 1;
    }
    int tempOpcao = 0;
    printf("\nUsuarios registrados: \n");
    printf("---------------------------\n");
    do {
        printf("%i - %s\n", (tempCount), usuario[tempCount]);
        tempCount++;
    } while (tempCount != *userCount);
    do {
        do {
            printf("Escolha um usuário: ");
            scanf("%s", &varTemp); //lê o input em uma variável string temporaria
        } while (validateInput(varTemp, charConst) == INVALIDO); //repete o do while caso a função de validação retorne invalido
        tempOpcao = atoi(varTemp); //converte o input na variável string para a variavél de destino
        varTempClean(varTemp); //função que limpa a variável temporária após a mesma já ter sido utilizada
        if (tempOpcao <= 0 || tempOpcao > (tempCount+1)) {
            printf("Opção inválida >:(\n");
        }
    } while (tempOpcao <= 0 || tempOpcao > (tempCount+1));
    strcpy(usuario[tempOpcao].user, "inutilizado");
    strcpy(usuario[tempOpcao].password, "inutilizado");
    usuario[tempOpcao].accessLevel = 0;
    return 0;
}
