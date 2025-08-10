/*Escrever um programa que leia uma matriz 4x4 e calcule a soma de todos os elementos, a soma
dos elementos da diagonal principal. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>         
#include <locale.h>

int valores[4][4], soma_total=0, soma_diag=0, lin, col; 

int main() {
    setlocale(LC_ALL, "PORTUGUESE");
    printf("Digite os valores para uma matriz 4x4:\n\n");
    // Leitura dos valores da matriz
    for (lin=0; lin<4; lin++){      //interval de linhas [0,3] 4x  
        for (col=0; col<4; col++){  //interval de colunas [0,3] 4x
            // Solicita ao usuário o valor para cada posição da matriz
            printf("Informe o valor da posição [%d][%d]: ", lin, col);
            scanf("%d", &valores[lin][col]);
            soma_total += valores[lin][col];     
            if (lin == col) { // Verifica se é um elemento da diagonal principal
                soma_diag += valores[lin][col];
            }        
        }
    }
    printf("\n\nA soma dos valores da matriz é de: %d\n", soma_total);  // Exibe a soma total dos elementos da matriz
    printf("A soma dos elementos da diagonal principal é de: %d\n", soma_diag); // Exibe a soma dos elementos da diagonal principal
}
