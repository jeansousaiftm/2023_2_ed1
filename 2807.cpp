#include<stdio.h>

struct No {

    long long valor;
    No *prox;

    No() {
        valor = 0;
        prox = NULL;
    }

    No(long long _valor) {
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

    void inserirInicio(long long valor) { // O(1)

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

    void inserirFinal(long long valor) { // O(1)

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
            if (aux != inicio) printf(" ");
            printf("%lld", aux->valor);
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

    void calculaProximoFibonacci() { // O(1)
        No *aux1 = inicio;
        No *aux2 = inicio->prox;
        long long valor = aux1->valor + aux2->valor;
        inserirInicio(valor);
    }

};

int main() {

    Lista l;

    int n;

    scanf("%d", &n); // O(n)

    l.inserirInicio(1);
    if (n > 1) {
        l.inserirInicio(1);
    }

    for (int i = 2; i < n; i++) {
        l.calculaProximoFibonacci();
    }

    l.imprimir();

    return 0;
}

