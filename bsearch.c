/* Question 2: write a binary search function on a sorted ascending int array.
   return the index of the element.
   eg:
   int t[] = [1,3,5,7,9];
   find index of 5.
*/

//#include <stdlib.h>
#include <stdio.h>

int bsearch(int *table, int sz, int key) {
	int low, high, mid;

	if (!table)
		return -1;

	if (sz <= 0)
		return -2;
	
	low  = 0;
	high = sz;
	while (low < high) {
		mid = (low + high) >> 1;

		if (key == table[mid])
			return mid;
		else if (key < table[mid])
			high = mid;
		else
			// key > table[mid]
			low = mid + 1;
	}
	return -3;
}

int bsearch_recur(int *table, int sz, int key) {
	int mid, ret_val;

	if (!table)
		return -1;

	if (sz <= 0)
		return -1;

	if (sz == 1) {
		if (*table == key)
			return 0;
		else
			return -1;
	}

	// If we reach here, sz >= 2
	mid = sz >> 1;
	if (key == table[mid])
		return mid;
	else if (key < table[mid])
		return bsearch_recur(table, mid, key);
	else {
		// key > table[mid]
		ret_val = bsearch_recur(table + mid + 1, sz - mid - 1, key);
		if (ret_val < 0)
			return ret_val;
		else
			return mid + 1 + ret_val;
	}
}

// one base of (sz <= 0) is enough
int bsearch_recur_onebase(int *table, int sz, int key) {
	int mid, ret_val;

	if (!table)
		return -1;

	if (sz <= 0)
		return -1;

	// case of sz > 0
	mid = sz >> 1;
	if (key == table[mid])
		return mid;
	else if (key < table[mid])
		return bsearch_recur_onebase(table, mid, key);
	else {
		// key > table[mid]
		ret_val = bsearch_recur_onebase(table + mid + 1, sz - mid - 1, key);
		if (ret_val < 0)
			return ret_val;
		else
			return mid + 1 + ret_val;
	}
}

int main(int argc, char *argv[])
{
	int t[] = {1, 3, 5, 7, 9};

	printf("index = %d\n", bsearch(t, sizeof(t)/sizeof(int), 3));
	printf("index = %d\n", bsearch(t, sizeof(t)/sizeof(int), 9));
	printf("index = %d\n", bsearch(t, sizeof(t)/sizeof(int), 6));

	printf("bsearch_recur\n");
	printf("index = %d\n", bsearch_recur(t, sizeof(t)/sizeof(int), 1));
	printf("index = %d\n", bsearch_recur(t, sizeof(t)/sizeof(int), 3));
	printf("index = %d\n", bsearch_recur(t, sizeof(t)/sizeof(int), 5));
	printf("index = %d\n", bsearch_recur(t, sizeof(t)/sizeof(int), 7));
	printf("index = %d\n", bsearch_recur(t, sizeof(t)/sizeof(int), 9));
	printf("index = %d\n", bsearch_recur(t, sizeof(t)/sizeof(int), -1));
	printf("index = %d\n", bsearch_recur(t, sizeof(t)/sizeof(int), 2));
	printf("index = %d\n", bsearch_recur(t, sizeof(t)/sizeof(int), 4));
	printf("index = %d\n", bsearch_recur(t, sizeof(t)/sizeof(int), 6));
	printf("index = %d\n", bsearch_recur(t, sizeof(t)/sizeof(int), 8));
	printf("index = %d\n", bsearch_recur(t, sizeof(t)/sizeof(int), 10));

	printf("bsearch_recur_onebase\n");
	printf("index = %d\n", bsearch_recur_onebase(t, sizeof(t)/sizeof(int), 1));
	printf("index = %d\n", bsearch_recur_onebase(t, sizeof(t)/sizeof(int), 3));
	printf("index = %d\n", bsearch_recur_onebase(t, sizeof(t)/sizeof(int), 5));
	printf("index = %d\n", bsearch_recur_onebase(t, sizeof(t)/sizeof(int), 7));
	printf("index = %d\n", bsearch_recur_onebase(t, sizeof(t)/sizeof(int), 9));
	printf("index = %d\n", bsearch_recur_onebase(t, sizeof(t)/sizeof(int), -1));
	printf("index = %d\n", bsearch_recur_onebase(t, sizeof(t)/sizeof(int), 2));
	printf("index = %d\n", bsearch_recur_onebase(t, sizeof(t)/sizeof(int), 4));
	printf("index = %d\n", bsearch_recur_onebase(t, sizeof(t)/sizeof(int), 6));
	printf("index = %d\n", bsearch_recur_onebase(t, sizeof(t)/sizeof(int), 8));
	printf("index = %d\n", bsearch_recur_onebase(t, sizeof(t)/sizeof(int), 10));

	return 0;
}
