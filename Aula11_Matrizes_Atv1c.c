/*Escrever um programa que leia uma matriz 30x2. As linhas representam os dias e as colunas as
entradas (receitas) e despesas (saídas) e calcule o saldo atual (entradas – saídas).*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>         
#include <locale.h>

float dias[30][2], saldo = 0, rec_total = 0, desp_total = 0;
int i;

int main() {
    setlocale(LC_ALL, "PORTUGUESE");
    
    printf("\n\nPrograma para calcular o saldo mensal com entradas diarias\n");
    printf("----------------------------------------------------------\n\n");
    printf("Informe as receitas e despesas de cada dia do mes:\n\n");

    for (i=0; i<30; i++) {      //intervalo de 0 a 29 = 30 dias
        printf("Informe os valores de Entrada e Saída do dia %i: ", i+1);
        scanf("%f %f", &dias[i][0], &dias[i][1]);
        printf(" ==> %.2f\n", dias[i][0]-dias[i][1]);
    }     
        rec_total += dias[i][0];
        desp_total += dias[i][1];           
        saldo = rec_total - desp_total;
    printf("\nReceita total: %.2f\n", rec_total);
    printf("\nDespesas totais: %.2f\n", desp_total);
    printf("\nSaldo restante: %.2f\n", saldo);
}