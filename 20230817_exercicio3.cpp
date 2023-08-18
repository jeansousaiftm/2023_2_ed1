#include<stdio.h>

void troca(int v[], int a, int b) {
    int tmp = v[a];
    v[a] = v[b];
    v[b] = tmp;
}

void bubbleSort(int v[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (v[j] > v[j + 1]) {
                troca(v, j, j + 1);
            }
        }
    }
}

struct Conjunto {

    int n;
    int v[20];

    Conjunto() {
        n = 0;
    }

    void ler() {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &v[i]);
        }
        bubbleSort(v, n);
    }

    void imprimir() {
        for (int i = 0; i < n; i++) {
            printf("%d\n", v[i]);
        }
    }

    void uniao(Conjunto c2) {
        if (c2.n + n > 20) {
            printf("Tamanho excedido\n");
            return;
        }
        for (int i = n, j = 0; j < c2.n; i++, j++) {
            v[i] = c2.v[j];
            n++;
        }
        bubbleSort(v, n);
    }

    void intersecao(Conjunto c2) {
        int tmp[20], n2 = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < c2.n; j++) {
                if (v[i] == c2.v[j]) {
                    tmp[n2] = v[i];
                    n2++;
                    break;
                }
            }
        }
        for (int i = 0; i < n2; i++) {
            v[i] = tmp[i];
        }
        n = n2;
    }

    bool iguais(Conjunto c2) {
        if (n != c2.n) {
            return false;
        }
        for (int i = 0; i < n; i++) {
            if (v[i] != c2.v[i]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Conjunto c;
    c.ler();
    Conjunto c2;
    c2.ler();
    printf("%d\n", c.iguais(c2));
    return 0;
}
