#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define AGUA 0
#define NAVIO 3

int main() {

    // Declaração do tabuleiro 10x10
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    // Inicializa todo o tabuleiro com 0 (água)
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Vetores que representam os navios (tamanho fixo 3)
    int navioHorizontal[TAM_NAVIO] = {NAVIO, NAVIO, NAVIO};
    int navioVertical[TAM_NAVIO]   = {NAVIO, NAVIO, NAVIO};
    int navioDiagonal1[TAM_NAVIO]  = {NAVIO, NAVIO, NAVIO}; // Diagonal principal
    int navioDiagonal2[TAM_NAVIO]  = {NAVIO, NAVIO, NAVIO}; // Diagonal inversa

    // Coordenadas iniciais dos navios (definidas no código)
    int linhaH = 2, colunaH = 1; // navio horizontal
    int linhaV = 5, colunaV = 6; // navio vertical
    int linhaD1 = 0, colunaD1 = 0; // navio diagonal 1 (i, i)
    int linhaD2 = 0, colunaD2 = 9; // navio diagonal 2 (i, 9-i)

    // -------- Posicionamento do navio horizontal --------
    if (colunaH + TAM_NAVIO <= TAM_TABULEIRO) {
        int sobreposicao = 0;

        // Verifica se há sobreposição
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaH][colunaH + i] != AGUA) {
                sobreposicao = 1;
            }
        }

        // Posiciona o navio se não houver sobreposição
        if (!sobreposicao) {
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaH][colunaH + i] = navioHorizontal[i];
            }
        }
    }

    // -------- Posicionamento do navio vertical --------
    if (linhaV + TAM_NAVIO <= TAM_TABULEIRO) {
        int sobreposicao = 0;

        // Verifica se há sobreposição
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaV + i][colunaV] != AGUA) {
                sobreposicao = 1;
            }
        }

        // Posiciona o navio se não houver sobreposição
        if (!sobreposicao) {
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaV + i][colunaV] = navioVertical[i];
            }
        }
    }

    // -------- Posicionamento do navio diagonal principal (i, i) --------
    if (linhaD1 + TAM_NAVIO <= TAM_TABULEIRO && colunaD1 + TAM_NAVIO <= TAM_TABULEIRO) {
        int sobreposicao = 0;

        // Verifica se há sobreposição na diagonal principal
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaD1 + i][colunaD1 + i] != AGUA) {
                sobreposicao = 1;
            }
        }

        // Posiciona o navio se não houver sobreposição
        if (!sobreposicao) {
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaD1 + i][colunaD1 + i] = navioDiagonal1[i];
            }
        }
    }

    // -------- Posicionamento do navio diagonal inversa (i, 9-i) --------
    if (linhaD2 + TAM_NAVIO <= TAM_TABULEIRO && colunaD2 - TAM_NAVIO >= -1) {
        int sobreposicao = 0;

        // Verifica se há sobreposição na diagonal inversa
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaD2 + i][colunaD2 - i] != AGUA) {
                sobreposicao = 1;
            }
        }

        // Posiciona o navio se não houver sobreposição
        if (!sobreposicao) {
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaD2 + i][colunaD2 - i] = navioDiagonal2[i];
            }
        }
    }

    // -------- Exibição do tabuleiro --------
    printf("Tabuleiro de Batalha Naval (0 = água | 3 = navio)\n\n");

    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%2d ", tabuleiro[i][j]); // Alinhamento para facilitar a visualização
        }
        printf("\n");
    }

    return 0;
}