/* solver.cpp
 *   A program to solve Sudoku puzzles.  Provide it with input from std input
 *   in the expected format:
 *     Inputs are listed from left to right, top to bottom (as one would draw
 *     them) with a space between each box, and a  single dash ('-')
 *     representing unknowns.
 *
 *   By Colin Hamilton
 *   Created Feb 6, 2014
 *   Last modified Feb 6, 2014
 */

/*
   TO DO:
"Span" checker - if there are x boxes in the same sequence that are ALL a
    subset of the same x values, they must share those values between them.
    Thus other cells in the same sequence cannot take on any of them.
   eg. if 2 blocks in the same sequence each have 1 and 4 as possibilities,
      then one must be 1, the other 4; thus no other block in the same
      sequence can be either 1 or 4.

  Subgroup exclusion
      If squares in the same row/column AND same region share a particular
      value, and are the only ones to share that value, then one of them
      must have it.  This eliminates that value as a possibility for other
      squares in the same row or region.  This is somewhat similar to
      the span idea.

Hypothetical - last resort, should only be needed for super-hard puzzles.
    Essentially, test each possibility for the unknown, and continue solving
    as if that were fact.  If this results in an inconsistent board, eliminate
    it as a possibility.
 */

#include <iostream>
#include "sudoku.h"
#include "consistency.h"
#include "solve.h"
using namespace std;

bool read(int board[][SIZE]);
void print(int board[][SIZE]);
void solve(int board[][SIZE]);
void solveAll(Guess board[][SIZE]);
void setNum(Guess *square, int num);
int numGuesses(Guess board[][SIZE]);
int numCertain(Guess board[][SIZE]);
void printGuesses(Guess board[][SIZE]);

int main()
{
    int board[SIZE][SIZE];

    if (!read(board) || !isPossible(board)) {
        cout << "It is impossible to solve this board." << endl;
        return 1;
    }
    print(board);
    cout << endl;
    solve(board);
    print(board);

    return 0;
}


/* read()
 *  Purpose: Reads the board from std input, storing it in the given 2-D
 *    array, which (having been passed by reference) is overwritten with the
 *    proper values, SENTINEL representing an unknown.
 *  Arguments: the array (which must be at least SIZExSIZE)
 *  Returns: A boolean, normally true, but false if there are too few clues
 *    for the board to be solveable.
 */
bool read(int board[][SIZE])
{
    int i, j, count = 0;
    string x;
    for (i = 0; i < SIZE; ++i) {
        for (j = 0; j < SIZE; ++j) {
            cin >> board[i][j];
            if (cin.fail()) {
                cin.clear();
                board[i][j] = SENTINEL;
            } else {
               ++count;
            }
        }
    }
    return (count >= MIN);
}


/* print()
 *  Purpose: Prints the given board to std output.
 *  Arguments: the board to print (which must be at least SIZExSIZE)
 *  Returns: nothing
 *  Notes: does not modify the array
 */
void print(int board[][SIZE])
{
    int i, j;
    for (i = 0; i < SIZE; ++i) {
        for (j = 0; j < SIZE; ++j) {
            if (j != 0) cout << " ";
            if (board[i][j] == SENTINEL) cout << "-";
            else cout << board[i][j];
        }
        cout << endl;
    }
}


/* solve()
 *   Purpose:  Solves the given board to the extent that it is possible to do
 *     so.
 *   Arguments:  The board to solve.  This is passed by reference and so WILL
 *     BE MODIFIED.
 *   Returns:  Nothing; uses the board parameter to "return" the solved board
 */
void solve(int board[][SIZE])
{
    int i, j, k;
    Guess copy[SIZE][SIZE];
    for (i = 0; i < SIZE; ++i) {
        for (j = 0; j < SIZE; ++j) {
	       setNum(&copy[i][j], board[i][j]);
        }
    }

    solveAll(copy);

    for (i = 0; i < SIZE; ++i) {
        for (j = 0; j < SIZE; ++j) {
            if (copy[i][j].amt == 1) {
                for (k = 0; k < SIZE; ++k) {
                    if (copy[i][j].possible[k]) break;
                }
                board[i][j] = k + 1;
            }
        }
    }
}


/*  solveAll()
 *  Purpose: Given a board of guesses, eliminates possibilities to solve it.
 *  Parameters: The board, which must be SIZExSIZE.  The array will be modified
 *           as it is solved.
 *  Returns: None.
 *  Notes:   Does not yet work on all inputs.  Will do its best.
 *           Repeats a number of strategies while it can still make progress.
 *           Stops when it can no longer eliminate anything.
 */
void solveAll(Guess board[][SIZE])
{
    int before =  numGuesses(board);
    int after = 0;
    cerr << "Before: " << before << endl;
    printGuesses(board);
    while (before != after) {
        elimAllRepeats(board);
        cerr << "Eliminated some repeats: left with " << numGuesses(board)
             << endl;
        printGuesses(board);
        findUniqueNums(board);
        cerr << "Found some unique numbers: left with " << numGuesses(board)
             << endl;
        printGuesses(board);

        before = after;
        after = numGuesses(board);
        cerr << "Next: " << after << endl;
    }
}


// For debugging.  Prints the number of possibilities at each square.
void printGuesses(Guess board[][SIZE])
{
    int i, j;
    for (i = 0; i < SIZE; ++i) {
        for (j = 0; j < SIZE; ++j) {
            cout << board[i][j].amt << " ";
        }
        cout << endl;
    }
    cout << endl;
}

