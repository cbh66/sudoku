#ifndef SUDOKU_H_INCLUDED
#define SUDOKU_H_INCLUDED

const unsigned SIZE = 9;
const unsigned BLOCK = 3;
const int SENTINEL = 0;
const unsigned MIN = 17;

/*   Contains a Guess for a given square of a sudoku board.
 *   certain refers to whether this square has yet been solved
 *     If true, contents will contan what the square should have
 *     If false, possible[] contains an entry for every number, true or
 *        false, representing whether the solver considers such a number
 *        to be possible.
 *    amt represents how many possibilities there are, ie. how many in
 *        possible[] are true.  Of course, if certain is true, amt == 1.
 */
struct Guess {
    unsigned amt;
    bool possible[SIZE];
};

/*  setNum()
 *  Purpose: Sets up the square at a particular index.
 *  Parameters: A pointer to the square to set up; the number to set it to.
 *           If this number is SENTINEL, the square is set up to allow
 *           all possibilities.  Otherwise, it indicates the value given.
 *  Returns: None.
 *  Side effects: Modifies the Guess pointed to.
 */
void setNum(Guess *square, unsigned num);

/*  numGuesses()
 *  Purpose: Calculates the number of guesses on the board, ie. the sum of the
 *           possibilities for each square.
 *  Parameters: The board, which must be of SIZExSIZE.  It will not be
 *           modified.
 *  Returns: An integer representing the number of guesses.
 */
int numGuesses(Guess board[][SIZE]);

/*  numCertain()
 *  Purpose: Calculates the number of squares in the board that have been
 *           solved.
 *  Parameters: The board, which must be SIZExSIZE.  It will not be
 *           modified.
 *  Returns: An integer representing the number of solved squares.
 */
int numCertain(Guess board[][SIZE]);

/*  printBoard()
 *  Purpose: Prints the current board of guesses in a nicely formatted output
 *           that lists for each box all possibilities, and indicates the
 *           board's division into blocks.
 *  Parameters: The board to print.
 *  Returns: None.
 */
void printBoard(Guess board[SIZE][SIZE]);

/* isPossible
 *   Purpose:  Checks if it is possible to solve a board.
 *   Parameters:  The board to check.
 *   Returns:  True if possible, false if impossible.
 *   Notes:    This function can be used in two ways:
 *             - To check if an incomplete board is consistent, and so possible
 *                to solve; or
 *             - To check if a completed board is correctly solved.
 */
bool isPossible(int board[][SIZE]);

#endif
