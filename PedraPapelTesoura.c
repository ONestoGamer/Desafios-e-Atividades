#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>

// Função auxiliar para imprimir a jogada, evitando repetição de código
void imprimirJogada(int jogada) {
    switch (jogada) {
        case 1: printf("Pedra"); break;
        case 2: printf("Papel"); break;
        case 3: printf("Tesoura"); break;
        case 4: printf("Lagarto"); break;
        case 5: printf("Spock"); break;
    }
}

int main() {
    setlocale(LC_ALL, "PORTUGUESE");

    int opcao;
    char novamente = 'S';
    int esc_pc, esc_usr;

    srand(time(NULL));

    do {
        printf("===== Bem vindo ao Pedra, Papel, Tesoura, Lagarto e Spock! =====\n\n");
        printf("*** Menu de Opções ***\n\n");
        printf("1. Iniciar Jogo\n");
        printf("2. Verificar Regras\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                //  O computador sorteia um número de 1 a 5.
                esc_pc = rand() % 5 + 1;

                // O menu do jogo.
                printf("\nEscolha uma das opções:\n");
                printf("1. Pedra\n");
                printf("2. Papel\n");
                printf("3. Tesoura\n");
                printf("4. Lagarto\n");
                printf("5. Spock\n");
                printf("Escolha: ");
                scanf("%d", &esc_usr);

                printf("\nSua escolha: ");
                imprimirJogada(esc_usr);
                printf("\nO computador escolheu: ");
                imprimirJogada(esc_pc);
                printf("\n\n");

                printf("Resultado: ");

                if (esc_usr < 1 || esc_usr > 5) {
                    printf("Jogada errada!\n\n");
                } else if (esc_pc == esc_usr) {
                    printf("Deu Empate!\n\n");
                } 
                
                else {
                    // Bloco de lógica para quando o usuário escolhe PEDRA (1)
                    if (esc_usr == 1) { 
                        if (esc_pc == 3) printf("Parabéns, você ganhou! Pedra quebra Tesoura! \n\n");
                        else if (esc_pc == 4) printf("Parabéns, você ganhou! Pedra esmaga Lagarto!\n\n");
                        else if (esc_pc == 2) printf("Não foi dessa vez, você perdeu! Papel cobre Pedra!\n\n");
                        else printf("Não foi dessa vez, você perdeu!! Spock vaporiza Pedra!\n\n"); // vs Spock(5)
                    }
                    // Bloco de lógica para quando o usuário escolhe PAPEL (2)
                    else if (esc_usr == 2) {
                        if (esc_pc == 1) printf("Parabéns, você ganhou! Papel cobre Pedra!\n\n");
                        else if (esc_pc == 5) printf("Parabéns, você ganhou! Papel refuta Spock!\n\n");
                        else if (esc_pc == 3) printf("Não foi dessa vez, você perdeu!! Tesoura corta Papel!\n\n");
                        else printf("Não foi dessa vez, você perdeu!! Lagarto come Papel!\n\n"); // vs Lagarto(4)
                    }
                    // Bloco de lógica para quando o usuário escolhe TESOURA (3)
                    else if (esc_usr == 3) {
                        if (esc_pc == 2) printf("Parabéns, você ganhou! Tesoura corta Papel!\n\n");
                        else if (esc_pc == 4) printf("Parabéns, você ganhou! Tesoura decapita Lagarto!\n\n");
                        else if (esc_pc == 1) printf("Não foi dessa vez, você perdeu!! Pedra quebra Tesoura!\n\n");
                        else printf("Não foi dessa vez, você perdeu! Spock quebra Tesoura!\n\n"); // vs Spock(5)
                    }
                    // Bloco de lógica para quando o usuário escolhe LAGARTO (4)
                    else if (esc_usr == 4) {
                        if (esc_pc == 5) printf("Parabéns, você ganhou! Lagarto envenena Spock!\n\n");
                        else if (esc_pc == 2) printf("Parabéns, você ganhou! Lagarto come Papel!\n\n");
                        else if (esc_pc == 1) printf("Não foi dessa vez, você perdeu! Pedra esmaga Lagarto!\n\n");
                        else printf("Não foi dessa vez, você perdeu! Tesoura decapita Lagarto!\n\n"); // vs Tesoura(3)
                    }
                    // Bloco de lógica para quando o usuário escolhe SPOCK (5)
                    else if (esc_usr == 5) {
                        if (esc_pc == 3) printf("Parabéns, você ganhou! Spock quebra Tesoura! Vida Longa e Próspera!\n\n");
                        else if (esc_pc == 1) printf("Parabéns, você ganhou! Spock vaporiza Pedra! Vida Longa e Próspera!\n\n");
                        else if (esc_pc == 4) printf("Não foi dessa vez, você perdeu! Lagarto envenena Spock!\n\n");
                        else printf("Não foi dessa vez, você perdeu! Papel refuta Spock!\n\n"); // vs Papel(2)
                    }
                }
                break;

            case 2:
                // As regras do jogo.
             printf("\n*** Regras do Jogo ***\n");
             printf("- Tesoura corta Papel\n");
             printf("- Papel cobre Pedra\n");
             printf("- Pedra esmaga Lagarto\n");
             printf("- Lagarto envenena Spock\n");
             printf("- Spock derrete Tesoura\n");
             printf("- Tesoura decapita Lagarto\n");
             printf("- Lagarto come Papel\n");
             printf("- Papel refuta Spock\n");
             printf("- Spock vaporiza Pedra\n");
             printf("- Pedra amassa Tesoura\n\n");
                break;

            case 3:
                printf("\nObrigado por jogar! Saindo...\n");
                continue; 

            default:
                printf("\nOpção inválida! Tente novamente.\n\n");
                break;
        }
        
        if (opcao == 1 || opcao == 2) {
            printf("Deseja voltar ao menu principal? (S/N)?\n");
            scanf(" %c", &novamente); 
        }

    } while ((novamente == 's' || novamente == 'S') && opcao != 3);

    return 0;
}