/*Escreva um programa em C para solucionar os seguintes problemas:
1. O sistema deve apresentar ao usuário um menu com as seguintes opções: 
1-Incluir; 
2-Alterar; 
3-Excluir e 
4-Imprimir na tela
O cadastro de N produtos de um determinado departamento de uma loja. 
Para o cadastro deve ser utilizado uma estrutura de dados tipo registro com as seguintes
informações: Código do Produto, Nome do Produto, Valor de Custo, Valor de Venda, Quantidade
em Estoque.*/
#include <stdio.h>  // Inclui a biblioteca padrão de entrada e saída
#include <stdlib.h> // Inclui a biblioteca padrão de utilidades, como alocação de memória e controle de processos
#include <string.h> // Inclui a biblioteca padrão de manipulação de strings        
#include <locale.h> // Inclui a biblioteca para manipulação de localidade e formatação de texto
#include <conio.h> // Inclui a biblioteca para entrada e saída de console, como leitura de teclas e manipulação de tela
#include <ctype.h> // Inclui a biblioteca para manipulação de caracteres, como conversão de maiúsculas e minúsculas

struct cadastro_produto {   // Definição da estrutura cadastro_produto
    // A estrutura contém os campos necessários para armazenar as informações do produto
    int codigo_produto;
    char nome_produto[50];
    float valor_custo;
    float valor_venda;
    int quantidade_estoque;
};
struct cadastro_produto produto[100]; // Declaração de um array de estruturas cadastro_produto para armazenar até 5 produtos
int i, j, n = 0; // Variáveis para armazenar a opção do usuário e o número de produtos cadastrados
int op; // Variável para armazenar a opção do usuário
int cont;
float valor_estoque;
char resp;

