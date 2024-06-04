#include <stdlib.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    int codigo;
    char nome[41];
    double preco;
} Produto;

Produto *p1, p2;

int main (void) {

    p1 = (Produto*) malloc(sizeof(Produto));
    p1->codigo = 1001;
    p1->preco = 1.99;
    strcpy(p1->nome, "leite");

    p2.codigo = 1002;
    p2.preco = 19.8;
    strcpy(p2.nome, "café");

    printf("p1->nome: %s\n", p1->nome);
    printf("p1->codigo: %d\n", p1->codigo);
    printf("p1->preco: %f\n\n", p1->preco);

    printf("p2.nome: %s\n", p2.nome);
    printf("p2.codigo: %d\n", p2.codigo);
    printf("p2.preco: %f", p2.preco);


    return EXIT_SUCCESS;
}