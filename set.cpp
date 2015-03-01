#include "set.h"

void combine(bool a[], bool b[], int size)
{
  int i;
  for (i = 0; i < size; i++) {
    if (b[i]) a[i] = true;
  }
}

bool isSubset(bool a[], bool b[], int size)
{
  int i;
  for (i = 0; i < size; i++) {
    if (a[i] && !b[i]) return false;
  }
  return true;
}

bool overlap(bool a[], bool b[], int size)
{
  int i;
  for (i = 0; i < size; i++) {
    if (a[i] && b[i]) return true;
  }
  return false;
}
