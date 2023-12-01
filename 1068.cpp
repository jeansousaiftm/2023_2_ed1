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

};

int main() {
    char exp[1010];

    while (scanf("%s", exp) != EOF) {
        Pilha p;
        int correto = 1;
        for (int i = 0; i < strlen(exp); i++) {
            if (exp[i] == '(') {
                p.inserir('(');
            } else if (exp[i] == ')') {
                if (p.vazia()) {
                    correto = 0;
                    break;
                } else {
                    p.remover();
                }
            }
        }
        if (p.vazia() && correto == 1) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
    }


    return 0;
}
