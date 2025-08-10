/*Escreva um programa C que a partir de uma dimensão N de uma matriz quadrada NxN (N máximo = 30)
descubra se a matriz é triangular inferior ou superior ou apenas quadrada
Considere nulos os valores com Zero.*/

/*Uma matriz é dita triangular inferior se todos os elementos situados acima de sua diagonal
principal são nulos. 
Uma matriz é dita triangular superior se todos os elementos situados abaixo da
diagonal principal são nulos.
Uma matriz é dita quadrada se o número de linhas é igual ao número de colunas.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>         
#include <locale.h>

int matriz[5][5], triangular_inferior = 1, triangular_superior = 1, diag_princ = 0, lin, col;

int main() {
    setlocale(LC_ALL, "PORTUGUESE");
    for (lin = 0; lin < 5; lin++) {
        for (col = 0; col < 5; col++) {
            printf("Digite o valor da linha %d e coluna %d: ", lin + 1, col + 1);
            scanf("%d", &matriz[lin][col]);
        }
    }
    for (lin = 0; lin < 5; lin++) {
        for (col = 0; col < 5; col++) {
            if (lin < col && matriz[lin][col] != 0) {
                triangular_inferior = 0;
            }
            if (lin > col && matriz[lin][col] != 0) {
                triangular_superior = 0;
            }
            if (lin == col && matriz[lin][col] != 0) {
                diag_princ++;
            }
        }
    }
    if (triangular_superior == 1 && triangular_inferior == 0) {
        printf("A matriz é triangular superior.\n");
    } else if (triangular_inferior == 1 && triangular_superior == 0) {
        printf("A matriz é triangular inferior.\n");
    } else if (diag_princ == 5) {
        printf("A matriz é quadrada.\n");
    } else {
        printf("A matriz não é triangular nem quadrada.\n");
    }
}