#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef unsigned int UINT;

typedef enum {FALSE, TRUE} BOOL;

typedef struct {
    UINT prefixo;
    char companhiaAerea[41];
} Aviao;

typedef struct {
    Aviao *inicio;
    Aviao **informacoes;
    Aviao *fim;
    int tamanho;
} Fila;

Fila *criarFila ();
Fila *adicionarAviao (Fila *fila, Aviao *aviao);  //final
Fila *removerAviao (Fila *fila); // inicio
BOOL filaVazia (Fila *fila);
void imprimirFila (Fila *fila);

int main (void) {

    Fila *fila = criarFila();

    Aviao *aviao1 = (Aviao*) malloc (sizeof(Aviao));
    aviao1->prefixo = 1;
    strcpy(aviao1->companhiaAerea, "Latam");

    Aviao *aviao2 = (Aviao*) malloc (sizeof(Aviao));
    aviao2->prefixo = 2;
    strcpy(aviao2->companhiaAerea, "Latam");

    Aviao *aviao3 = (Aviao*) malloc (sizeof(Aviao));
    aviao3->prefixo = 3;
    strcpy(aviao3->companhiaAerea, "Gol");

    adicionarAviao(fila, aviao1);
    adicionarAviao(fila, aviao2);
    adicionarAviao(fila, aviao3);

    imprimirFila(fila);
    printf("\n");
   
    removerAviao(fila);
    imprimirFila(fila);
    printf("\n");

    adicionarAviao(fila, aviao1);
    imprimirFila(fila);

    return EXIT_SUCCESS;
}

Fila *criarFila () {
    Fila *fila = (Fila*) malloc (sizeof(Fila));
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
    fila->informacoes = NULL;
    return fila;
}

Fila *adicionarAviao (Fila *fila, Aviao *aviao) {
    if (filaVazia(fila)) {
        fila->informacoes = (Aviao**) malloc (sizeof(Aviao**));
        fila->informacoes[0] = (Aviao*) malloc (sizeof(Aviao));
        fila->inicio = fila->informacoes[0];
        fila->inicio->prefixo = aviao->prefixo;
        strcpy(fila->inicio->companhiaAerea, aviao->companhiaAerea);
        fila->tamanho = 1;
    } else {
        fila->informacoes = (Aviao**) realloc (fila->informacoes, sizeof(Aviao**)*fila->tamanho+1);
        fila->inicio = fila->informacoes[0];
        fila->tamanho++;
        fila->fim = fila->inicio;
        fila->fim += fila->tamanho;
        fila->informacoes[fila->tamanho-1] = (Aviao*) malloc (sizeof(Aviao));
        fila->informacoes[fila->tamanho-1]->prefixo = aviao->prefixo;
        strcpy(fila->informacoes[fila->tamanho-1]->companhiaAerea, aviao->companhiaAerea);
    }

    Aviao *adicionado = fila->informacoes[fila->tamanho-1];

    printf("aviao pousou: %u, %s\n", adicionado->prefixo, adicionado->companhiaAerea);

    return fila;
}

Fila *removerAviao (Fila *fila) {
    if (filaVazia(fila)) {
        return fila;
    }
    if (fila->tamanho == 1) {
        fila->fim++;
    }

    Aviao *removido = fila->informacoes[0];

    for (int i = 0; i < fila->tamanho-1; i++) {
        fila->informacoes[i] = fila->informacoes[i+1];
    }
    fila->tamanho--;
    fila->informacoes[fila->tamanho-1] = fila->informacoes[fila->tamanho];;

    printf("aviao decolou: %u, companhia: %s\n", removido->prefixo, removido->companhiaAerea);

    return fila;
}

BOOL filaVazia (Fila *fila) {
    return fila->inicio == NULL;
}

void imprimirFila (Fila *fila) {
    for (int i = 0; i < fila->tamanho; i++) {
        printf("prefixo: %u, companhia aerea: %s\n",fila->informacoes[i]->prefixo, fila->informacoes[i]->companhiaAerea);
    }
}