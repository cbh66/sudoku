#ifndef SET_OPS_INCLUDED
#define SET_OPS_INCLUDED
/*  This file defines operations on sets, represented as arrays of booleans,
 *      with true representing elements in the set, false representing
 *      elements out of the set.
 */


/*  setUnion()
 *  Purpose: Takes the union of two sets.
 *  Parameters: Three arrays, and a size.  All arrays must be of at least this
 *           size.  The third array will be modified, filled with the union of
 *           the first two.
 *  Returns: None.
 */
void setUnion(bool a[], bool b[], bool c[], unsigned size);

/*  setIntersection()
 *  Purpose: Takes the intersections of two sets.
 *  Parameters: Three arrays, and a size.  All arrays must be of at least this
 *           size.  The third array will be modified, filled with the
 *           intersection of the first two.
 *  Returns: None.
 */
void setIntersection(bool a[], bool b[], bool c[], unsigned size);

/*  isSubset()
 *  Purpose: Determines if one set is a subset of another.
 *  Parameters: Two arrays, a and b, and a size.  Both arrays must be at least
 *           this size.
 *  Returns: true if a is a subset of b, false if not.
 */
bool isSubset(bool a[], bool b[], unsigned size);

/*  isEmpty()
 *  Purpose: Determines if a given set is empty or not.
 *  Parameters: An array and a size.  The array must be at least this size.
 *  Returns: true if the array is empty (all elements are false), false
 *           otherwise.
 */
bool isEmpty(bool a[], unsigned size);

/*  overlap()
 *  Purpose: Determines if two sets overlap.  Equivalently, if their
 *           intersection is nonempty.
 *  Parameters: Two arrays and a size.  Both arrays must be at least this size.
 *  Returns: true if the arrays share at least one element, false otherwise.
 */
bool overlap(bool a[], bool b[], unsigned size);

#endif
