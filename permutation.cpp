#include <iostream>
#include "sudoku.h"
#include "solve.h"
#include "set.h"
using namespace std;


void findRowGroups(Guess board[SIZE][SIZE], unsigned row);
void removeFromRow(Guess board[SIZE][SIZE], unsigned row, unsigned to_remove,
                   bool exempt[]);
void findColGroups(Guess board[SIZE][SIZE], unsigned col);
void removeFromCol(Guess board[SIZE][SIZE], unsigned col, unsigned to_remove,
                   bool exempt[]);
void findBlockGroups(Guess board[SIZE][SIZE], unsigned h_block,
                     unsigned v_block);
void removeFromBlock(Guess board[SIZE][SIZE], unsigned h_block,
                     unsigned v_block, unsigned to_remove, bool exempt[]);


/*  Basic idea: Take the union of the possibilities for the squares under
 *     consideration.  Check if the size of the union is the same as the
 *     number of squares.  If so, eliminate these guesses from the other
 *     squares in the same group.
 *  For i from 0 to 2^SIZE:
 *     Translate the binary representation of i into a set.
 *
 */


void eliminatePermutations(Guess board[SIZE][SIZE])
{
    for (unsigned i = 0; i < SIZE; ++i) {
        findRowGroups(board, i);
        findColGroups(board, i);
        findBlockGroups(board, i / BLOCK, i % BLOCK);
    }
}


void findRowGroups(Guess board[SIZE][SIZE], unsigned row)
{
    unsigned permutations = 1 << SIZE;
    bool to_check[SIZE];
    bool guess_union[SIZE];
    for (unsigned i = 0; i < permutations; ++i) {
        for (unsigned j = 0; j < SIZE; ++j) {
            guess_union[j] = false;
        }
        setFromInt(i, to_check, SIZE);
        for (unsigned col = 0; col < SIZE; ++col) {
            if (to_check[col]) {
                setUnion(guess_union, board[row][col].possible, guess_union,
                         SIZE);
            }
        }
        if (cardinality(to_check, SIZE) == cardinality(guess_union, SIZE)) {
            for (unsigned j = 0; j < SIZE; ++j) {
                if (guess_union[j]) {
                    removeFromRow(board, row, j, to_check);
                }
            }
        }
    }
}


void removeFromRow(Guess board[SIZE][SIZE], unsigned row, unsigned to_remove,
                   bool exempt[])
{
    for (unsigned col = 0; col < SIZE; ++col) {
        if (!exempt[col]) {
            board[row][col].possible[to_remove] = false;
        }
    }
}


void findColGroups(Guess board[SIZE][SIZE], unsigned col)
{
    unsigned permutations = 1 << SIZE;
    bool to_check[SIZE];
    bool guess_union[SIZE];
    for (unsigned i = 0; i < permutations; ++i) {
        for (unsigned j = 0; j < SIZE; ++j) {
            guess_union[j] = false;
        }
        setFromInt(i, to_check, SIZE);
        for (unsigned row = 0; row < SIZE; ++row) {
            if (to_check[row]) {
                setUnion(guess_union, board[row][col].possible, guess_union,
                         SIZE);
            }
        }
        if (cardinality(to_check, SIZE) == cardinality(guess_union, SIZE)) {

            for (unsigned j = 0; j < SIZE; ++j) {
                if (guess_union[j]) {
                    removeFromCol(board, col, j, to_check);
                }
            }
        }
    }
}


void removeFromCol(Guess board[SIZE][SIZE], unsigned col, unsigned to_remove,
                   bool exempt[])
{
    for (unsigned row = 0; row < SIZE; ++row) {
        if (!exempt[row]) {
            board[row][col].possible[to_remove] = false;
        }
    }
}


void findBlockGroups(Guess board[SIZE][SIZE], unsigned h_block,
                     unsigned v_block)
{
    unsigned permutations = 1 << SIZE;
    bool to_check[SIZE];
    bool guess_union[SIZE];
    for (unsigned i = 1; i < permutations; ++i) {
        for (unsigned j = 0; j < SIZE; ++j) {
            guess_union[j] = false;
        }
        setFromInt(i, to_check, SIZE);
        for (unsigned j = 0; j < SIZE; ++j) {
            unsigned row = (v_block * BLOCK) + j / BLOCK;
            unsigned col = (h_block * BLOCK) + j % BLOCK;
            if (to_check[j]) {
                setUnion(guess_union, board[row][col].possible, guess_union,
                         SIZE);
            }
        }
        if (cardinality(to_check, SIZE) == cardinality(guess_union, SIZE)) {
            for (unsigned j = 0; j < SIZE; ++j) {
                if (guess_union[j]) {
                    removeFromBlock(board, h_block, v_block, j, to_check);
                }
            }
        }
    }
}


void removeFromBlock(Guess board[SIZE][SIZE], unsigned h_block,
                     unsigned v_block, unsigned to_remove, bool exempt[])
{
    for (unsigned i = 0; i < SIZE; ++i) {
        if (!exempt[i]) {
            unsigned row = (v_block * BLOCK) + i / BLOCK;
            unsigned col = (h_block * BLOCK) + i % BLOCK;
            board[row][col].possible[to_remove] = false;
        }
    }
}
