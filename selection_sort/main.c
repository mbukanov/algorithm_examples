#include <stdio.h>
#include "../utils/utils.h"

#define ARRAY_SIZE 6

/* Sort order
 * if defined SORT_DESC: desc order
 * if not defined SORT_DESC: acs order
 */

//#define SORT_DESC

void selection_sort(int * arr) {
	int i =0, idx1 = 0, idx2 = 0;

	while(idx1 < ARRAY_SIZE) {
		// selection
		for( i = idx1; i < ARRAY_SIZE; i++) 
#ifdef SORT_DESC
			if( arr[i] > arr[idx2])
#else
			if( arr[i] < arr[idx2])
#endif
				idx2 = i;

		// swapping
		int tmp_val = arr[idx2];
		arr[idx2] = arr[idx1];
		arr[idx1] = tmp_val;

		// counter shift
		idx2 = ++idx1;
	}
}

void main() {
	int i = 0;
	int arr[] = { 23, 12, 53, 23, 42, 52 };
	print_arr(arr, ARRAY_SIZE);
	selection_sort(arr);
	print_arr(arr, ARRAY_SIZE);
}
