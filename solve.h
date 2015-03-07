#ifndef SOLVE_H_INCLUDED
#define SOLVE_H_INCLUDED
#include "sudoku.h"

/*  elimAllRepeats()
 *  Purpose: Eliminates possibilites on the board based on squares that have
 *           been solved.  That is, for every solved square, its value is
 *           removed as a possibility from squares in the same row, column,
 *           or block.
 *  Parameters: The array of guesses, which will be modified.
 *  Returns: Nothing.
 */
void elimAllRepeats(Guess board[][SIZE]);

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
void findUniqueNums(Guess board[][SIZE]);

/*  eliminateGroups()
 *  Purpose: Considers all "subgroups" -- sets of three squares where a row or
 *           column intersects a block.  If there are any possibilities in this
 *           subgroup not present elsewhere in the row/column, they are
 *           eliminated from the rest of the block.  Similarly, if they are not
 *           present in the rest of the block, they are eliminated from the
 *           row/column.
 *  Parameters: The array of guesses to examine, which will be modified.
 *  Returns: Nothing.
 */
void eliminateGroups(Guess board[SIZE][SIZE]);


void eliminatePermutations(Guess board[SIZE][SIZE]);

#endif
