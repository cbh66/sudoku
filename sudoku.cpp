#include "sudoku.h"


void setNum(Guess *square, int num)
{
    int i;
    for (i = 0; i < SIZE; ++i) {
        square->possible[i] = (num == SENTINEL);
    }
    square->amt = (num == SENTINEL) ? SIZE : 1;
    if (num != SENTINEL) {
        square->contents = num;
        square->possible[num - 1] = true;
    }
}


int numGuesses(Guess board[][SIZE])
{
    int i, j, count = 0;
    for (i = 0; i < SIZE; ++i) {
        for (j = 0; j < SIZE; ++j) {
            if (board[i][j].amt != 1) {
                count += board[i][j].amt;
            }
        }
    }
    return count;
}


int numCertain(Guess board[][SIZE])
{
    int i, j, count = 0;
    for (i = 0; i < SIZE; ++i) {
        for (j = 0; j < SIZE; ++j) {
            count += (board[i][j].amt == 1);
        }
    }
    return count;
}
