#include <iostream>
#include "solve.h"
#include "sudoku.h"
using namespace std;


void eliminateRowSubset(Guess board[SIZE][SIZE], unsigned row, unsigned block);
bool inRow(Guess board[SIZE][SIZE], unsigned row, unsigned block,
           unsigned possibility);
void removeRowGuessFromBlock(Guess board[SIZE][SIZE], unsigned guess_row,
                             unsigned h_block, unsigned to_remove);
bool inRowBlock(Guess board[SIZE][SIZE], unsigned v_block, unsigned h_block,
                unsigned guess_row, unsigned possibility);
void removeBlockGuessFromRow(Guess board[SIZE][SIZE], unsigned block,
                             unsigned row, unsigned to_remove);

void eliminateColSubset(Guess board[SIZE][SIZE], unsigned col, unsigned block);
bool inCol(Guess board[SIZE][SIZE], unsigned col, unsigned block,
           unsigned possibility);
void removeColGuessFromBlock(Guess board[SIZE][SIZE], unsigned guess_col,
                             unsigned v_block, unsigned to_remove);
bool inColBlock(Guess board[SIZE][SIZE], unsigned v_block, unsigned h_block,
                unsigned guess_col, unsigned possibility);
void removeBlockGuessFromCol(Guess board[SIZE][SIZE], unsigned block,
                             unsigned col, unsigned to_remove);



void eliminateGroups(Guess board[SIZE][SIZE])
{
    for (unsigned row_or_col = 0; row_or_col < SIZE; ++row_or_col) {
        for (unsigned block = 0; block < BLOCK; ++block) {
            eliminateRowSubset(board, row_or_col, block);
            eliminateColSubset(board, row_or_col, block);
        }
    }
}


/* eliminateRowSubset()
 * Purpose: Examines each row subset, meaning each sequence of BLOCK squares
 *          where a row intersects a block.  For each, looks for possibilities
 *          within that subset that do not appear elsewhere in the row, or that
 *          do not appear elsewhere in the block.  In the former case, such
 *          possibilities are eliminated from the block outside the subset.
 *          In the latter, they are eliminated from the row outside the block.
 * Parameters: The board; the row; the block (a number from 0 to BLOCK).
 * Returns: None.
 * Side effects: Modifies the board array to eliminate possibilities.
 */
void eliminateRowSubset(Guess board[SIZE][SIZE], unsigned row, unsigned block)
{
    for (unsigned col = block * BLOCK; col < (block + 1) * BLOCK; ++col) {
        for (unsigned possibility = 0; possibility < SIZE; ++possibility) {
            if (board[row][col].possible[possibility]) {
                if (!inRow(board, row, block, possibility)) {
                    removeRowGuessFromBlock(board, row, block,
                                            possibility);
                }
                if (!inRowBlock(board, row / BLOCK, block, row, possibility)) {
                    removeBlockGuessFromRow(board, block, row, possibility);
                }
            }
        }
    }
}


/* inRow()
 * Purpose: Determines if a possibility is in a given row, outside of a given
 *          block.
 * Parameters: The board; the row; the block (between 0 and BLOCK); the
 *          possibility to look for.
 * Returns: True if there is a possibility, false if not
 * Notes: Can call with a negative block to check the entire row.
 */
bool inRow(Guess board[SIZE][SIZE], unsigned row, unsigned block,
           unsigned possibility)
{
    for (unsigned col = 0; col < SIZE; ++col) {
        if ((col < block * BLOCK || col >= (block + 1) * BLOCK) &&
            board[row][col].possible[possibility]) {
            return true;
        }
    }
    return false;
}


/* removeRowGuessFromBlock()
 * Purpose: Removes a given possibility from a given block, except in the
 *          given row.
 * Parameters: The board; the row to ignore; the horizontal position of the
 *          block (between 0 and BLOCK); the possibility to remove.
 * Returns: None.
 * Side effects: Modifies the board possibilities.
 */
void removeRowGuessFromBlock(Guess board[SIZE][SIZE], unsigned guess_row,
                             unsigned h_block, unsigned to_remove)
{
    for (unsigned row = (guess_row / BLOCK) * BLOCK;
         row < (guess_row / BLOCK + 1) * BLOCK; ++row) {
        for (unsigned col = h_block * BLOCK; col < (h_block + 1) * BLOCK;
             ++col) {
            if (row != guess_row) {
                board[row][col].possible[to_remove] = false;
            }
        }
    }
}


/* inRowBlock()
 * Purpose: Determines if a possibility is in a given block, outside of a given
 *          row.
 * Parameters: The board; the vertical and horizontal block numbers (both
 *          between 0 and BLOCK); the row; the possibility to look for.
 * Returns: True if there is a possibility, false if not
 * Notes: Can call with a negative row to check the entire block.
 */
bool inRowBlock(Guess board[SIZE][SIZE], unsigned v_block, unsigned h_block,
                unsigned guess_row, unsigned possibility)
{
    for (unsigned row = v_block * BLOCK; row < (v_block + 1) * BLOCK; ++row) {
        for (unsigned col = h_block * BLOCK; col < (h_block + 1) * BLOCK;
             ++col) {
            if (row != guess_row && board[row][col].possible[possibility]) {
                return true;
            }
        }
    }
    return false;
}


