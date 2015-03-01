#include "set.h"

void setUnion(bool a[], bool b[], bool c[], int size)
{
    int i;
    for (i = 0; i < size; ++i) {
        c[i] = a[i] || b[i];
    }
}


void setIntersection(bool a[], bool b[], bool c[], unsigned size)
{
    int i;
    for (i = 0; i < size; ++i) {
        c[i] = a[i] && b[i];
    }
}


bool isSubset(bool a[], bool b[], int size)
{
    int i;
    for (i = 0; i < size; ++i) {
        if (a[i] && !b[i]) return false;
    }
    return true;
}


bool isEmpty(bool a[], unsigned size)
{
    int i;
    for (i = 0; i < size; ++i) {
        if (a[i]) return false;
    }
    return true;
}


bool overlap(bool a[], bool b[], int size)
{
    int i;
    for (i = 0; i < size; ++i) {
        if (a[i] && b[i]) return true;
    }
    return false;
}
