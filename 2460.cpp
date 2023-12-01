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

    void imprimir(int v[]) { // O(n)

        No *aux = inicio;
        int imprimiu = 0;

        while (aux != NULL) {

            if (v[aux->valor] == 1) {
                if (imprimiu == 1) {
                    printf(" ");
                }
                printf("%d", aux->valor);
                imprimiu = 1;
            }
            aux = aux->prox;
        }

        printf("\n");

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

    void removerPorValor(int valor) { // O(n)

        No *aux1 = inicio, *aux2;

        while (aux1 != NULL && aux1->valor != valor) {
            aux2 = aux1;
            aux1 = aux1->prox;
        }

        if (aux1 == NULL) {
            return;
        } else if (aux1 == inicio) {
            removerInicio();
        } else if (aux1 == fim) {
            removerFinal();
        } else {
            aux2->prox = aux1->prox;
            delete(aux1);
        }

        n--;

    }

};

int main() {

    Lista l;

    int n, m, x, v[100001];
    for (int i = 0; i <= 100000; i++) {
        v[i] = 0;
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        l.inserirFinal(x);
        v[x] = 1;
    }
    scanf("%d", &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        v[x] = 0;
    }
    l.imprimir(v);

    return 0;
}
