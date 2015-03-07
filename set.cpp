#include "set.h"

void setUnion(bool a[], bool b[], bool c[], unsigned size)
{
    for (unsigned i = 0; i < size; ++i) {
        c[i] = a[i] || b[i];
    }
}


void setIntersection(bool a[], bool b[], bool c[], unsigned size)
{
    for (unsigned i = 0; i < size; ++i) {
        c[i] = a[i] && b[i];
    }
}


bool isSubset(bool a[], bool b[], unsigned size)
{
    for (unsigned i = 0; i < size; ++i) {
        if (a[i] && !b[i]) return false;
    }
    return true;
}


unsigned cardinality(bool a[], unsigned size)
{
    unsigned count = 0;
    for (unsigned i = 0; i < size; ++i) {
        count += a[i];
    }
    return count;
}


bool isEmpty(bool a[], unsigned size)
{
    for (unsigned i = 0; i < size; ++i) {
        if (a[i]) return false;
    }
    return true;
}


bool overlap(bool a[], bool b[], unsigned size)
{
    for (unsigned i = 0; i < size; ++i) {
        if (a[i] && b[i]) return true;
    }
    return false;
}


void setFromInt(int n, bool set[], unsigned size)
{
    if (size <= 0 || size > 8 * sizeof(n)) return;
    for (unsigned i = 0; i < size; ++i) {
        set[i] = (n >> i) & 1;             // Gets the i'th bit of n
    }
}
