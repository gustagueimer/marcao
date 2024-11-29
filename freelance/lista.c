#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
//balls 101

typedef struct Item {
    int item;
    struct Item *next;
} item;

typedef struct item *lista;

void anbt() {
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);
}

lista* createLista() {
    lista *newLista = (lista*) malloc (sizeof(lista));
    if(newLista == NULL) {
        printf("erro na alocação :( \n");
        exit(0);
    } else {
        printf("alocação deu certo \n");
        printf("newLista: %p \n", newLista);
        *newLista = NULL;
    }
    return newLista;
}

void adicionarNoInicio(lista *lista) {
    item *novoItem = (item*) malloc (sizeof(item));
    if(novoItem == NULL) {
        printf("erro na alocação :( \n");
        exit(0);
    } else {
        printf("alocação deu certo \n");
        printf("insira o valor do novo item: ");
        scanf("%i", &novoItem->item);
        novoItem->next = *lista;
        *lista = novoItem;
    }
}

void adicionarNoFinal(lista *lista) {
    item *novoItem = (item*) malloc (sizeof(item));
    if(novoItem == NULL) {
        printf("erro na alocação :( \n");
        exit(0);
    } else {
        printf("alocação deu certo \n");
        printf("insira o valor do novo item: ");
        scanf("%i", &novoItem->item);
        novoItem->next = NULL;
        if(*lista == NULL) {
            *lista = novoItem;
        } else {
            item *temp;
            temp = (*lista);
            while(temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = novoItem;
        }
    }
}

void mostrarItensDaLista(lista *lista) {
    item *temp = *lista;
    int counter = 0;
    if(*lista == NULL) {
        printf("lista vazia :P \n");
    } else {
        while(temp->next != NULL) {
            counter++;
            printf("%i° item: %i \n", counter, temp->item);
            temp = temp->next;
        }
        counter++;
        printf("%i° item: %i \n", counter, temp->item);
    }
    printf("\n");
}

void menu(lista *lista) {
    int opsao = 1;
    do {
        printf("menuzinho: \n");
        printf("1-adicionar no topo da lista. \n");
        printf("2-adicionar no final da lista. \n");
        printf("3-mostrar lista. \n");
        printf("0-sair :( \n");
        printf("escolha uma opção: ");
        scanf("%i", &opsao);
        switch (opsao) {
            case 1: adicionarNoInicio(lista); break;
            case 2: adicionarNoFinal(lista); break;
            case 3: mostrarItensDaLista(lista); break;
            case 0: printf("saindo :( \n"); break;
            default: printf("opsao invalida :P \n");
        }
    } while(opsao != 0);
}

int main() {
    anbt();
    lista * a = createLista();
    menu(a);
    free(a);
}
