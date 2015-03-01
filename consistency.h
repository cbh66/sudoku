#include<iostream>
#include"sudoku.h"
#ifndef CONSISTENCY_INCLUDED
#define CONSISTENCY_INCLUDED
bool isPossible(int board[][SIZE]);
bool validRows(int board[][SIZE]);
bool validCols(int board[][SIZE]);
bool validBlocks(int board[][SIZE]);

#endif
