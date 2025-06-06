#include <stdio.h>
#include "board.h"

char board[3][3];

void resetBoard() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';
}

void printBoard() {
    printf("  0   1   2\n");
    for (int i = 0; i < 3; i++) {
        printf("%d", i);
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf(" ---+---+---\n");
    }
}
