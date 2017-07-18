/* Question 2: write a binary search function on a sorted ascending int array.
   return the index of the element.
   eg:
   int t[] = [1,3,5,7,9];
   find index of 5.
*/

//#include <stdlib.h>
#include <stdio.h>

int bsearch(int *table, int sz, int key)
{
	int low, high, mid;

	if (!table)
		return -1;

	if (sz <= 0)
		return -2;
	
	low  = 0;
	high = sz - 1;
	mid  = high >> 1;
	while (low < high) {
		if (key == table[mid])
			return mid;
		else if (key < table[mid])
			high = mid - 1;
		else
			// key > table[mid]
			low = mid + 1;

		mid = (low + high) >> 1;
	}
	// reach here, we must have low == high
	if (key == table[mid])
		return mid;

	return -3;
}

int main(int argc, char *argv[])
{
	int t[] = {1, 3, 5, 7, 9};

	printf("index = %d\n", bsearch(t, sizeof(t)/sizeof(int), 3));
	printf("index = %d\n", bsearch(t, sizeof(t)/sizeof(int), 9));
	printf("index = %d\n", bsearch(t, sizeof(t)/sizeof(int), 6));

	return 0;
}
