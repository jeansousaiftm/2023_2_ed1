#include<stdio.h>

struct Livro {

    char titulo[100], autor[100];
    int numeroPaginas;

    void ler() {
        scanf("%[^\n]%*c", titulo);
        scanf("%[^\n]%*c", autor);
        scanf("%d%*c", &numeroPaginas);
    }

    void imprimir() {
        printf("%s - %s - %d paginas.\n",
               titulo, autor, numeroPaginas);
    }

};

struct Biblioteca {

    Livro livros[10];
    int qtdLivros;

    Biblioteca() {
        qtdLivros = 0;
    }

    void lerLivro() {
        if (qtdLivros >= 10) {
            printf("Biblioteca cheia.\n");
            return;
        }
        livros[qtdLivros].ler();
        qtdLivros++;
    }

    void imprimirTodos() {
        if (qtdLivros == 0) {
            printf("Biblioteca vazia.\n");
            return;
        }
        for (int i = 0; i < qtdLivros; i++) {
            livros[i].imprimir();
        }
    }

    void imprimirMaiorLivro() {
        if (qtdLivros == 0) {
            printf("Biblioteca vazia.\n");
            return;
        }
        int maiorQtdPaginas = 0, indice = -1;
        for (int i = 0; i < qtdLivros; i++) {
            if (livros[i].numeroPaginas > maiorQtdPaginas) {
                maiorQtdPaginas = livros[i].numeroPaginas;
                indice = i;
            }
        }
        livros[indice].imprimir();
    }

};

int main() {

    Biblioteca b;

    int opcao;

    do {
        printf("1. Ler livro\n");
        printf("2. Imprimir todos\n");
        printf("3. Imprimir maior\n");
        printf("0. Sair\n");
        scanf("%d%*c", &opcao);
        switch (opcao) {
            case 1:
                b.lerLivro();
                break;
            case 2:
                b.imprimirTodos();
                break;
            case 3:
                b.imprimirMaiorLivro();
                break;
        }
     } while (opcao == 1 || opcao == 2 || opcao == 3);

    return 0;
}
