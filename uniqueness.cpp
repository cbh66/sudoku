#include <iostream>
#include "sudoku.h"
#include "solve.h"
using namespace std;


int uniqueNum(Guess board[][SIZE], int x, int y);
int rowOccurrences(Guess board[][SIZE], int num, int row);
int colOccurrences(Guess board[][SIZE], int num, int col);
int blockOccurrences(Guess board[][SIZE], int num, int blockX, int blockY);


/*  findUniqueNums()
 *  Purpose: For every square, checks if it has a possibility that is unique
 *           in its row, column, or block.  If so, that possibility becomes
 *           a certainty.
 *  Parameters: The array of guesses, which will be modified.
 *  Returns: Nothing.
 *  Notes:   Once it finds such a number, this function does not continue
 *           to eliminate that number as a possibility from other rows and
 *           columns.  That must be done separately.
 */
void findUniqueNums(Guess board[][SIZE])
{
  int i, j, k, current;
  for (i = 0; i < SIZE; i++) {
    for (j = 0; j < SIZE; j++) {
      if (board[i][j].amt == 1) continue;
      current = uniqueNum(board, i, j);
      if (current) {
      	board[i][j].amt = 1;
        for (k = 0; k < SIZE; ++k) {
          if (k == current - 1) {
            board[i][j].possible[k] = true;
          } else {
            board[i][j].possible[k] = false;
          }
        }
      }
    }
  }

}

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
  return 0;
}


int rowOccurrences(Guess board[][SIZE], int num, int row)
{
  int i, count = 0;
  for (i = 0; i < SIZE; i++) {
    if (board[row][i].possible[num - 1]) count++;
  }
  return count;
}


int colOccurrences(Guess board[][SIZE], int num, int col)
{
  int i, count = 0;
  for (i = 0; i < SIZE; i++) {
    if (board[i][col].possible[num - 1]) count++;
  }
  return count;
}


int blockOccurrences(Guess board[][SIZE], int num, int blockX, int blockY)
{
  int i, j, count = 0;
  for (i = blockX; i < blockX + BLOCK; i++) {
    for (j = blockY; j < blockY + BLOCK; j++) {
      if (board[i][j].possible[num - 1]) count++;
    }
  }
  return count;
}


