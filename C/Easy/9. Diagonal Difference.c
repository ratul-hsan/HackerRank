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

#define problemUrl "https://www.hackerrank.com/challenges/diagonal-difference"

int diagonalDifference(int arr_rows, int arr_columns, int **arr) {
	int ltr = 0, rtr = 0;

	for (int i = 0; i < arr_rows; i++)
		ltr += arr[i][i], rtr += arr[i][arr_columns - 1 - i];
	return abs(ltr - rtr);
}

int main() {
	int length = 3;
	int array[][3] = {{11, 2, 4}, {4, 5, 6}, {10, 8, -12}};
	int** arr = malloc(length * sizeof(int*));

    for (int i = 0; i < length; i++) {
        *(arr + i) = malloc(length * (sizeof(int)));
        for (int j = 0; j < length; j++)
            *(*(arr + i) + j) = array[i][j];
    }

    int result = diagonalDifference(length, length, arr);

    printf("%d\n", result);
	return 0;
}