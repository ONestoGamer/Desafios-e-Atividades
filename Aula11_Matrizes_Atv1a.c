/*Escrever um programa que leia uma matriz 3x2 de números inteiros e calcule a soma de todos os
elementos (valores) da matriz.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>         
#include <locale.h>

int valores[3][2], soma=0, lin, col; 

int main() {
    setlocale(LC_ALL, "PORTUGUESE");
    for (lin=0; lin<3; lin++){      //intervalo de 0 a 2 para linhas 3x
        for (col=0; col<2; col++){  //intervalo de 0 a 1 para colunas 2x
            printf("Informe o valor da posição [%d][%d]: ", lin, col);
            scanf("%d", &valores[lin][col]);
            soma = soma + valores[lin][col];
        }
    }
    printf("\n\nA soma dos valores da matriz 3x2 é de: %d", soma);
}
