#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>

void print_arr(int *arr, int num) {
	int i = 0;
	printf("arr: ");
	for(i; i < num; i++) {
		printf(" %d", arr[i]);
	}
	printf("\n");
}


#endif
