#include<stdio.h>
#include<string.h>

struct No {

    char valor;
    No *prox;

    No() {
        valor = 0;
        prox = NULL;
    }

    No(char _valor) {
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

    void inserir(char valor) { // O(1)

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

    bool eIgual(char a, char b, char c, char d) {
        if (vazia()) {
            inserir('F');
            inserir('A');
            inserir('C');
            inserir('E');
        }
        if (tamanho() >= 4) {
            if (a == inicio->valor) {
                No *proximo = inicio->prox;
                if (b == proximo->valor) {
                    proximo = proximo->prox;
                    if (c == proximo->valor) {
                        proximo = proximo->prox;
                        if (d == proximo->valor) {
                            remover();
                            remover();
                            remover();
                            remover();
                            return true;
                        }
                    }
                }
            }
        }
        inserir(a);
        inserir(b);
        inserir(c);
        inserir(d);
        return false;
    }

};

int main() {
    int n;
    int r = 0;
    Pilha p;
    scanf("%d%*c", &n);
    while (n--) {
        char a, b, c, d;
        scanf("%c %c %c %c%*c", &a, &b, &c, &d);
        if (p.eIgual(a, b, c, d)) {
            r++;
        }
    }
    printf("%d\n", r);

    return 0;
}
