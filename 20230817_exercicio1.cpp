#include<stdio.h>
#include<time.h>

struct Data {

    int dia, mes, ano;

    void ler() {
        scanf("%d/%d/%d%*c", &dia, &mes, &ano);
    }

    void imprimir() {
        printf("%02d/%02d/%04d\n", dia, mes, ano);
    }

    int calcularIdade() {

        /*
        int diaHoje = 17;
        int mesHoje = 8;
        int anoHoje = 2023;
        */

        time_t timer;
        struct tm *horarioLocal;

        time(&timer); // Obtem informações de data e hora
        horarioLocal = localtime(&timer); // Converte a hora atual para a hora local

        int diaHoje = horarioLocal->tm_mday;
        int mesHoje = horarioLocal->tm_mon + 1;
        int anoHoje = horarioLocal->tm_year + 1900;

        if (mes < mesHoje || (mes == mesHoje && dia <= diaHoje)) {
            return anoHoje - ano;
        } else {
            return (anoHoje - ano) - 1;
        }

    }

};

struct Cliente {

    char nome[100];
    Data nascimento;
    int idade;
    char sexo;

    void ler() {
        scanf("%[^\n]%*c", nome);
        scanf("%c%*c", &sexo);
        nascimento.ler();
        idade = nascimento.calcularIdade();
    }

    void imprimir() {
        printf("%s\n", nome);
        printf("%c\n", sexo);
        nascimento.imprimir();
        printf("%d\n", idade);
    }

};

int main() {

    Cliente c[50];

    int opcao, ultimoCliente = 0;

    do {
        printf("1. Cadastrar\n");
        printf("2. Listar\n");
        scanf("%d%*c", &opcao);

        if (opcao == 1) {
            c[ultimoCliente].ler();
            ultimoCliente++;
        } else if (opcao == 2) {
            for (int i = 0; i < ultimoCliente; i++) {
                c[i].imprimir();
            }
        }

    } while (opcao == 1 || opcao == 2);


    return 0;
}
