/* Esqueleto básico de um jogo de Xadrez para atividade projeto do módulo Desenvolva um Game com Suporte da Ferramenta ChatGPT */

#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

// Definição dos tipos de peças
#define EMPTY 0
#define RED 1
#define BLACK 2
#define RED_KING 3
#define BLACK_KING 4

// Estrutura para representar uma peça no tabuleiro
typedef struct {
    int type;
} Piece;

// Função para inicializar o tabuleiro com peças
void initializeBoard(Piece board[BOARD_SIZE][BOARD_SIZE]) {
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if ((row + col) % 2 == 1) {
                if (row < 3)
                    board[row][col].type = BLACK;
                else if (row > 4)
                    board[row][col].type = RED;
                else
                    board[row][col].type = EMPTY;
            } else {
                board[row][col].type = EMPTY;
            }
        }
    }
}

// Função para imprimir o tabuleiro
void printBoard(Piece board[BOARD_SIZE][BOARD_SIZE]) {
    printf("   A B C D E F G H\n");
    for (int row = 0; row < BOARD_SIZE; row++) {
        printf("%d  ", row + 1);
        for (int col = 0; col < BOARD_SIZE; col++) {
            char pieceChar;
            switch (board[row][col].type) {
                case EMPTY:
                    pieceChar = ' ';
                    break;
                case RED:
                    pieceChar = 'r';
                    break;
                case BLACK:
                    pieceChar = 'b';
                    break;
                case RED_KING:
                    pieceChar = 'R';
                    break;
                case BLACK_KING:
                    pieceChar = 'B';
                    break;
            }
            printf("%c ", pieceChar);
        }
        printf("%d\n", row + 1);
    }
    printf("   A B C D E F G H\n");
}

int main() {
    Piece board[BOARD_SIZE][BOARD_SIZE];
    initializeBoard(board);

    int currentPlayer = RED;  // Começa com as peças vermelhas
    int gameRunning = 1;

    while (gameRunning) {
        printf("Jogador %s, é a sua vez.\n", (currentPlayer == RED) ? "Vermelho" : "Preto");
        printBoard(board);

        // Aqui você pode implementar a lógica do jogo, como mover peças e verificar vitória

        // Defina as condições para encerrar o jogo
        // Por exemplo: gameRunning = 0;

        // Alternar o jogador atual
        currentPlayer = (currentPlayer == RED) ? BLACK : RED;
    }

    // Imprima a mensagem de vitória
    printf("Jogador %s venceu!\n", (currentPlayer == RED) ? "Preto" : "Vermelho");

    return 0;
}