int main() {
    setlocale(LC_ALL, "PORTUGUESE");
    printf("Bem-vindo ao sistema de cadastro de produtos!\n");
    printf("=========================================================\n");
    printf("Você pode cadastrar até 100 produtos.\n");
    printf("==========================================================\n");
    printf("Para sair do sistema, selecione a opção 6 no menu.\n");
   
    do {
            //system("cls"); // Limpa a tela do console
            printf("\n------------Menu de Opções--------------:\n");
            printf("1 - Incluir Produto\n");
            printf("2 - Alterar Produto\n");
            printf("3 - Excluir Produto\n");
            printf("4 - Imprimir Produtos\n");
            printf("5 - Para exibir Relatório do custo total do estoque\n");
            printf("6 - Sair\n\n");
            scanf("%d", &op); // Lê a opção do usuário
  
        switch (op){
    
        case 1: // Opção para incluir produto
            if (n >99) { // Verifica se ainda há espaço para mais produtos no máximo de 100 produtos
                printf("Limite de cadastro de produtos atingido!\n");
            break; // Sai do switch se o limite for atingido
            }
            do {
                printf("\nEntre com o código do produto: ");
                scanf("%i", &produto[n].codigo_produto);
                printf("Entre com o nome do produto: ");
                scanf(" %[^\n]", produto[n].nome_produto); // Lê o nome do produto
                printf("Entre com o valor de custo: ");
                scanf("%f", &produto[n].valor_custo);
                printf("Entre com o valor de venda: ");
                scanf("%f", &produto[n].valor_venda);
                printf("Entre com a quantidade em estoque: ");
                scanf("%i", &produto[n].quantidade_estoque);
                n++; // Incrementa o número de produtos cadastrados
                printf("Produto cadastrado com sucesso!\n");
                printf("Total de produtos cadastrados: %i\n", n); // Exibe o total de produtos cadastrados
                printf("Deseja cadastrar mais produtos? (S/N): ");
                fflush(stdin);
                resp = toupper(getche());
                printf("\n");
            } while (toupper(resp) == 'S');
            break;

        case 2: // Opção para alterar produto
        {
            int codigo_alterar;
            int encontrado = 0;
            printf("Entre com o código do produto a ser alterado: ");
            scanf("%i", &codigo_alterar);
            for (i=0; i<n; i++) {
                if (produto[i].codigo_produto == codigo_alterar){  // Verifica se o código do produto existe
                    printf("Entre com o novo nome do produto: ");
                    scanf(" %[^\n]", produto[i].nome_produto);
                    printf("Entre com o novo valor de custo: ");
                    scanf("%f", &produto[i].valor_custo);
                    printf("Entre com o novo valor de venda: ");
                    scanf("%f", &produto[i].valor_venda);
                    printf("Entre com a nova quantidade em estoque: ");
                    scanf("%i", &produto[i].quantidade_estoque);
                    encontrado = 1;
                    printf("Produto alterado com sucesso!\n");
                    break;
                }
            }
            if (!encontrado)
                printf("Produto não encontrado!\n");
            system("pause");
            break;
        }

        case 3: // Opção para excluir produto
        {
            int codigo_excluir;
            int encontrado = 0;
            printf("Entre com o código do produto a ser excluído: ");
            scanf("%i", &codigo_excluir);
            for (i=0; i<n; i++) {
                if (produto[i].codigo_produto == codigo_excluir) { // Verifica se o código do produto existe
                    printf("Confirma a exclusão do produto? (S/N): ");
                    fflush(stdin); // Limpa o buffer de entrada
                    resp = toupper(getche()); // Lê a resposta do usuário
                    printf("\n");
                    if (resp == 'S') { // Se o usuário confirmar a exclusão
                        for (j=i; j<n-1; j++) { // Move os produtos para preencher o espaço vazio
                            produto[j] = produto[j+1];
                        }
                        n--; // Decrementa o número de produtos cadastrados
                        printf("Produto excluído com sucesso!\n");
                    } else {
                        printf("Exclusão cancelada!\n");
                    }
                    encontrado = 1;
                    break;
                }
            }
            if (!encontrado)
                printf("Produto não encontrado!\n"); // Mensagem se o produto não for encontrado
            system("pause"); // Pausa o programa para o usuário ler a mensagem
            break; // Sai do loop se o produto for encontrado
        }

        case 4: // Opção para imprimir produtos
            printf("********Lista de Produtos Cadastrados********\n\n");            
            for (i=0; i<n; i++) { // Loop para imprimir todos os produtos cadastrados
                if (produto[i].codigo_produto != 0) { // Pula produtos excluídos
                    // Imprime as informações do produto formatadas
                    printf("\n%-4i", produto[i].codigo_produto); // Formata o código do produto com 4 caracteres
                    printf("%-20s", produto[i].nome_produto); // Formata o nome do produto com 20 caracteres
                    printf("%8.2f", produto[i].valor_custo); // Formata o valor de custo com 2 casas decimais
                    printf("\t%10.2f", produto[i].valor_venda); // Formata o valor de venda com 2 casas decimais
                    printf("\t%8i", produto[i].quantidade_estoque); // Formata a quantidade em estoque com 4 caracteres
                    printf("\n---------------------------------------------------------\n");
                }
            }
            system("pause"); // Pausa o programa para o usuário ler a lista de produtos
            break; // Sai do loop após imprimir todos os produtos
        case 5: // Opção para exibir relatório do custo total do estoque
            printf("********Relatório do Custo Total do Estoque********\n\n");
            valor_estoque = 0; // Inicializa o valor total do estoque
            for (i=0; i<n; i++)  // Loop para calcular o valor total do estoque
                valor_estoque += produto[i].valor_custo * produto[i].quantidade_estoque; // Calcula o valor total do estoque
            printf("---------------------------------------\n");
            printf("Valor total do estoque: R$ %.2f\n", valor_estoque); // Exibe o valor total do estoque
            printf("\n---------------------------------------\n");
            printf("Pressione qualquer tecla para continuar...\n");
            system("pause"); // Pausa o programa para o usuário ler o relatório;
            break; // Sai do switch após a opção ser processada
        case 6:
            break;
        default: // Caso a opção não seja válida
            printf("Opção inválida! Por favor, escolha uma opção válida.\n");
            system("pause"); // Pausa o programa para o usuário ler a mensagem
            break; // Sai do switch se a opção for inválida
                      
        }

    } while (op != 6); // Continua o loop até que o usuário escolha a opção de sair
    
}  