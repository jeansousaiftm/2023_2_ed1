#include<stdio.h>

struct Item {

    char nome[100];
    double qtd, preco, total;

    void ler() {
        scanf("%[^\n]s%*c", nome);
        scanf("%lf%*c", &qtd);
        scanf("%lf%*c", &preco);
        calcularTotal();
    }

    void calcularTotal() {
        total = qtd * preco;
    }

    void imprimir() {
        printf("%20s\t%.1lf\t%.2lf\t%.2lf\n",
               nome, qtd, preco, total);
    }

};

struct Venda {

    int qtd;
    double total;
    Item itens[100];

    void ler() {
        scanf("%d%*c", &qtd);
        for (int i = 0; i < qtd; i++) {
            itens[i].ler();
        }
        calcularTotal();
    }

    void calcularTotal() {
        total = 0;
        for (int i = 0; i < qtd; i++) {
            total += itens[i].total;
        }
    }

    void imprimir() {
        printf("%20s\t%s\t%s\t%s\n",
               "Item", "Qtd", "Unit", "Total");
        for (int i = 0; i < qtd; i++) {
            itens[i].imprimir();
        }
        printf("Total da venda: %.2lf\n", total);
    }
};

int main() {
    Venda v;
    v.ler();
    v.imprimir();
    return 0;
}
