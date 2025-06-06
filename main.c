#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include "board.h"
#include "game.h"

int main() {
    int row, col;
    char buffer[100];
    char currentPlayer = 'X';
    resetBoard();

    while (1) {
        printBoard();
        printf("Jucatorul %c, introdu o pozitie (ex: 12 pentru rand 1, coloana 2): ", currentPlayer);

        if (!fgets(buffer, sizeof(buffer), stdin)) {
            printf("Eroare la citire. Încearcă din nou.\n");
            continue;
        }

        buffer[strcspn(buffer, "\n")] = 0; 
        if (strlen(buffer) != 2 || buffer[0] < '0' || buffer[0] > '2' || buffer[1] < '0' || buffer[1] > '2') {
            printf("Input invalid. Scrie doua cifre între 00 și 22.\n");
            continue;
        }

        row = buffer[0] - '0';
        col = buffer[1] - '0';

        if (board[row][col] != ' ') {
            printf("Poziția este deja ocupată. Încearcă altă mutare.\n");
            continue;
        }

        board[row][col] = currentPlayer;

        if (checkWin(currentPlayer)) {
            printBoard();
            printf("Jucatorul %c a castigat!\n", currentPlayer);
            break;
        } else if (isDraw()) {
            printBoard();
            printf("Remiza!\n");
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
