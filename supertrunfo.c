#include <stdio.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>
// Desenvolvido por Ernesto Silva
// Matrícula: 202507200003
// Data inicial: 17/09/2025
// Data final: 15/10/2025

int main(){
	setlocale(LC_ALL, "PORTUGUESE");
//variaveis
	char estado_a = '\0', estado_b = '\0';                  //variaveis para armazenar os estados     			       

	char codigo_a[4] = "", codigo_b[4] = "";			 //variaveis para armazenar os codigos das cidades	
	char cidade_a[50] = "", cidade_b[50] = "";        //variaveis para armazenar as cidades
	int pop_a = 0, pop_b = 0;				       //variavel população
	float area_a = 0.0f, area_b = 0.0f, pib_a = 0.0f, pib_b = 0.0f;	  //variavel area em km² e PIB
	int turismo_a = 0, turismo_b = 0;	         //variavel pontos turisticos
	float densidade_a = 0.0f, densidade_b = 0.0f; 	//variavel densidade demografica
	float pib_per_capita_a = 0.0f, pib_per_capita_b = 0.0f; //variavel PIB per capita
	int opcao = 0, escolha1 = 0, escolha2 = 0; 		  //variaveis para armazenar as escolhas do usuario

	do{			// loop do-while para repetir o menu até o usuário escolher sair
	
	printf("*** Jogo Super Trunfo ***\n\n");
	printf("==============================\n");
	printf("1. Primeira Carta\n");
	printf("2. Segunda Carta \n");
	printf("3. Visualizar Cartas \n");
	printf("4. Comparar Cartas \n");
	printf("5. Ver as Regras \n");
	printf("6. Sair do Jogo\n");

	printf("Digite a opção desejada: ");
	scanf("%d", &opcao);

	// switch case para o menu
	switch(opcao){
		// coleta de dados da carta 1
		case 1:
			printf("Insira os dados da Carta 1   \n\n");

			printf("Escolha uma letra entre A e H: ");
			scanf(" %c", &estado_a);
			printf("Informe o código da carta, com a letra do Estado seguida de um número(ex: A01, B03): ");
			scanf(" %3s", codigo_a);

			printf("Informe o nome da cidade: ");
			scanf(" %49[^\n]", cidade_a);

			printf("Informe o numero de habitantes: ");
			scanf("%i", &pop_a);

			printf("Informe a Área da cidade em km²: ");
			scanf("%f", &area_a);
			while(getchar() != '\n'); // Limpa o buffer até o ENTER

			printf("Informe o PIB da cidade: ");
			scanf("%f", &pib_a);

			printf("Informe o número de pontos turísticos: ");
			scanf("%i", &turismo_a);
		break;
		// coleta de dados da carta 2
		case 2:
			printf("\n\nAgora informe os dados da Carta 2  \n\n");
				
			printf("Escolha outra letra entre A e H diferente da anterior: ");
			scanf(" %c", &estado_b);
			printf("Informe o código da carta com a letra do Estado seguida de um número(ex: A01, B03): ");
			scanf(" %3s", codigo_b);

			printf("Informe o nome da cidade: ");
			scanf(" %49[^\n]", cidade_b);

			printf("Informe o numero de habitantes: ");
			scanf("%i", &pop_b);

			printf("Informe a Área da cidade em km²: ");
			scanf("%f", &area_b);
			while(getchar() != '\n'); // Limpa o buffer até o ENTER

			printf("Informe o PIB da cidade: ");
			scanf("%f", &pib_b);

			printf("Informe o número de pontos turísticos: ");
			scanf("%i", &turismo_b);
		break;
	case 3:	
			//calculo da densidade demografica
			if (area_a != 0.0f) {
				densidade_a = pop_a / area_a;
			} else {
				densidade_a = 0.0f; // Evita divisão por zero
			}
			//calculo do PIB per capita
			if (pop_a != 0) {
				pib_per_capita_a = (pib_a * 1000000.0f) / pop_a;
			} else {
				pib_per_capita_a = 0.0f;
			}

			//calculo da densidade demografica
			if (area_b != 0.0f) {
				densidade_b = pop_b / area_b;
			} else {
				densidade_b = 0.0f; // Evita divisão por zero
			}
			//calculo do PIB per capita
			if (pop_b != 0) {
				pib_per_capita_b = (pib_b * 1000000.0f) / pop_b;
			} else {
				pib_per_capita_b = 0.0f;
			}

			//mostrando os dados das cartas 

			printf("\n*** Carta 1: *** \n");
			printf("Estado: %c \n", estado_a);			
			printf("Código: %s \n", codigo_a);			
			printf("Nome da Cidade: %s \n", cidade_a);			
			printf("População: %.2f milhões de habitantes\n", pop_a / 1000000.0);			
			printf("Área: %.2f km² \n", area_a);			
			printf("PIB: R$ %.2f milhões de reais \n", pib_a);			
			printf("Número de pontos Turísticos: %i \n", turismo_a);
			printf("Densidade Demográfica: %.2f habitantes por km² \n", densidade_a);
			printf("PIB per capita: R$ %.2f \n", pib_per_capita_a);
	
			printf("\n*** Carta 2: *** \n");			
			printf("Estado: %c \n", estado_b);			
			printf("Código: %s \n", codigo_b);			
			printf("Nome da Cidade: %s \n", cidade_b);			
			printf("População: %.2f milhões de habitantes\n", pop_b / 1000000.0);			
			printf("Área: %.2f km² \n", area_b);			
			printf("PIB: R$ %.2f milhões de reais \n", pib_b);			
			printf("Número de pontos Turísticos: %i \n", turismo_b);
			printf("Densidade Demográfica: %.2f habitantes por km² \n", densidade_b);
			printf("PIB per capita: R$ %.2f \n", pib_per_capita_b);
		break;
	case 4: {
		// calcula densidade e PIB per capita com verificação para evitar divisão por zero
		if (area_a != 0.0f) {
			densidade_a = pop_a / area_a;
		} else {
			densidade_a = 0.0f;
		}
		if (area_b != 0.0f) {
			densidade_b = pop_b / area_b;
		} else {
			densidade_b = 0.0f;
		}
		if (pop_a != 0) {
			pib_per_capita_a = (pib_a * 1000000.0f) / pop_a;
		} else {
			pib_per_capita_a = 0.0f;
		}
		if (pop_b != 0) {
			pib_per_capita_b = (pib_b * 1000000.0f) / pop_b;
		} else {
			pib_per_capita_b = 0.0f;
		}

		// valores que serão comparados
		float comparacao1 = 0.0f, comparacao2 = 0.0f;

		//menu de escolha da categoria para comparar
		printf("\nEscolha 2 atributos para comparar as cartas: \n");
		printf("1. População \n");
		printf("2. PIB per capita \n");
		printf("3. Densidade Demográfica \n");
		printf("4. Número de Pontos Turísticos \n");
		printf("5. PIB \n");
		printf("6. Área \n");

		printf("Digite a primeira opção desejada: ");
		scanf("%d", &escolha1);

		printf("Digite a segunda opção desejada: ");
		scanf("%d", &escolha2);

		// validações simples
		if (escolha1 < 1 || escolha1 > 6) {
			printf("Opção inválida para a primeira escolha!\n");
			break;
		}
		if (escolha2 < 1 || escolha2 > 6) {
			printf("Opção inválida para a segunda escolha!\n");
			break;
		}
		if (escolha2 == escolha1) {
			printf("Você já escolheu essa opção. Por favor, escolha uma opção diferente.\n");
			break;
		}

		// atribui os valores para comparação com base na escolha 1
		switch (escolha1) {
			case 1:
				printf("Você escolheu comparar a População. \n");
				comparacao1 = (float)pop_a;
				break;
			case 2:
				printf("Você escolheu comparar o PIB per capita. \n");
				comparacao1 = pib_per_capita_a;
				break;
			case 3:
				printf("Você escolheu comparar a Densidade Demográfica. \n");
				comparacao1 = densidade_a;
				break;
			case 4:
				printf("Você escolheu comparar o Número de Pontos Turísticos. \n");
				comparacao1 = (float)turismo_a;
				break;
			case 5:
				printf("Você escolheu comparar o PIB. \n");
				comparacao1 = pib_a;
				break;
			case 6:
				printf("Você escolheu comparar a Área. \n");
				comparacao1 = area_a;
				break;
		}

		// atribui os valores para comparação com base na escolha 2
		switch (escolha2) {
			case 1:
				comparacao2 = (float)pop_b;
				break;
			case 2:
				comparacao2 = pib_per_capita_b;
				break;
			case 3:
				comparacao2 = densidade_b;
				break;
			case 4:
				comparacao2 = (float)turismo_b;
				break;
			case 5:
				comparacao2 = pib_b;
				break;
			case 6:
				comparacao2 = area_b;
				break;
		}

		printf("\n\n*** Comparação entre as cartas ***\n");
		printf(" %s: %.2f\n", cidade_a, comparacao1);
		printf(" %s: %.2f\n", cidade_b, comparacao2);

		if (comparacao1 > comparacao2) {
			printf("\nA carta 1 venceu na comparação! \n");
		} else if (comparacao1 < comparacao2) {
			printf("\nA carta 2 venceu na comparação! \n");
		} else {
			printf("\nEmpate na comparação!\n");
		}
	} break;
	case 5:
		printf("\n*** Regras do Jogo Super Trunfo ***\n");
		printf("1. Cada jogador deve criar duas cartas com dados de cidades brasileiras.\n");
		printf("2. Cada carta deve conter os seguintes atributos: Estado (letra de A a H), Código (letra do estado + número), Nome da Cidade, População, Área (km²), PIB (milhões de reais), Número de Pontos Turísticos.\n");
		printf("3. O jogador deve escolher dois atributos para comparar entre as cartas.\n");	
		printf("4. A carta que tiver o maior valor nos atributos escolhidos vence a comparação.\n");
		printf("5. Em caso de empate, o jogo pode ser repetido ou considerado empate.\n");
		printf("6. O jogo continua até que o jogador decida sair.\n");
		printf("7. Divirta-se e aprenda sobre as cidades brasileiras!\n\n");
		break;
	case 6:
		printf("Saindo do jogo. Obrigado por jogar!\n");
		/* quando opcao == 6 o loop será encerrado pelo while abaixo */
		break;
	default:
		printf("Opção inválida! Tente novamente.\n\n");
		break;
	} /* fim do switch */

	} while(opcao != 6); /* condição de saída do loop */
	
	return 0;
}
