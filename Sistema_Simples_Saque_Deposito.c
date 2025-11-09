#include <stdio.h>
#include <stdlib.h>
#include <string.h>         
#include <locale.h>


int main() {
    setlocale(LC_ALL, "PORTUGUESE");
    int opcao, continuar = 1;
    float saldo = 1000.00; // Exemplo de saldo inicial
    float deposito, saque, agencia, conta;

    while (continuar == 1) {
        printf("*** Menu de Opções ***\n\n");
        printf("1. Verificar Saldo\n");  
        printf("2. Fazer Depósito\n");
        printf("3. Fazer Saque\n");
        printf("4. Sair \n");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("Opção 1 selecionada: Verificar Saldo\n");
                printf("O Seu Saldo é de: %.2f\n", saldo); // Exemplo de saldo
                printf("Deseja continuar? (1-Sim, 2-Não): ");
                scanf("%d", &continuar);
                if (continuar != 1) {
                    printf("Saindo do programa...\n");
                    exit(0);
                }
                system("cls"); // Limpa a tela
                break;
            case 2:
                printf("Opção 2 selecionada: Fazer Depósito\n");
                printf("Digite o valor do depósito: ");
                scanf("%f", &deposito);
                printf("Digite a agencencia: ");
                scanf("%f", &agencia);
                printf("Digite o número da conta: ");
                scanf("%f", &conta);
                saldo += deposito; // Atualiza o saldo com o depósito
                printf("Depósito realizado com sucesso.\n");
                printf("Deseja continuar? (1-Sim, 2-Não): ");
                scanf("%d", &continuar);
                if (continuar != 1) {
                    printf("Saindo do programa...\n");
                    exit(0);
                }
                system("cls"); // Limpa a tela
                break;
            case 3:
                printf("Opção 3 selecionada: Fazer Saque\n");
                printf("Digite o valor do saque: ");
                scanf("%f", &saque);
                if (saque > saldo) {
                    printf("Saldo insuficiente para saque.\n");
                } else {
                    saldo -= saque; // Atualiza o saldo com o saque
                    printf("Saque realizado com sucesso.\n");
                }
                printf("Deseja continuar? (1-Sim, 2-Não): ");
                scanf("%d", &continuar);
                if (continuar != 1) {
                    printf("Saindo do programa...\n");
                    exit(0);
                }
                system("cls"); // Limpa a tela
                break;
            case 4:
                printf("Saindo do programa...\n");
                exit(0);
            default:
                printf("Opção inválida. Tente novamente.\n");
                system("cls"); // Limpa a tela
                break;
        }
    }
    return 0;
}    