#include <iostream>
#include "board.h"
#include "set.h"
#include "span.h"
using namespace std;

/*  The idea:
"Span" checker - if there are x boxes in the same sequence that are ALL a
    subset of the same x values, they must share those values between them.
    Thus other cells in the same sequence cannot take on any of them.
   eg. if 2 blocks in the same sequence each have 1 and 4 as possibilities,
      then one must be 1, the other 4; thus no other block in the same
      sequence can be either 1 or 4.

    We do this by checking a square's possibilities.  We then look at unsolved
        squares, not inclusing this one, in the same sequence.
    We take the union of all of their possibilities.
    If the amount in that intersection is equal to the amount of unsolved
        squares, then the values must be shared between them.
    Hence we remove the value of the intersection from this square's
        possibilites
 */


/*
int main()
{
  bool a[9];
  bool b[9];
  int i;
  for (i = 0; i < 9; i++) {
    a[i] = b[i] = true;
  }
  a[8] = false;
  cout << isSubset(a, b, 9) << endl;

  return 0;
}


void setAll(bool a[], bool val, int size)
{
  int i;
  for (i = 0; i < size; i++) a[i] = val;
}


int arrCount(bool arr[], int size)
{
  int i, count = 0;
  for (i = 0; i < size; i++) {
    if (arr[i]) count++;
  }
  return count;
}


void findRowSubsets(Guess board[][SIZE], int row,  bool numbers[])
{
  int i;
  bool set[SIZE];
  setAll(set, false, SIZE);
  setAll(positions, false, SIZE);
  setAll(numbers, false, SIZE);
  for (i = 0; i < SIZE; i++) {
    if (board[row][i].amt != 1) genSpan(board, row, i, set, positions);
  }

}

void genRowSets(Guess board[][SIZE], int row, int col,
	     bool positions[], bool span[])
{
  int i;
  for (i = 0; i < SIZE; i++) {
    if (board[row][i] != 1 && overlap(....)) {  // FIX THIS.
      combine(span, board[row][i].possible);
    }
  }
}


void findSubsetForRow(Guess board[][SIZE], int row, bool position[],
		   bool set[])
{
  int i;
  for (i = 0; i < SIZE; i++) {
    if (position[i]) {
      combine(set, board[row][i].possible, SIZE);
    }
  }
}
*/