#include "solve.h"
#include <iostream>
using namespace std;


void elimRepeats(Guess board[][SIZE]);
void eliminate(Guess board[][SIZE], int num, int x, int y);
int numCertain(Guess board[][SIZE]);

void elimAllRepeats(Guess board[][SIZE])
{
    unsigned before =  numCertain(board);
    unsigned after = 0;
    while (before != after) {
        elimRepeats(board);
        before = after;
        after = numCertain(board);
    }
}

/* elimRepeats
 *   Purpose: Modifies the given board to eliminate possibilites based on
 *     numbers already in a row, column, or block.
 *   Arguments:  A board of possibilities, passed by reference.
 *   Returns:  Nothing, but modifies the board passed as a parameter.
 */
void elimRepeats(Guess board[][SIZE])
{
    for (unsigned i = 0; i < SIZE; ++i) {
        for (unsigned j = 0; j < SIZE; ++j) {
            if (board[i][j].amt == 1) {
                unsigned k;
                for (k = 0; k < SIZE; k++) {
                  	if (board[i][j].possible[k]) break;
              	}
                eliminate(board, k + 1, i, j);
            }
        }
    }
}

/* eliminate()
 *   Purpose: Removes the given number from the list of possibilities
 *     for positions in the same row, column, or block.
 *   Arguments: The board to modify; the number to eliminate; the x and y
 *     coordinates of the location of the number.
 *   Returns: Nothing, but modifies the board parameter.
 */
void eliminate(Guess board[][SIZE], int num, int x, int y)
{
    /*  Hold the upper-left coordinates of the square's block
     */
    int row = (x / BLOCK) * BLOCK;
    int col = (y / BLOCK) * BLOCK;
    /*  Goes through the row and column simultaneously
     */
    for (int i = 0; i < (int) SIZE; ++i) {
        if (i != x) {
            if (board[i][y].possible[num - 1]) board[i][y].amt--;
            board[i][y].possible[num - 1] = false;
        }
        if (i != y) {
            if (board[x][i].possible[num - 1]) board[x][i].amt--;
            board[x][i].possible[num - 1] = false;
        }
    }

    for (int i = row; (unsigned) i < row + BLOCK; ++i) {
        for (int j = col; (unsigned) j < col + BLOCK; ++j) {
            if (i != x && j != y) {
                if (board[i][j].possible[num - 1]) board[i][j].amt--;
                board[i][j].possible[num - 1] = false;
            }
        }
    }
}

