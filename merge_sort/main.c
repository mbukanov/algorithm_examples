#include <stdio.h>
#include "../utils/utils.h"

#define ARRAY_SIZE 7

void merge(int *arr, int p, int q, int r) {
	int i = 0, j = 0, k = 0;
	int n1 = q - p + 1;
	int n2 = r - q;
	int L[ARRAY_SIZE];
	int R[ARRAY_SIZE];
	for(i = 0; i < n1; i++) {
		L[i] = arr[p+i];
	}
	for(i = 0; i < n2; i++) {
		R[i] = arr[q+i+1];
	}
	L[n1] = -1;
	R[n2] = -1;
	i = 0;
	j = 0;
	for(k = p; k <= r; k++) {
		if ( (L[i] <= R[j] && L[i] >= 0) || R[j] < 0 ) 
			arr[k] = L[i++];
		else
			arr[k] = R[j++];
	}
}

void merge_sort(int *arr, int p, int r) {
	if( p <= r-1) {
		int q = (p + r) / 2;
		merge_sort(arr, p, q);
		merge_sort(arr, q+1, r);
		merge(arr, p, q, r);
	}
}

void main() {
	int arr[] = { 5, 2, 3, 7, 4, 1, 6};
	print_arr(arr, ARRAY_SIZE);
	merge_sort(arr, 0, ARRAY_SIZE-1);
	print_arr(arr, ARRAY_SIZE);
}
