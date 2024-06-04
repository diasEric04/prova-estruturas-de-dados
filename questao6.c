#include <stdlib.h>
#include <stdio.h>

struct elemento {
    float nota;
    struct elemento *prox;
};

typedef struct elemento Elemento;

Elemento *cria_lista(void);
Elemento *insere_lista1 (Elemento *lista, float nota);
Elemento *insere_lista2 (Elemento *lista, float nota);
int verifica_lista_vazia (Elemento *lista);
void imprime_lista (Elemento *lista);
Elemento *operacao(Elemento *listaUm, Elemento *listaDois);
Elemento *buscar (Elemento *lista, float nota);

int main (void) {
    Elemento *listaUm;
    Elemento *listaDois;
    listaUm = cria_lista();
    listaDois = cria_lista();

    listaUm = insere_lista1(listaUm, 8.0);
    listaUm = insere_lista1(listaUm, 9.2);
    listaUm = insere_lista1(listaUm, 7.8);
    listaUm = insere_lista1(listaUm, 8.5);

    listaDois = operacao(listaUm, listaDois);
    imprime_lista(listaDois);
    Elemento *oito = buscar(listaDois, 7.8);
    printf("\n\nnumero procurado: %.2f", oito->nota);
    getchar();

    return EXIT_SUCCESS;

    /*respota 6.b
    nota:   8.50
    nota:   7.80
    nota:   9.20
    nota:   8.00

    resposta 6.c
    nota:   8.00
    nota:   9.20
    nota:   7.80
    nota:   8.50
    */
}


// resposta 6.a
Elemento *buscar (Elemento *lista, float nota) {
    if (verifica_lista_vazia(lista)) {
        return NULL;
    }

    Elemento *p = lista;

    for (; p != NULL; p = p->prox) {
        if (p->nota == nota) return p;
    }

    return NULL;
}

Elemento *cria_lista(void) {
    return NULL;
}

Elemento *insere_lista1(Elemento *lista, float nota) {
    Elemento *novo = (Elemento*) malloc (sizeof(Elemento));
    novo->prox = lista;
    novo->nota = nota;
    return novo;
}

Elemento *insere_lista2(Elemento *lista, float nota) {
    Elemento *p, *ant = NULL;
    Elemento *novo = (Elemento*) malloc (sizeof(Elemento));
    novo->nota = nota;
    novo->prox = NULL;

    if (verifica_lista_vazia(lista))
        lista = novo;
    else {
        p = lista;
        while (p != NULL) {
            ant = p;
            p = p->prox;
        }
        ant->prox = novo;
    }
    return lista;
}

void imprime_lista (Elemento *lista) {
    if (verifica_lista_vazia(lista)) {
        printf("lista está vazia");
    } else {
        Elemento *p;
        for (p = lista; p != NULL; p = p->prox) {
            printf("nota: %6.2f\n", p->nota);
        }
    }
}

int verifica_lista_vazia(Elemento *lista) {
    return (lista == NULL);
}

Elemento *operacao(Elemento *listaUm, Elemento *listaDois) {
    Elemento *p;
    p = listaUm;
    while (p != NULL) {
        listaDois = insere_lista2(listaDois, p->nota);
        p = p->prox;
    }

    return listaDois;
}