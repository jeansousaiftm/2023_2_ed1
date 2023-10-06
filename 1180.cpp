#include<stdio.h>

struct No {

    int valor, posicao;
    No *prox;

    No() {
        valor = 0;
        prox = NULL;
    }

    No(int _valor, int _posicao) {
        valor = _valor;
        posicao = _posicao;
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

    void inserirFinal(int valor, int posicao) { // O(1)

        n++;
        No *novo = new No(valor, posicao);

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
            printf("%d %d -> ",
                   aux->valor, aux->posicao);
            aux = aux->prox;
        }

        printf("\n");

    }

    void acharMenor() { // O(n)

        if (!vazia()) {

            int m = inicio->valor;
            int p = inicio->posicao;

            No *aux = inicio;

            while (aux != NULL) {
                if (aux->valor < m) {
                    m = aux->valor;
                    p = aux->posicao;
                }
                aux = aux->prox;
            }

            printf("Menor valor: %d\n", m);
            printf("Posicao: %d\n", p);

        }

    }

};

int main() {

    Lista l;

    int n, x;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        l.inserirFinal(x, i);
    }

    l.acharMenor();

    return 0;
}

