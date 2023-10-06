#include<stdio.h>
#include<string.h>

struct No {

    char idioma[1000], traducao[1000];
    No *prox;

    No() {
        strcpy(idioma, "");
        strcpy(traducao, "");
        prox = NULL;
    }

    No(char _idioma[1000], char _traducao[1000]) {
        strcpy(idioma, _idioma);
        strcpy(traducao, _traducao);
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

    void inserirFinal(char idioma[1000], char traducao[1000]) { // O(1)

        n++;
        No *novo = new No(idioma, traducao);

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
            printf("%s %s -> ", aux->idioma, aux->traducao);
            aux = aux->prox;
        }

        printf("\n");

    }

    char* encontrarTraducao(char idioma[]) { // O(n * |s|)
        No *aux = inicio;
        while (aux != NULL) {
            if (strcmp(aux->idioma, idioma) == 0) {
                return aux->traducao;
            }
            aux = aux->prox;
        }
        return "";
    }

};

int main() {

    Lista l;

    int n, m;

    scanf("%d%*c", &n);

    for (int i = 0; i < n; i++) {
        char idioma[1000], traducao[1000];
        scanf("%[^\n]%*c", idioma);
        scanf("%[^\n]%*c", traducao);
        l.inserirFinal(idioma, traducao);
    }

    scanf("%d%*c", &m);
    for (int i = 0; i < m; i++) {
        char idioma[1000], nome[1000];
        scanf("%[^\n]%*c", nome);
        scanf("%[^\n]%*c", idioma);
        printf("%s\n", nome);
        printf("%s\n\n", l.encontrarTraducao(idioma));
    }

    return 0;
}

