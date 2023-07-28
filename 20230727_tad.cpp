#include<stdio.h>

struct Aluno {

    char nome[100];
    char email[100];
    int ra;

    void imprimir() {
        printf("Nome: %s\n", nome);
        printf("E-mail: %s\n", email);
        printf("RA: %d\n", ra);
    }

    void ler() {
        scanf("%[^\n]%*c", nome);
        scanf("%[^\n]%*c", email);
        scanf("%d%*c", &ra);
    }

};

int main() {
    Aluno a[10];
    for (int i = 0; i < 10; i++) {
        a[i].ler();
        a[i].imprimir();
    }
    return 0;
}
