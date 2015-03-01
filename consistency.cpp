#include "consistency.h"

/* isPossible
 *   Purpose:  Checks if it is possible to solve an incomplete board
 *   Arguments:  The board to check.
 *   Returns:  True if possible, false if impossible.
 */
bool isPossible(int board[][SIZE])
{
  return validRows(board) && validCols(board) && validBlocks(board);
}


/* validRows()
 *   Purpose:  Checks if the rows are valid; that is, that no row repeats
 *     a number.
 *   Arguments: The board to check.
 *   Returns: True if valid, false if not.
 */
bool validRows(int board[][SIZE])
{
  int i, j;
  bool vals[SIZE];
  for (i = 0; i < SIZE; i++) {
    for (j = 0; j < SIZE; j++) {
      vals[j] = false;
    }
    for (j = 0; j < SIZE; j++) {
      if (board[i][j] == SENTINEL) continue;
      if (vals[board[i][j] - 1]) {
	      return false;
      } else {
	      vals[board[i][j] - 1] = true;
      }
    }
  }
  return true;
}


/* validCols()
 *   Purpose:  Checks if the columns are valid; that is, that no column repeats
 *     a number.
 *   Arguments: The board to check.
 *   Returns: True if valid, false if not.
 */
bool validCols(int board[][SIZE])
{
  int i, j;
  bool vals[SIZE];
  for (j = 0; j < SIZE; j++) {
    for (i = 0; i < SIZE; i++) {
      vals[i] = false;
    }
    for (i = 0; i < SIZE; i++) {
      if (board[i][j] == SENTINEL) continue;
      if (vals[board[i][j] - 1]) {
      	return false;
      } else {
      	vals[board[i][j] - 1] = true;
      }
    }
  }
  return true;
}


/* validBlocks()
 *   Purpose:  Checks if the blocks are valid; that is, that no block repeats
 *     a number.  Note that each block should be of size BLOCK.
 *   Arguments: The board to check.
 *   Returns: True if valid, false if not.
 */
bool validBlocks(int board[][SIZE])
{
  int i, j, k, l, x, y;
  int num_blocks = SIZE / BLOCK;
  bool vals[SIZE];
  for (i = 0; i < num_blocks; i++) {
    for (j = 0; j < num_blocks; j++) {
      for (x = 0; x < SIZE; x++) {
      	vals[x] = false;
      }

      for (k = 0; k < BLOCK; k++) {
      	for (l = 0; l < BLOCK; l++) {
      	  x = (BLOCK * i) + k;
      	  y = (BLOCK * j) + l;
      	  if (board[x][y] == SENTINEL) continue;
      	  if (vals[board[x][y] - 1]) {
      	    return false;
      	  } else {
      	    vals[board[x][y] - 1] = true;
      	  }
      	}
      }
    }
  }
  return true;
}

