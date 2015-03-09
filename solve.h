#ifndef SOLVE_H_INCLUDED
#define SOLVE_H_INCLUDED
#include "sudoku.h"

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

/*  eliminatePermutations()
 *  Purpose: Considers all subsets of a row, column, and block.  If the
 *           subgroup has size n, and they share exactly n possibilities
 *           among them, then these possibilities are eliminated from
 *           elsewhere in the row, column, or block.
 *           Special cases:
 *           - Solved squares are treated as a group of size 1, and so are
 *             eliminated from elsewhere in the row, column, and block.
 *           - Twin exclusion: when two squares share two values, these can
 *             be eliminated from elsewhere in the row/column/block.
 *           - Subgroup exclusion: Considers where a row/column intersects a
 *             block.
 */
void eliminatePermutations(Guess board[SIZE][SIZE]);

#endif
