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

/*
    Pilha vazia: { [ (
    Topo da Pilha {: } [ (
    Topo da Pilha [: ] (
    Topo da Pilha (: )
*/
    char tmp[1000];
    int valido = 1;
    scanf("%s", tmp);
    Pilha p;

    for (int i = 0; i < strlen(tmp); i++) {
        if (tmp[i] == '{') {
            if (!p.vazia()) {
                valido = 0;
                break;
            }
            p.inserir('{');
        } else if (tmp[i] == '[') {
            if (!p.vazia() && p.inicio->valor != '{') {
                valido = 0;
                break;
            }
            p.inserir('[');
        } else if (tmp[i] == '(') {
            if (!p.vazia() && p.inicio->valor != '{' && p.inicio->valor != '[') {
                valido = 0;
                break;
            }
            p.inserir('(');
        } else if (tmp[i] == '}') {
            if (p.vazia() || p.inicio->valor != '{') {
                valido = 0;
                break;
            }
            p.remover();
        } else if (tmp[i] == ']') {
            if (p.vazia() || p.inicio->valor != '[') {
                valido = 0;
                break;
            }
            p.remover();
        } else if (tmp[i] == ')') {
            if (p.vazia() || p.inicio->valor != '(') {
                valido = 0;
                break;
            }
            p.remover();
        }
    }

    if (!p.vazia()) {
        valido = 0;
    }

    printf("%d\n", valido);

    return 0;
}
