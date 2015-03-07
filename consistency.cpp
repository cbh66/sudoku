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
    bool vals[SIZE];
    for (unsigned row = 0; row < SIZE; ++row) {
        for (unsigned i = 0; i < SIZE; ++i) {
            vals[i] = false;
        }
        for (unsigned col = 0; col < SIZE; ++col) {
            if (board[row][col] == SENTINEL) continue;
            if (vals[board[row][col] - 1]) {
                return false;
            } else {
                vals[board[row][col] - 1] = true;
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
    bool vals[SIZE];
    for (unsigned col = 0; col < SIZE; col++) {
        for (unsigned i = 0; i < SIZE; i++) {
            vals[i] = false;
        }
        for (unsigned row = 0; row < SIZE; ++row) {
            if (board[row][col] == SENTINEL) continue;
            if (vals[board[row][col] - 1]) {
                return false;
            } else {
                vals[board[row][col] - 1] = true;
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
    bool vals[SIZE];
    for (unsigned v_block = 0; v_block < BLOCK; ++v_block) {
        for (unsigned h_block = 0; h_block < BLOCK; ++h_block) {
            for (unsigned i = 0; i < SIZE; ++i) {
                vals[i] = false;
            }

            for (unsigned block_row = 0; block_row < BLOCK; ++block_row) {
                for (unsigned block_col = 0; block_col < BLOCK; ++block_col) {
                    unsigned row = (BLOCK * v_block) + block_row;
                    unsigned col = (BLOCK * h_block) + block_col;
                    if (board[row][col] == SENTINEL) continue;
                    if (vals[board[row][col] - 1]) {
                        return false;
                    } else {
                        vals[board[row][col] - 1] = true;
                    }
                }
            }
        }
    }
    return true;
}

