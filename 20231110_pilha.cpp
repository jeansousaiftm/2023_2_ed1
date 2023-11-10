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

struct Pilha {

    No *inicio;
    int n;

    Pilha() {
        inicio = NULL;
        n = 0;
    }

    bool vazia() { // O(1)
        return inicio == NULL;
    }

    void inserir(int valor) { // O(1)

        n++;
        No *novo = new No(valor);

        if (vazia()) {
            inicio = novo;
            return;
        }

        novo->prox = inicio;
        inicio = novo;

    }

    void imprimir() { // O(n)

        No *aux = inicio;

        while (aux != NULL) {
            printf("%d -> ", aux->valor);
            aux = aux->prox;
        }

        printf("\n");

    }

    int tamanho() { // O(1)
        return n;
    }

    void remover() { // O(1)

        if (tamanho() <= 1) {
            delete(inicio);
            inicio = NULL;
            n = 0;
            return;
        }

        No *r = inicio;
        inicio = inicio->prox;
        delete(r);
        n--;
    }

};

int main() {

    Pilha p;

    p.inserir(1);
    p.inserir(2);
    p.inserir(3);
    p.remover();
    p.remover();
    p.remover();
    p.remover();
    p.imprimir();

    return 0;
}

