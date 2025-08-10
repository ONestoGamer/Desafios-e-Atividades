#include <stdio.h>
#include <stdlib.h>
#include <string.h>         
#include <locale.h>

struct registroAluno {     // Definição da estrutura registroAluno
    char nome[50];
    char endereco[100];
    int id;
    float nota[3];  // Array para armazenar notas, pode ser ajustado conforme necessário
};
struct registroAluno aluno[10];    // Declaração de uma variável do tipo registroAluno
float media;

int main() {
    setlocale(LC_ALL, "PORTUGUESE");
    printf("Cadastro de Alunos\n\n");
    printf("----------------------\n");
    for (int i=0; i<4; i++) {
        printf("Entre com as informaçõeos de ID, Nome, Endereço e as notas do Aluno:\n");
        scanf("%i  %[^\n]  %[^\n] %f %f %f", &aluno[i].id, aluno[i].nome, aluno[i].endereco, &aluno[i].nota[0], &aluno[i].nota[1], &aluno[i].nota[2]);  // Lê as informações do aluno
    }
    media = (aluno[0].nota[0] + aluno[0].nota[1] + aluno[0].nota[2]) / 3; // Calcula a média das notas do aluno
    for (int i=0; i<4; i++) {
        printf("\nAluno: %s - ID: %i Endereço: %s \n", aluno[i].nome, aluno[i].id, aluno[i].endereco, aluno[i].nota[0], aluno[i].nota[1], aluno[i].nota[2]);  // Exibe as informações do aluno
     if (media >= 7.0) {
            printf("Aluno Aprovado!\n");
    }   else {
            printf("Aluno Reprovado!\n");
    }
    }

    
    
}