#ifndef SUDOKU_INCLUDED
#define SUDOKU_INCLUDED

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

#endif
