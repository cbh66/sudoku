#include <iostream>
#include "sudoku.h"
#include "solve.h"
using namespace std;


int uniqueNum(Guess board[][SIZE], int x, int y);
int rowOccurrences(Guess board[][SIZE], int num, int row);
int colOccurrences(Guess board[][SIZE], int num, int col);
int blockOccurrences(Guess board[][SIZE], int num, int blockX, int blockY);



void findUniqueNums(Guess board[][SIZE])
{
    int i, j, current;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (board[i][j].amt == 1) continue;
            current = uniqueNum(board, i, j);
            if (current != SENTINEL) {
                setNum(&board[i][j], current);
            }
        }
    }
}


/*  uniqueNum()
 *  Purpose: Determines whether the square at the given coordinates contains
 *           a possibility that is unique in its row, column, or block.
 *  Parameters: The board, the x (row) and y (column) coordinates of the square
 *           of interest.
 *  Returns: The number that is unique, if it exists.
 *           If no such number exists, SENTINEL is returned.
 */
int uniqueNum(Guess board[][SIZE], int x, int y)
{
    int i;
    for (i = 0; i < SIZE; i++) {
        if (board[x][y].possible[i]) {
            if (rowOccurrences(board, i + 1, x) == 1 ||
      	        colOccurrences(board, i + 1, y) == 1 ||
      	        blockOccurrences(board, i + 1, (x / BLOCK) * BLOCK,
			                     (y / BLOCK) * BLOCK) == 1) {
                return i + 1;
            }
        }
    }
    return SENTINEL;
}


/*  rowOccurences()
 *  Purpose: Determines how many times a number occurs as a possibility in a
 *           given row.
 *  Parameters: The board, the number to look for, the row to search in.
 *  Returns: An integer representing the number of squares that have this
 *           number as a possibility in the given row.  It will be greater
 *           than 0.
 */
int rowOccurrences(Guess board[][SIZE], int num, int row)
{
    int i, count = 0;
    for (i = 0; i < SIZE; i++) {
        if (board[row][i].possible[num - 1]) ++count;
    }
    return count;
}


/*  colOccurences()
 *  Purpose: Determines how many times a number occurs as a possibility in a
 *           given column.
 *  Parameters: The board, the number to look for, the column to search in.
 *  Returns: An integer representing the number of squares that have this
 *           number as a possibility in the given column.  It will be greater
 *           than 0.
 */
int colOccurrences(Guess board[][SIZE], int num, int col)
{
    int i, count = 0;
    for (i = 0; i < SIZE; i++) {
        if (board[i][col].possible[num - 1]) ++count;
    }
    return count;
}


/*  blockOccurences()
 *  Purpose: Determines how many times a number occurs as a possibility in a
 *           given block.
 *  Parameters: The board, the number to look for, the x (row) and y (column)
 *           coordinates of the upper-left corner of the block to search in.
 *  Returns: An integer representing the number of squares that have this
 *           number as a possibility in the given block.  It will be greater
 *           than 0.
 */
int blockOccurrences(Guess board[][SIZE], int num, int blockX, int blockY)
{
    int i, j, count = 0;
    for (i = blockX; i < blockX + BLOCK; ++i) {
        for (j = blockY; j < blockY + BLOCK; ++j) {
            if (board[i][j].possible[num - 1]) ++count;
        }
    }
    return count;
}
