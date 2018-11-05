#include <stdio.h>
#include "../utils/utils.h"

#define ARRAY_SIZE 7

void swap(int *first, int *second) {
	int tmp_var = *first;
	*first = *second;
	*second = tmp_var;
}

int partition(int * arr, int start, int end) {
	int i = 0, q = start, tmp_var = 0, r = end-1;
	for(i = start; i < end; i++)  {
		if( arr[i] <= arr[r] ) {
			swap(&arr[q], &arr[i]);
			q++;
		}
	}
	swap(&arr[end-1], &arr[r]);
	return q;
}

void quick_sort(int * arr, int start, int end) {
	if(start >= end) return;
	int q = partition(arr, start, end);
	quick_sort(arr, start, q-1);
	quick_sort(arr, q, end);
}

void main() {
	int arr[] = { 34, 23, 64, 24, 12, 84, 10 };

	print_arr(arr, ARRAY_SIZE);
	quick_sort(arr, 0, ARRAY_SIZE);
	print_arr(arr, ARRAY_SIZE);
}
