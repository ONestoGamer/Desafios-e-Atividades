#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#include <conio.h>

float valor1, valor2, resultado;
char op;

int main() {
    setlocale(LC_ALL, "PORTUGUESE");
    
    printf("Calculadora Simples\n");
    printf("Digite o primeiro valor: ");
    scanf("%f", &valor1);
    
    printf("Digite o segundo valor: ");
    scanf("%f", &valor2);
    
    printf("Escolha a operação (+, -, *, /): ");
    op = toupper(getche());
    
    switch (op) {
        case '+':
            resultado = valor1 + valor2;
            break;
        case '-':
            resultado = valor1 - valor2;
            break;
        case '*':
            resultado = valor1 * valor2;
            break;
        case '/':
            if (valor2 != 0) {
                resultado = valor1 / valor2;
            } else {
                printf("\nErro: Divisão por zero!\n");
                return 1;
            }
            break;
        default:
            printf("\nOperação inválida!\n");
            return 1;
    }
    
    printf("\nResultado: %.2f %c %.2f = %.2f\n", valor1, op, valor2, resultado);
    
    return 0;
}