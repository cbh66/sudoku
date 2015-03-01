#ifndef SPAN_INCLUDED
#define SPAN_INCLUDED

bool isSubset(bool a[], bool b[], int size);
void findRowSubsets(Guess board[][SIZE], int row,  bool numbers[]);
void genSets(Guess board[][SIZE], int row, int col,
	     bool positions[], bool span[]);
void setAll(bool a[], bool val, int size);
int arrCount(bool arr[], int size);
void findSubsetForRow(Guess board[][SIZE], int row, bool position[],
		   bool set[]);


#endif
