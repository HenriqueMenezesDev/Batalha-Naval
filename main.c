#include <stdio.h>
#include <string.h>

#define TAMANHO 10
#define NAVIO 3
#define HABILIDADE 5
#define AGUA 0

// Função para inicializar o tabuleiro com água
void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Função para posicionar navios
void posicionarNavios(int tabuleiro[TAMANHO][TAMANHO]) {
    // Dois navios horizontais/verticais
    tabuleiro[1][1] = tabuleiro[1][2] = tabuleiro[1][3] = NAVIO;
    tabuleiro[4][5] = tabuleiro[5][5] = tabuleiro[6][5] = NAVIO;
    
    // Dois navios diagonais
    tabuleiro[2][2] = tabuleiro[3][3] = tabuleiro[4][4] = NAVIO;
    tabuleiro[7][2] = tabuleiro[6][3] = tabuleiro[5][4] = NAVIO;
}

// Aplica a habilidade ao tabuleiro
void aplicarHabilidade(int tabuleiro[TAMANHO][TAMANHO], int origemX, int origemY, char tipo) {
    int efeito[5][5] = {0}; // Matriz da habilidade

    if (tipo == 'C') { // Cruz
        for (int i = 0; i < 5; i++) {
            efeito[2][i] = efeito[i][2] = 1;
        }
    } else if (tipo == 'O') { // Octaedro
        efeito[0][2] = efeito[1][1] = efeito[1][3] =
        efeito[2][0] = efeito[2][2] = efeito[2][4] =
        efeito[3][1] = efeito[3][3] = efeito[4][2] = 1;
    } else if (tipo == 'N') { // Cone
        efeito[0][2] = efeito[1][1] = efeito[1][3] =
        efeito[2][0] = efeito[2][1] = efeito[2][2] = efeito[2][3] = efeito[2][4] = 1;
    }

    // Aplicar a matriz de efeito ao tabuleiro
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int x = origemX + i - 2;
            int y = origemY + j - 2;
            if (x >= 0 && x < TAMANHO && y >= 0 && y < TAMANHO && efeito[i][j] == 1) {
                tabuleiro[x][y] = HABILIDADE;
            }
        }
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            if (tabuleiro[i][j] == AGUA) printf(". ");
            else if (tabuleiro[i][j] == NAVIO) printf("N ");
            else if (tabuleiro[i][j] == HABILIDADE) printf("* ");
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    inicializarTabuleiro(tabuleiro);
    posicionarNavios(tabuleiro);

    // Aplicando habilidades em diferentes pontos
    aplicarHabilidade(tabuleiro, 2, 2, 'C'); // Cruz
    aplicarHabilidade(tabuleiro, 6, 6, 'O'); // Octaedro
    aplicarHabilidade(tabuleiro, 4, 7, 'N'); // Cone
    
    // Exibir tabuleiro final
    exibirTabuleiro(tabuleiro);
    return 0;
}
