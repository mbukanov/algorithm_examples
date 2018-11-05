#include <stdio.h>
#include "../utils/utils.h"

#define ARRAY_SIZE 6563

#define STEP_COUNTER 

static int step_counter = 0;

int binary_search(int * arr, int value) {
	int p = 0, r = ARRAY_SIZE, q = 0;
	while(p <= r) {
#ifdef STEP_COUNTER
		step_counter++;
#endif
		q = (p + r) / 2;
		if ( arr[q] == value ) 
			return q;
		if ( arr[q] < value ) 
			p = ++q;
		else if ( arr[q] > value ) 
			r = --q;
	}
	return -1;
}

int binary_search_recursive(int *arr, int value, int start, int end) {
	step_counter++;
	if ( start > end ) return -1;
	int q = (start + end) / 2;
	if (arr[q] == value ) return q;
	if (arr[q] > value ) 
		return binary_search_recursive(arr, value, start, --q);
	else
		return binary_search_recursive(arr, value, ++q, end); 
}

int main() {
	int search_value = 5;

	int i = 0;
	int arr[ARRAY_SIZE];
	for(i; i < ARRAY_SIZE; i++) {
		arr[i] = i;
	}

	int index = binary_search(arr, search_value);
//	int index = binary_search_recursive(arr, search_value, 0, ARRAY_SIZE);
#ifdef STEP_COUNTER
	printf("step counter = %d\n", step_counter);
#endif
	printf("index = %d\n", index);

	return 0;
}
