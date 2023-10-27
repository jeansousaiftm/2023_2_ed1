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

    No *inicio, *fim, *mediana;
    int n;

    Lista() {
        inicio = NULL;
        fim = NULL;
        mediana = NULL;
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
            mediana = novo;
            return;
        }

        fim->prox = novo;
        fim = novo;

        if (tamanho() % 2 == 1) {
            mediana = mediana->prox;
        }

    }

    void imprimir() { // O(n)

        No *aux = inicio;

        while (aux != NULL) {
            printf("%d ", aux->valor);
            aux = aux->prox;
        }

        printf("%.2lf\n", calculoMediana());

    }

    int tamanho() { // O(1)
        return n;
    }

    double calculoMediana() { // O(1)
        if (tamanho() % 2 == 0) {
            No *proximo = mediana->prox;
            return (mediana->valor + proximo->valor) / 2.0;
        } else {
            return mediana->valor;
        }
    }

};

int main() {

    Lista l;

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        l.inserirFinal(x);
        l.imprimir();
    }

    return 0;
}

