#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

    #define TAM 10      // tamanho do tabuleiro
    #define NAVIO 3     // valor que representa parte do navio
    #define AGUA 0      // valor que representa água
    #define TAM_NAVIO 3 // tamanho fixo dos navios

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.
    
    int tabuleiro[TAM][TAM]; // matriz do tabuleiro
    int i, j;

    // ---------------------------
    // Inicializa o tabuleiro com água (0)
    // ---------------------------
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // ---------------------------
    // Coordenadas iniciais dos navios
    // ---------------------------
    int linhaH = 2, colunaH = 4; // navio horizontal começa em (2,4)
    int linhaV = 5, colunaV = 7; // navio vertical começa em (5,7)

    // ---------------------------
    // Posiciona navio horizontal
    // ---------------------------
    if (colunaH + TAM_NAVIO <= TAM) { // verifica limite do tabuleiro
        for (j = 0; j < TAM_NAVIO; j++) {
            tabuleiro[linhaH][colunaH + j] = NAVIO;
        }
    } else {
        printf("Erro: Navio horizontal fora do tabuleiro!\n");
        return 1;
    }

    // ---------------------------
    // Posiciona navio vertical
    // ---------------------------
    if (linhaV + TAM_NAVIO <= TAM) { // verifica limite do tabuleiro
        for (i = 0; i < TAM_NAVIO; i++) {
            // valida se não há sobreposição
            if (tabuleiro[linhaV + i][colunaV] == NAVIO) {
                printf("Erro: Navios se sobrepõem!\n");
                return 1;
            }
            tabuleiro[linhaV + i][colunaV] = NAVIO;
        }
    } else {
        printf("Erro: Navio vertical fora do tabuleiro!\n");
        return 1;
    }

    // ---------------------------
    // Exibe o tabuleiro
    // ---------------------------
    printf("\n=== Tabuleiro Batalha Naval ===\n\n");
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
