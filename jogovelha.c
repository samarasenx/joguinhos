#include <stdio.h>

#define TAMANHO 3

void imprimeVelha(char m[TAMANHO][TAMANHO]);
int acabou(char m[TAMANHO][TAMANHO]);

int caminho = 1; // 1 para 'X', 2 para 'O'

int main() {
    char matriz[TAMANHO][TAMANHO];

    // inicializa a matriz com espaços
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            matriz[i][j] = ' ';
        }
    }

    int linha, coluna;
    int estadoJogo = 0;

    while ((estadoJogo = acabou(matriz)) == 0) {
        imprimeVelha(matriz);
        printf("Vez do %c. Digite linha e coluna (0 a 2): ", (caminho == 1 ? 'X' : 'O'));
        scanf("%d %d", &linha, &coluna);

        // verifica se a posição é válida
        if (linha >= 0 && linha < TAMANHO && coluna >= 0 && coluna < TAMANHO) {
            if (matriz[linha][coluna] == ' ') {
                matriz[linha][coluna] = (caminho == 1) ? 'X' : 'O';
                caminho = (caminho == 1) ? 2 : 1;
            } else {
                printf("Posição ocupada. Tente novamente.\n");
            }
        } else {
            printf("Coordenadas inválidas. Tente novamente.\n");
        }
    }

    imprimeVelha(matriz);

    if (estadoJogo == 1) {
        printf("Jogador %c venceu!\n", (caminho == 2) ? 'X' : 'O'); // Inverte pois o jogador atual perdeu a vez
    } else if (estadoJogo == -1) {
        printf("Deu Velha :(\n");
    }

    return 0;
}

void imprimeVelha(char m[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf(" %c ", m[i][j]);
            if (j < TAMANHO - 1) printf("|");
        }
        printf("\n");
        if (i < TAMANHO - 1) printf("---+---+---\n");
    }
    printf("\n");
}

int acabou(char m[TAMANHO][TAMANHO]) {
    // verifica linhas e colunas
    for (int i = 0; i < TAMANHO; i++) {
        // linhas
        if (m[i][0] == m[i][1] && m[i][1] == m[i][2] && m[i][0] != ' ')
            return 1;

        // colunas
        if (m[0][i] == m[1][i] && m[1][i] == m[2][i] && m[0][i] != ' ')
            return 1;
    }

    // diagonal principal
    if (m[0][0] == m[1][1] && m[1][1] == m[2][2] && m[0][0] != ' ')
        return 1;

    // diagonal secundária
    if (m[0][2] == m[1][1] && m[1][1] == m[2][0] && m[0][2] != ' ')
        return 1;

    // verifica se há espaços vazios
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            if (m[i][j] == ' ') 
                return 0; // ainda há jogadas
        }
    }

    return -1; // empate
}
