#include<stdio.h>

struct Funcionario {

    char nome[100], cargo[50];
    double salarioBase, beneficios, descontos, salario;

    void ler() {
        scanf("%[^\n]%*c", nome);
        scanf("%[^\n]%*c", cargo);
        scanf("%lf %lf %lf%*c", &salarioBase, &beneficios, &descontos);
        salario = salarioBase + beneficios - descontos;
    }

    void imprimir() {
        printf("%s\n", nome);
        printf("%s\n", cargo);
        printf("Salario Base: R$ %.2lf\n", salarioBase);
        printf("Beneficios: R$ %.2lf\n", beneficios);
        printf("Descontos: R$ %.2lf\n", descontos);
        printf("Salario Final: R$ %.2lf\n", salario);
    }

};

struct Loja {

    Funcionario f[10];
    int ultimoFuncionario;
    double totalSalarios, maior;

    Loja() {
        ultimoFuncionario = 0;
        totalSalarios = 0;
        maior = 0;
    }

    void ler() {
        f[ultimoFuncionario].ler();
        totalSalarios += f[ultimoFuncionario].salario;
        if (f[ultimoFuncionario].salario > maior) {
            maior = f[ultimoFuncionario].salario;
        }
        ultimoFuncionario++;
    }

    void listarTodos() {
        for (int i = 0; i < ultimoFuncionario; i++) {
            f[i].imprimir();
        }
    }

    double mediaSalarial() {
        if (ultimoFuncionario == 0) {
            return 0;
        }
        return totalSalarios / ultimoFuncionario;
    }

    double maiorSalario() {
        return maior;
    }

};

int main() {

    Loja l;

    int opcao;

    do {
        printf("1. Cadastrar\n");
        printf("2. Listar\n");
        printf("3. Media Salarial\n");
        printf("4. Maior Salario\n");
        scanf("%d%*c", &opcao);

        if (opcao == 1) {
            l.ler();
        } else if (opcao == 2) {
            l.listarTodos();
        } else if (opcao == 3) {
            printf("R$ %.2lf\n", l.mediaSalarial());
        } else if (opcao == 4) {
            printf("R$ %.2lf\n", l.maiorSalario());
        }

    } while (opcao == 1 || opcao == 2 || opcao == 3 || opcao == 4);

    return 0;
}
