#include "board.h"

void setNum(Guess board[][SIZE], int num, int x, int y)
{
  int i;
  for (i = 0; i < SIZE; i++) {
    board[x][y].possible[i] = false;
  }
  board[x][y].amt = 1;
  board[x][y].possible[num - 1] = true;
}
