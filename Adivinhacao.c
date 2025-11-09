#include <stdio.h>
#include <stdlib.h>
#include <string.h>         
#include <locale.h>
#include <time.h>


int main() {
    setlocale(LC_ALL, "PORTUGUESE");
    int opcao;
    char novamente;
    int tentativas;     // variavel de controle de tentativas
    int num_pc, num_usr; // variáveis para armazenar os números do usuário e os gerados pelo PC
    int acertou = 0;  // Flag para saber se o user acertou. 0 = não. 1 = sim.
    srand(time(NULL)); // semente para números aleatórios
    
    do {
        printf("*** Menu de Opções ***\n\n");
        printf("1. Iniciar Jogo\n");
        printf("2. Verificar Regras\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:        
                num_pc = rand() % 11; // rand com intervalo entre 0 e 10
                printf("Iniciando o jogo...\n");
                printf("Eu pensei em um número de 0 a 10, você tem 3 tentativas para adivinhar!\n");

            for (tentativas = 1; tentativas <=3; tentativas++){ //laço FOR para controlar as 3 tentativas
                printf("\n*** Tentativa %d ***\n", tentativas);
                printf("Digite o seu palpite: ");
                scanf("%d", &num_usr);

                if (num_usr == num_pc){
                    printf("Parabéns, você acertou na tentativa %d!\n", tentativas);
                    acertou = 1;
                break;
                } else {
                    printf("Errou...");
                    if (num_pc > num_usr) {
                    printf("O número que pensei é MAIOR que %d.\n", num_usr);
                } else {
                    printf("O número que pensei é MENOR que %d.\n", num_usr);
                 }
            }
        }   
		    if (acertou == 0) {
			    printf("ERROOOUUU... O número que eu pensei foi %d, GAME OVER!!", num_pc);
		    } 
            break;
            case 2:
                printf("Regras do jogo:\n");
                printf("1. O jogo começa com um número aleatório.\n");
                printf("2. O jogador deve adivinhar o número.\n");  
                printf("3. O jogador tem 3 tentativas.\n");
                printf("4. A cada erro, uma dica será dada.\n");
                printf("5. Se o jogador adivinhar corretamente, ele ganha.\n");
                break;
            case 3:
                printf("Saindo do jogo...\n");
                break;
            default:
                printf("Opção inválida! Por favor, escolha uma opção válida.\n");
                break;
        }
        if (opcao != 3) {
            printf("\n\nDeseja voltar ao menu principal? (S/N): ");
            scanf(" %c", &novamente);
        }
    } while (novamente == 's' || novamente == 'S');
    
       printf("Obrigado por jogar! Tchau!!\n");

    
    return 0;
        
}