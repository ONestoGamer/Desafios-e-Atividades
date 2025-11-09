/* Objetivos:
Aplicar estruturas de repetição simples (for, while, do-while) para simular movimentos básicos de peças de xadrez (Torre, Bispo, Rainha).
Aplicar loops aninhados para simular o movimento complexo em "L" do Cavalo no tabuleiro de xadrez.
Aplicar recursividade e loops complexos com múltiplas condições para simular movimentos avançados das peças de xadrez.
Vamos dar os primeiros passos, utilizando as estruturas de repetição for, while e do-while 
para controlar os movimentos lineares da Torre, Bispo e Rainha. 
em seguida implementar loops aninhados para orquestrar o intrigante movimento em "L" do Cavalo. 
Por fim, atingir o auge da jornada, dominando a recursividade para otimizar os movimentos
e utilizando loops complexos com múltiplas
variáveis e condições para refinar seus códigos, demonstrando maestria na manipulação de estruturas de repetição. */ 

#include <stdio.h>
#include <stdlib.h>

#define TABULEIRO 8   // tamanho do tabuleiro
#define PASSOS 2      // número de casas para recursão

// ------------------ TORRE ------------------
void torre_recursiva(int passos) {
    if (passos == 0) return; // condição de parada

    printf("Cima\n");
    torre_recursiva(passos - 1);

    printf("Baixo\n");
    torre_recursiva(passos - 1);

    printf("Esquerda\n");
    torre_recursiva(passos - 1);

    printf("Direita\n");
    torre_recursiva(passos - 1);
}

// ------------------ BISPO ------------------
void bispo_recursivo(int passos) {
    if (passos == 0) return; // condição de parada

    // loops aninhados: vertical (i) e horizontal (j)
    for (int i = 1; i <= passos; i++) {
        for (int j = 1; j <= passos; j++) {
            if (i == j) {
                printf("Diagonal Cima-Direita\n");
            } else if (i + j == passos + 1) {
                printf("Diagonal Cima-Esquerda\n");
            }
        }
    }

    bispo_recursivo(passos - 1); // chamada recursiva
}

// ------------------ RAINHA ------------------
void rainha_recursiva(int passos) {
    if (passos == 0) return;

    // movimentos da Torre
    printf("Cima\n");
    rainha_recursiva(passos - 1);

    printf("Baixo\n");
    rainha_recursiva(passos - 1);

    printf("Esquerda\n");
    rainha_recursiva(passos - 1);

    printf("Direita\n");
    rainha_recursiva(passos - 1);

    // movimentos do Bispo
    printf("Diagonal Cima-Direita\n");
    rainha_recursiva(passos - 1);

    printf("Diagonal Cima-Esquerda\n");
    rainha_recursiva(passos - 1);

    printf("Diagonal Baixo-Direita\n");
    rainha_recursiva(passos - 1);

    printf("Diagonal Baixo-Esquerda\n");
    rainha_recursiva(passos - 1);
}

// ------------------ CAVALO ------------------
void cavalo_movimentos() {
    // loops complexos para simular "L"
    for (int i = 1; i <= TABULEIRO; i++) {
        for (int j = 1; j <= TABULEIRO; j++) {
            // movimento em L: duas casas para cima e uma para a direita
            if (i - 2 >= 1 && j + 1 <= TABULEIRO) {
                printf("Cima\n");
                printf("Cima\n");
                printf("Direita\n");
                break; // sai do loop interno após encontrar movimento válido
            } else {
                continue; // ignora posições inválidas
            }
        }
    }
}

// ------------------ MAIN ------------------
int main() {
    printf("Movimentos da Torre:\n");
    torre_recursiva(PASSOS);

    printf("\nMovimentos do Bispo:\n");
    bispo_recursivo(PASSOS);

    printf("\nMovimentos da Rainha:\n");
    rainha_recursiva(PASSOS);

    printf("\nMovimentos do Cavalo:\n");
    cavalo_movimentos();

    return 0;
}