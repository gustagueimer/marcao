#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define charConst 50
typedef struct produto {
    int id;
    char nome[charConst];
    int quantidadeEstoque;
    float valor;
} produto;
//balls 101
void anbt() {
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);
}
void printerProdutos(produto *produtos, int tamanho) {
    for(int i=0; i<tamanho; i++) {
        printf("%i - nome: %s, id: %i, quantidade em estoque: %i, valor: R$%.2f \n", i+1, produtos[i].nome, produtos[i].id, produtos[i].quantidadeEstoque, produtos[i].valor);
    }
}
int findMostCaroProduto(produto *produtos, int tamanho) {
    float biggestValue = 0;
    for(int i=0; i<tamanho; i++) {
        if(produtos[i].valor > biggestValue) biggestValue = produtos[i].valor;
    }
    for(int i=0; i<tamanho; i++) {
        if(produtos[i].valor == biggestValue) return i;
    }
    return -1;
}
int findBiggestStockedProduto( produto * produtos, int tamanho) {
    int biggestStock = 0;
    for(int i=0; i<tamanho; i++) {
        if(produtos[i].quantidadeEstoque > biggestStock) biggestStock = produtos[i].quantidadeEstoque;
    }
    for(int i=0; i<tamanho; i++) {
        if(produtos[i].quantidadeEstoque == biggestStock) return i;
    }
    return -1;
}
int main() {
    anbt();
    produto *produtos = malloc(1 * sizeof(produto));
    if (produtos == NULL) {
        printf("a alocação falhou :( \n");
    } else {
        int size = 0;
        int C = 0;
        do {
        C = 0;
        printf("insira o nome do produto - ");
        scanf("%s", produtos[size].nome);
        printf("insira o id do produto - ");
        scanf("%i", &produtos[size].id);
        printf("insira a quantidade em estoque do produto - ");
        scanf("%i", &produtos[size].quantidadeEstoque);
        printf("insira o valor do produto - ");
        scanf("%f", &produtos[size].valor);
        size++;
        printf("deseja cadastrar mais um produto? (0 - não/any - sim) - ");
        scanf("%i", &C);
        if(C != 0) produtos = realloc(produtos, (size+1) * sizeof(produto));
        } while (C != 0);
        printerProdutos(produtos, size);
        printf("produto com o maior preço: %s, valor: R$%.2f \n", produtos[findMostCaroProduto(produtos, size)].nome, produtos[findMostCaroProduto(produtos, size)].valor);
        printf("produto com o maior quantidade de produtos em estoque: %s, quantidade em estoque: %i \n", produtos[findBiggestStockedProduto(produtos, size)].nome, produtos[findBiggestStockedProduto(produtos, size)].quantidadeEstoque);
    }
    free(produtos);
    system("pause");
    return 0;
}