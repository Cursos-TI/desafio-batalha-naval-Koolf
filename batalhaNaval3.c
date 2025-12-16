#include <stdio.h>
#include <stdlib.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define TAM_HAB 5

#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5

int main() {

    // ================= TABULEIRO =================
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    // Inicializa o tabuleiro com água
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // ================= NAVIOS =================
    // Navio horizontal
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[2][1 + i] = NAVIO;
    }

    // Navio vertical
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[5 + i][6] = NAVIO;
    }

    // ================= MATRIZES DE HABILIDADE =================
    int cone[TAM_HAB][TAM_HAB];
    int cruz[TAM_HAB][TAM_HAB];
    int octaedro[TAM_HAB][TAM_HAB];

    int centro = TAM_HAB / 2;

    // ---------- Construção do CONE ----------
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (i >= centro && j >= centro - (i - centro) && j <= centro + (i - centro)) {
                cone[i][j] = 1;
            } else {
                cone[i][j] = 0;
            }
        }
    }

    // ---------- Construção da CRUZ ----------
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (i == centro || j == centro) {
                cruz[i][j] = 1;
            } else {
                cruz[i][j] = 0;
            }
        }
    }

    // ---------- Construção do OCTAEDRO ----------
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (abs(i - centro) + abs(j - centro) <= centro) {
                octaedro[i][j] = 1;
            } else {
                octaedro[i][j] = 0;
            }
        }
    }

    // ================= SOBREPOSIÇÃO DAS HABILIDADES =================
    // Pontos de origem no tabuleiro
    int origemConeLinha = 4, origemConeColuna = 2;
    int origemCruzLinha = 6, origemCruzColuna = 6;
    int origemOctLinha  = 3, origemOctCol  = 7;

    // Função de sobreposição (manual)
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {

            int l, c;

            // Cone
            if (cone[i][j] == 1) {
                l = origemConeLinha + (i - centro);
                c = origemConeColuna + (j - centro);
                if (l >= 0 && l < TAM_TABULEIRO && c >= 0 && c < TAM_TABULEIRO && tabuleiro[l][c] == AGUA) {
                    tabuleiro[l][c] = HABILIDADE;
                }
            }

            // Cruz
            if (cruz[i][j] == 1) {
                l = origemCruzLinha + (i - centro);
                c = origemCruzColuna + (j - centro);
                if (l >= 0 && l < TAM_TABULEIRO && c >= 0 && c < TAM_TABULEIRO && tabuleiro[l][c] == AGUA) {
                    tabuleiro[l][c] = HABILIDADE;
                }
            }

            // Octaedro
            if (octaedro[i][j] == 1) {
                l = origemOctLinha + (i - centro);
                c = origemOctCol + (j - centro);
                if (l >= 0 && l < TAM_TABULEIRO && c >= 0 && c < TAM_TABULEIRO && tabuleiro[l][c] == AGUA) {
                    tabuleiro[l][c] = HABILIDADE;
                }
            }
        }
    }

    // ================= EXIBIÇÃO =================
    printf("TABULEIRO FINAL\n");
    printf("0 = Água | 3 = Navio | 5 = Habilidade\n\n");

    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}