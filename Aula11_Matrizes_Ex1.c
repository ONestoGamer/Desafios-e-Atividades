#include <stdio.h>
#include <stdlib.h>
#include <string.h>         
#include <locale.h>
#define TAM_MAX_LIN 5
#define TAM_MAX_COL 5

int lin, col;
float notas[TAM_MAX_LIN][TAM_MAX_COL], media;

int main() {
    setlocale(LC_ALL, "PORTUGUESE");
    //entrada de dados
    for (lin=0; lin<TAM_MAX_LIN; lin++)     //controle de linhas (alunos)
        for(col=0; col<TAM_MAX_COL; col++) { //controle de colunas (notas)
            printf("Entre com a nota %i do aluno %i: ", col+1, lin+1);
            scanf("%f", &notas[lin][col]);
        }
    //saída de dados
    for (lin=0; lin<TAM_MAX_LIN; lin++) {   //calculo da média
        media=0;
        for (col=0; col<TAM_MAX_COL; col++) 
            media+=notas[lin][col]; //soma das notas
        printf("\nA média do aluno %i foi de: %.2f\n", lin+1, (float)media/TAM_MAX_COL);
        
    }
}