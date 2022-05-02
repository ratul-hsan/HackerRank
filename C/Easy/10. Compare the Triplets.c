#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define peoblemUrl "https://www.hackerrank.com/challenges/compare-the-triplets"

int* compareTriplets(int a_count, int *a, int b_count, int *b, int *result_count) {
	int *results = (int *) malloc(*result_count * sizeof(int));
	for (int i = 0; i < a_count; i++) {
		if (a[i] < b[i])
			results[1] += 1;
		if (a[i] > b[i])
			results[0] += 1;
	}
	return results;
}

int main() {
	int arr1[] = {5, 6, 7};
	int arr2[] = {3, 6, 10};
	
	int result_count = 2;
	int* result = compareTriplets(3, arr1, 3, arr2, &result_count);
	printf("%d %d", result[0], result[1]);
	return 0;
}