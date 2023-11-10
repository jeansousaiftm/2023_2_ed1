#include<stdio.h>

struct No {

    int valor;
    No *prox;

    No() {
        valor = 0;
        prox = NULL;
    }

    No(int _valor) {
        valor = _valor;
        prox = NULL;
    }

};

struct Lista {

    No *inicio, *fim;
    int n;

    Lista() {
        inicio = NULL;
        fim = NULL;
        n = 0;
    }

    bool vazia() { // O(1)
        return inicio == NULL;
    }

    void inserirFinal(int valor) { // O(1)

        n++;
        No *novo = new No(valor);

        if (vazia()) {
            inicio = novo;
            fim = novo;
            return;
        }

        fim->prox = novo;
        fim = novo;

    }

    void imprimir() { // O(n)

        No *aux = inicio;

        while (aux != NULL) {
            printf("%d ", aux->valor);
            aux = aux->prox;
        }

        printf("\n");

    }

};

int main() {

    int n, x;
    scanf("%d", &n);

    Lista a, b, r;

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        a.inserirFinal(x);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        b.inserirFinal(x);
    }

    No *aux1 = a.inicio;
    No *aux2 = b.inicio;

    while (aux1 != NULL && aux2 != NULL) {
        r.inserirFinal(aux1->valor);
        r.inserirFinal(aux2->valor);
        aux1 = aux1->prox;
        aux2 = aux2->prox;
    }

    r.imprimir();

    return 0;
}
