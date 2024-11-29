#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "./libs/menu.h"

#define LimiteMax 100 //define a constante que representa o limite maximo de muita coisa
#define LimiteMaxRelatório 200 //define a constante que representa o limite maximo de relatórios
#define ANBT UINT CPAGE_UTF8 = 65001; \
             SetConsoleOutputCP(CPAGE_UTF8); //define o bagulhonson pra deixar o terminal mostrar acentos e etc

//função que limpa tudo de todas as variáveis que armazenam os bagulhonsons
int limpadorGeral(User *usuarios) {
    for (int g=0; g<LimiteMaxUser; g++) {
        strcpy(usuarios[g].user, "inutilizado");
        strcpy(usuarios[g].password, "inutilizado");
        usuarios[g].accessLevel = 0;
    }
    return 0;
}

//programa
int main() {

    ANBT;

    //definição de variáveis relacionadas a se o programa está rodando e quantas vazes ele já rodou
    int isRunning = 0; //variavel que defnie se o programa continuará rodando ou não ||0: roda||any other: não roda||
    int timesRunned = 0; //variável que vai guardar o numero de execuções que o programa já teve

    //definição de variáveis relacionadas ao login
    int userCount = 0; //variavel que conta quantos usuários cadstrados existem
    User usuarios[LimiteMaxUser]; //variavel array que contém os usuários registrados no sistema

    //declaração das listas
    listaFilmes *filmes = criarCatalogo();
    listaVendas *vendas = criarHistoricoDeVendas();

    //pega dos arquivos o valor de quantas vezes o programa já rodou 
    getTimesRunnedValue(&timesRunned);

    if (timesRunned == 0) {
        //limpa tudo das variáveis caso seja a primeir vez que o programa abra
        limpadorGeral(usuarios);
        printf("\nNenhum usuário registrado, favor registrar um usuário\n");
        registrarAdmin(usuarios, &userCount);
    } else {
        //pega dos arquivos todas as informações dos usuários e das listas 
        getUsersValues(usuarios, &userCount);
        getFilmesValues(filmes);
        getVendasValues(vendas);
    }

    //a parte usável do programa, de fato
    do {
        int logon = login(usuarios);
        switch (logon) {
            case 0: menuDefault(&isRunning, filmes, vendas); break;
            case 2: menuAdmin(usuarios, &userCount, &isRunning, filmes, vendas); break; 
            default: retry(&isRunning);
        }
    } while (isRunning == 0);

    //aumenta o contador de vezes que o programa rodou
    timesRunned++;

    //salva todas as informações
    saveTimesRunnedValue(timesRunned);
    saveUsersValues(usuarios, userCount);
    saveFilmesValues(filmes);
    saveVendasValues(vendas);

    //libera a memoria alocada das listas e seus elementos
    limparListaFilmes(filmes);
    limparListaVendas(vendas);

    return 0; 
}