#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

    #define TAM 10      // tamanho do tabuleiro
    #define NAVIO 3     // valor que representa parte do navio
    #define AGUA 0      // valor que representa água
    #define TAM_NAVIO 3 // tamanho fixo dos navios

    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.
    
int main() {
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
    return 0;
}

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    #define TAM 10        // Tamanho fixo do tabuleiro
    #define NAVIO 3       // Valor que representa parte do navio
    #define AGUA 0        // Valor que representa água
    #define TAM_NAVIO 3   // Tamanho fixo de cada navio

int main() {
    int tabuleiro[TAM][TAM];
    int i, j;

    // ------------------------------------------------
    // Inicializa o tabuleiro com 0 (água)
    // ------------------------------------------------

    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // ------------------------------------------------
    // Coordenadas iniciais dos navios
    // ------------------------------------------------

    int linhaH = 1, colunaH = 2; // navio horizontal
    int linhaV = 5, colunaV = 6; // navio vertical
    int linhaD1 = 2, colunaD1 = 2; // navio diagonal ↘ (linha e coluna aumentam)
    int linhaD2 = 7, colunaD2 = 2; // navio diagonal ↙ (linha aumenta, coluna diminui)

    // ------------------------------------------------
    // Posiciona navio horizontal (para a direita)
    // ------------------------------------------------

    if (colunaH + TAM_NAVIO <= TAM) {
        for (j = 0; j < TAM_NAVIO; j++) {
            if (tabuleiro[linhaH][colunaH + j] == NAVIO) {
                printf("Erro: sobreposição detectada (horizontal)!\n");
                return 1;
            }
            tabuleiro[linhaH][colunaH + j] = NAVIO;
        }
    } else {
        printf("Erro: navio horizontal fora do tabuleiro!\n");
        return 1;
    }

    // ------------------------------------------------
    // Posiciona navio vertical (para baixo)
    // ------------------------------------------------

    if (linhaV + TAM_NAVIO <= TAM) {
        for (i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaV + i][colunaV] == NAVIO) {
                printf("Erro: sobreposição detectada (vertical)!\n");
                return 1;
            }
            tabuleiro[linhaV + i][colunaV] = NAVIO;
        }
    } else {
        printf("Erro: navio vertical fora do tabuleiro!\n");
        return 1;
    }

    // ------------------------------------------------
    // Posiciona navio diagonal ↘ (linha e coluna aumentam)
    // ------------------------------------------------

    if (linhaD1 + TAM_NAVIO <= TAM && colunaD1 + TAM_NAVIO <= TAM) {
        for (i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaD1 + i][colunaD1 + i] == NAVIO) {
                printf("Erro: sobreposição detectada (diagonal ↘)!\n");
                return 1;
            }
            tabuleiro[linhaD1 + i][colunaD1 + i] = NAVIO;
        }
    } else {
        printf("Erro: navio diagonal ↘ fora do tabuleiro!\n");
        return 1;
    }

    // ------------------------------------------------
    // Posiciona navio diagonal ↙ (linha aumenta, coluna diminui)
    // ------------------------------------------------
    if (linhaD2 + TAM_NAVIO <= TAM && colunaD2 - (TAM_NAVIO - 1) >= 0) {
        for (i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaD2 + i][colunaD2 - i] == NAVIO) {
                printf("Erro: sobreposição detectada (diagonal ↙)!\n");
                return 1;
            }
            tabuleiro[linhaD2 + i][colunaD2 - i] = NAVIO;
        }
    } else {
        printf("Erro: navio diagonal ↙ fora do tabuleiro!\n");
        return 1;
    }

    // ------------------------------------------------
    // Exibe o tabuleiro completo
    // ------------------------------------------------
    printf("\n=== Tabuleiro Batalha Naval ===\n\n");

    // Cabeçalho com índices das colunas
    printf("   ");
    for (j = 0; j < TAM; j++) {
        printf("%2d ", j);
    }
    printf("\n");

    // Linhas do tabuleiro
    for (i = 0; i < TAM; i++) {
        printf("%2d ", i); // índice da linha
        for (j = 0; j < TAM; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    return 0;
}

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.
   
    #define TAM 10
    #define H 5  // tamanho das matrizes de habilidade (5x5)

// Função para inicializar o tabuleiro com 0 (água)
void inicializarTabuleiro(int tab[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tab[i][j] = 0;
        }
    }
}

// Função para imprimir o tabuleiro formatado
void exibirTabuleiro(int tab[TAM][TAM]) {
    printf("\nTABULEIRO ATUAL:\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tab[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Posiciona os quatro navios: dois retos e dois diagonais
void posicionarNavios(int tab[TAM][TAM]) {
    int i;

    // Navio 1 (horizontal)
    int linha1 = 2, col1 = 1;
    for (i = 0; i < 3; i++) tab[linha1][col1 + i] = 3;

    // Navio 2 (vertical)
    int linha2 = 5, col2 = 6;
    for (i = 0; i < 3; i++) tab[linha2 + i][col2] = 3;

    // Navio 3 (diagonal principal)
    int linha3 = 1, col3 = 7;
    for (i = 0; i < 3; i++) tab[linha3 + i][col3 + i] = 3;

    // Navio 4 (diagonal secundária)
    int linha4 = 7, col4 = 2;
    for (i = 0; i < 3; i++) tab[linha4 - i][col4 + i] = 3;
}

// Cria a matriz de habilidade em forma de cone
void criarCone(int cone[H][H]) {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {
            // Quanto mais "embaixo" da matriz, mais larga a área
            if (j >= (H / 2 - i) && j <= (H / 2 + i))
                cone[i][j] = 1;
            else
                cone[i][j] = 0;
        }
    }
}

// Cria a matriz de habilidade em forma de cruz
void criarCruz(int cruz[H][H]) {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {
            if (i == H / 2 || j == H / 2)
                cruz[i][j] = 1;
            else
                cruz[i][j] = 0;
        }
    }
}

// Cria a matriz de habilidade em forma de octaedro (losango)
void criarOctaedro(int oct[H][H]) {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {
            // Losango: diferença entre linha e coluna controlada
            if (abs(i - H / 2) + abs(j - H / 2) <= H / 2)
                oct[i][j] = 1;
            else
                oct[i][j] = 0;
        }
    }
}

// Sobrepõe uma habilidade ao tabuleiro, centrando-a no ponto (x, y)
void aplicarHabilidade(int tab[TAM][TAM], int hab[H][H],
                       int x, int y) {
    int offset = H / 2; // metade da matriz da habilidade
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {
            // Verifica se está dentro dos limites do tabuleiro
            int linha = x + (i - offset);
            int col = y + (j - offset);

            if (linha >= 0 && linha < TAM &&
                col >= 0 && col < TAM) {
                // Se a habilidade atinge (valor 1), marca com 5
                if (hab[i][j] == 1 && tab[linha][col] == 0)
                    tab[linha][col] = 5;
            }
        }
    }
}

int main() {
    int tabuleiro[TAM][TAM];
    int cone[H][H], cruz[H][H], octaedro[H][H];

    inicializarTabuleiro(tabuleiro);
    posicionarNavios(tabuleiro);

    criarCone(cone);
    criarCruz(cruz);
    criarOctaedro(octaedro);

    // Define os pontos de origem das habilidades
    aplicarHabilidade(tabuleiro, cone, 3, 3);
    aplicarHabilidade(tabuleiro, cruz, 6, 5);
    aplicarHabilidade(tabuleiro, octaedro, 7, 8);

    exibirTabuleiro(tabuleiro);

    return 0;
}
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

