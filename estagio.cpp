#include<stdio.h>

struct No {

    int c, m;
    No *prox;

    No() {
        c = 0;
        m = 0;
        prox = NULL;
    }

    No(int _c, int _m) {
        c = _c;
        m = _m;
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

    void inserirFinal(int c, int m) { // O(1)

        n++;
        No *novo = new No(c, m);

        if (vazia()) {
            inicio = novo;
            fim = novo;
            return;
        }

        fim->prox = novo;
        fim = novo;

    }

    void imprimirMaior(int maior) { // O(n)

        No *aux = inicio;

        while (aux != NULL) {
            if (aux->m == maior) {
                printf("%d ", aux->c);
            }
            aux = aux->prox;
        }

        printf("\n");

    }

};

int main() {



    int n, t = 1;

    while (scanf("%d", &n) == 1 && n > 0) {
        Lista l;
        int maior = 0;
        for (int i = 0; i < n; i++) {
            int c, m;
            scanf("%d %d", &c, &m);
            if (m > maior) maior = m;
            l.inserirFinal(c, m);
        }
        printf("Turma %d\n", t++);
        l.imprimirMaior(maior);
    }

    return 0;
}