/* removeBlockGuessFromRow()
 * Purpose: Removes a given possibility from a given row, except in the
 *          given block.
 * Parameters: The board; the horizontal position of the block to ignore
 *          (between 0 and BLOCK); the row; the possibility to remove.
 * Returns: None.
 * Side effects: Modifies the board possibilities.
 */
void removeBlockGuessFromRow(Guess board[SIZE][SIZE], unsigned block,
                             unsigned row, unsigned to_remove)
{
    for (unsigned col = 0; col < SIZE; ++col) {
        if (col / BLOCK != block) {
            board[row][col].possible[to_remove] = false;
        }
    }
}



/* eliminateColSubset()
 * Purpose: Examines each column subset, meaning each sequence of BLOCK squares
 *          where a column intersects a block.  For each, looks for
 *          possibilities within that subset that do not appear elsewhere in
 *          the column, or that do not appear elsewhere in the block.  In the
 *          former case, such possibilities are eliminated from the block
 *          outside the subset.  In the latter, they are eliminated from the
 *          column outside the block.
 * Parameters: The board; the column; the block (a number from 0 to BLOCK).
 * Returns: None.
 * Side effects: Modifies the board array to eliminate possibilities.
 */
void eliminateColSubset(Guess board[SIZE][SIZE], unsigned col, unsigned block)
{
    for (unsigned row = block * BLOCK; row < (block + 1) * BLOCK; ++row) {
        for (unsigned possibility = 0; possibility < SIZE; ++possibility) {
            if (board[row][col].possible[possibility]) {
                if (!inCol(board, col, block, possibility)) {
                    removeColGuessFromBlock(board, col, block,
                                            possibility);
                }
                if (!inColBlock(board, row / BLOCK, block, col, possibility)) {
                    removeBlockGuessFromCol(board, block, col, possibility);
                }
            }
        }
    }
}


/* inCol()
 * Purpose: Determines if a possibility is in a given column, outside of a
 *          given block.
 * Parameters: The board; the column; the block (between 0 and BLOCK); the
 *          possibility to look for.
 * Returns: True if there is a possibility, false if not
 * Notes: Can call with a negative block to check the entire column.
 */
bool inCol(Guess board[SIZE][SIZE], unsigned col, unsigned block,
           unsigned possibility)
{
    for (unsigned row = 0; row < SIZE; ++row) {
        if ((row < block * BLOCK || row >= (block + 1) * BLOCK) &&
            board[row][col].possible[possibility]) {
            return true;
        }
    }
    return false;
}


/* removeColGuessFromBlock()
 * Purpose: Removes a given possibility from a given block, except in the
 *          given column.
 * Parameters: The board; the column to ignore; the vertical position of the
 *          block (between 0 and BLOCK); the possibility to remove.
 * Returns: None.
 * Side effects: Modifies the board possibilities.
 */
void removeColGuessFromBlock(Guess board[SIZE][SIZE], unsigned guess_col,
                             unsigned v_block, unsigned to_remove)
{
    for (unsigned col = (guess_col / BLOCK) * BLOCK;
         col < (guess_col / BLOCK + 1) * BLOCK; ++col) {
        for (unsigned row = v_block * BLOCK; row < (v_block + 1) * BLOCK;
             ++row) {
            if (col != guess_col) {
                board[row][col].possible[to_remove] = false;
            }
        }
    }
}


/* inColBlock()
 * Purpose: Determines if a possibility is in a given block, outside of a given
 *          column.
 * Parameters: The board; the vertical and horizontal block numbers (both
 *          between 0 and BLOCK); the column; the possibility to look for.
 * Returns: True if there is a possibility, false if not
 * Notes: Can call with a negative column to check the entire block.
 */
bool inColBlock(Guess board[SIZE][SIZE], unsigned v_block, unsigned h_block,
                unsigned guess_col, unsigned possibility)
{
    for (unsigned row = v_block * BLOCK; row < (v_block + 1) * BLOCK; ++row) {
        for (unsigned col = h_block * BLOCK; col < (h_block + 1) * BLOCK;
             ++col) {
            if (col != guess_col && board[row][col].possible[possibility]) {
                return true;
            }
        }
    }
    return false;
}


/* removeBlockGuessFromCol()
 * Purpose: Removes a given possibility from a given column, except in the
 *          given block.
 * Parameters: The board; the vertical position of the block to ignore
 *          (between 0 and BLOCK); the column; the possibility to remove.
 * Returns: None.
 * Side effects: Modifies the board possibilities.
 */
void removeBlockGuessFromCol(Guess board[SIZE][SIZE], unsigned block,
                             unsigned col, unsigned to_remove)
{
    for (unsigned row = 0; row < SIZE; ++row) {
        if (row / BLOCK != block) {
            board[row][col].possible[to_remove] = false;
        }
    }
}
