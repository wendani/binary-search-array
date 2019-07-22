int search_idx(int arr[], int lo, int hi, int x);
int _bsearch(int arr[], int lo, int hi, int x, int *start_idx, int *end_idx);

Void print_indices(int arr[], int n, int x) {
	int start_idx, end_idx;

	if (!arr || n < 1) {
		printf("-1\n");
		return;
	}

	if (!_bsearch(arr, 0, n - 1, x, &start_idx, &end_idx)) {
		printf("start index: %d, end index: %d\n", start_idx, end_idx);
	}
	else {
		printf("-1\n");
	}
}

int _bsearch(int arr[], int lo, int hi, int x, int *start_idx, int *end_idx)
{
	if (!start_idx || !end_idx) {
		return -2;
	}

	int idx = search_idx(arr, lo, hi, x);
	if (idx > -1) {
		int s_idx, e_idx;
		if (!_bsearch(arr, lo, idx - 1, x, &s_idx, &e_idx)) {
			*start_idx = s_idx;
		}
		else {
			*start_idx = idx;
		}

		if (!_bsearch(arr, idx + 1, hi, x, &s_idx, &e_idx)) {
			*end_idx = e_idx;
		}
		else {
			*end_idx = idx;
		}
		return 0;
	}
	return -1;
}

int search_idx(int arr[], int lo, int hi, int x)
{
	if (!arr) {
		return -1;
	}

	while (lo <= hi) {
		int mid = (lo + hi) >> 1;

		if (arr[mid] == x) {
			return mid;
		}
		else if (arr[mid] < x) {
			lo = mid + 1;
		}
		else {
			// x < arr[mid]
			hi = mid - 1;
		}
	}

	return -1;
}
