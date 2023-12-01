#include<stdio.h>

void bubbleSort(int v[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (v[j] < v[j + 1]) {
                int tmp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = tmp;
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        int m, v[1001], c[1001], r = 0;
        scanf("%d", &m);
        for (int i = 0; i < m; i++) {
            scanf("%d", &v[i]);
            c[i] = v[i];
        }
        bubbleSort(v, m);
        for (int i = 0; i < m; i++) {
            if (v[i] == c[i]) {
                r++;
            }
        }
        printf("%d\n", r);
    }
    return 0;
}
