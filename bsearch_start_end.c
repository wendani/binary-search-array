int search_idx(int arr[], int lo, int hi, int x);

Void print_indices(int arr[], int n, int x) {
	int idx, start_idx, end_idx;

	if (!arr || n < 1) {
		printf("-1\n");
		return;
	}

	idx = search_idx(arr, 0, n - 1, x);
	if (idx > -1) {
		int lidx = idx;
		int ridx = idx;

		while (lidx > -1) {
			start_idx = lidx;
			lidx = search_idx(arr, 0, lidx - 1, x);
		}

		while (ridx > -1) {
			end_idx = ridx;
			ridx = search_idx(arr, ridx + 1, n - 1, x);

		}

		printf("start index: %d, end index: %d\n", start_idx, end_idx);
	}

	printf("-1\n");
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
		} else {
			// x < arr[mid]
			hi = mid - 1;
		}
	}

	return -1;
}

