#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void troca(int v[], int a, int b) {
    int tmp = v[a];
    v[a] = v[b];
    v[b] = tmp;
}


void bubbleSort(int v[], int n) { // n^2
    for (int i = 0; i < n; i++) { // (2n + 2) * c
        for (int j = 0; j < n - 1; j++) { // (2n * c) * n
            if (v[j] > v[j + 1]) { // (n * n - 1) * c
                troca(v, j, j + 1); // (n * n - 1) * 3c
            }
        }
    }
}

void geraVetor(int v[], int n) {
    for (int i = 0; i < n; i++) {
        v[i] = rand() % n;
    }
}

void imprimeVetor(int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    int n = 100000;
    int v[n];
    geraVetor(v, n);
    imprimeVetor(v, n);
    bubbleSort(v, n);
    imprimeVetor(v, n);
    return 0;
}
