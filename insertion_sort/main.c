#include <stdio.h>
#include "../utils/utils.h"

#define ARRAY_SIZE 6


void insertion_sort(int * arr) {
	int i = 0, j = 0, value = 0;

	for(i = 1; i < ARRAY_SIZE; i++) {
		value = arr[i];
		j = i - 1;
		while(j >= 0 && arr[j] < value) {
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = value;
	}
}

int main(int argc, char ** argv) {
	int a[] = { 31, 41, 59, 26, 41, 58 };
	print_arr(a, ARRAY_SIZE);
	insertion_sort(a);
	print_arr(a, ARRAY_SIZE);
	return 0;
}
