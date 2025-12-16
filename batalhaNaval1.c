#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define AGUA 0
#define NAVIO 3

int main() {

    // Tabuleiro 10x10
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    // Inicializa todo o tabuleiro com 0 (água)
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // navios (tamanho fixo 3)
    int navioHorizontal[TAM_NAVIO] = {NAVIO, NAVIO, NAVIO};
    int navioVertical[TAM_NAVIO]   = {NAVIO, NAVIO, NAVIO};

    // Coordenadas iniciais dos navios (definidas no código)
    int linhaH = 2, colunaH = 1; // navio horizontal
    int linhaV = 5, colunaV = 6; // navio vertical

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

    // -------- Exibição do tabuleiro --------
    printf("Tabuleiro de Batalha Naval (0 = água | 3 = navio)\n\n");

    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
