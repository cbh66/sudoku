#include <iostream>
#include "sudoku.h"
using namespace std;

void setNum(Guess *square, unsigned num)
{
    for (unsigned i = 0; i < SIZE; ++i) {
        square->possible[i] = ((int) num == SENTINEL);
    }
    square->amt = ((int) num == SENTINEL) ? SIZE : 1;
    if ((int) num != SENTINEL) {
        square->possible[num - 1] = true;
    }
}


int numGuesses(Guess board[][SIZE])
{
    unsigned count = 0;
    for (unsigned i = 0; i < SIZE; ++i) {
        for (unsigned j = 0; j < SIZE; ++j) {
            if (board[i][j].amt != 1) {
                count += board[i][j].amt;
            }
        }
    }
    return count;
}


int numCertain(Guess board[][SIZE])
{
    unsigned i, j, count = 0;
    for (i = 0; i < SIZE; ++i) {
        for (j = 0; j < SIZE; ++j) {
            count += (board[i][j].amt == 1);
        }
    }
    return count;
}


void printBoard(Guess board[SIZE][SIZE])
{
    for (unsigned row = 0; row < SIZE; ++row) {
        for (unsigned col = 0; col < SIZE; ++col) {
            cout << "--------";
        }
        cout << "---" << endl;
        if (row != 0 && row % BLOCK == 0) {
            for (unsigned col = 0; col < SIZE; ++col) {
                cout << "--------";
            }
            cout << "---" << endl;
        }
        for (unsigned guess_start = 0; guess_start < SIZE;
             guess_start += BLOCK) {
            for (unsigned col = 0; col < SIZE; ++col) {
                if (col != 0 && col % BLOCK == 0) {
                    cout << "|";
                }
                cout << "| ";
                for (unsigned guess = guess_start; guess < guess_start + BLOCK;
                     ++guess) {
                    if (board[row][col].possible[guess]) {
                        cout << guess + 1 << " ";
                    } else {
                        cout << "  ";
                    }
                }
            }
            cout << "|" << endl;
        }
    }
    for (unsigned col = 0; col < SIZE; ++col) {
        cout << "--------";
    }
    cout << "---" << endl;
}
