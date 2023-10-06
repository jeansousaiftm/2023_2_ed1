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

    void inserirInicio(int valor) { // O(1)

        n++;
        No *novo = new No(valor);

        if (vazia()) {
            inicio = novo;
            fim = novo;
            return;
        }

        novo->prox = inicio;
        inicio = novo;

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

        int i = 0;
        No *aux = inicio;

        while (aux != NULL) {
            printf("X[%d] = %d\n", i++, aux->valor);
            aux = aux->prox;
        }

    }

    /*
    int tamanho() { // O(n)

        int t = 0;

        No *aux = inicio;

        while (aux != NULL) {
            t++;
            aux = aux->prox;
        }

        return t;
    }
    */

    int tamanho() { // O(1)
        return n;
    }

    void removerInicio() { // O(1)

        if (tamanho() <= 1) {
            delete(inicio);
            inicio = NULL;
            fim = NULL;
            n = 0;
            return;
        }

        No *remover = inicio;
        inicio = inicio->prox;
        delete(remover);
        n--;
    }

    void removerFinal() { // O(n)

        if (tamanho() <= 1) {
            delete(inicio);
            inicio = NULL;
            fim = NULL;
            n = 0;
            return;
        }

        No *penultimo = inicio;
        while (penultimo->prox != fim) {
            penultimo = penultimo->prox;
        }
        delete(fim);
        penultimo->prox = NULL;
        fim = penultimo;
        n--;

    }

    void inserir(int valor, int pos) { // O(n)

        if (pos >= tamanho()) {
            inserirFinal(valor);
            return;
        }

        if (pos < 1) {
            inserirInicio(valor);
            return;
        }

        No *aux1 = inicio;
        for (int i = 0; i < pos - 1; i++) {
            aux1 = aux1->prox;
        }
        No *aux2 = aux1->prox;

        No *novo = new No(valor);
        aux1->prox = novo;
        novo->prox = aux2;
        n++;
    }

    void remover(int pos) { // O(n)

        if (pos <= 1) {
            removerInicio();
            return;
        }

        if (pos >= tamanho()) {
            removerFinal();
            return;
        }

        No *aux1 = inicio;
        for (int i = 0; i < pos - 2; i++) {
            aux1 = aux1->prox;
        }
        No *remover = aux1->prox;
        No *aux2 = remover->prox;
        aux1->prox = aux2;
        delete(remover);
        n--;

    }

    void tratarNegativosOuNulos() { // O(n)
        No *aux = inicio;
        while (aux != NULL) {
            if (aux->valor <= 0) {
                aux->valor = 1;
            }
            aux = aux->prox;
        }
    }

};

int main() {

    Lista l;

    int x;

    for (int i = 0; i < 10; i++) {
        scanf("%d", &x);
        // if (x <= 0) x = 1;
        l.inserirFinal(x);
    }

    l.tratarNegativosOuNulos();
    l.imprimir();

    return 0;
}

