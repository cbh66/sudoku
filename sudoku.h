#ifndef SUDOKU_H_INCLUDED
#define SUDOKU_H_INCLUDED

const int SIZE = 9;
const int BLOCK = 3;
const int SENTINEL = 0;
const int MIN = 17;

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
    bool certain;
    int amt;
    bool possible[SIZE];
    int contents;
};

/*  setNum()
 *  Purpose: Sets up the square at a particular index.
 *  Parameters: A pointer to the square to set up; the number to set it to.
 *           If this number is SENTINEL, the square is set up to allow
 *           all possibilities.  Otherwise, it indicates the value given.
 *  Returns: None.
 *  Side effects: Modifies the Guess pointed to.
 */
void setNum(Guess *square, int num);

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

#endif
