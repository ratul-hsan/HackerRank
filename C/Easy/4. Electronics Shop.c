#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define problemUrl "https://www.hackerrank.com/challenges/electronics-shop"

void swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

void bubbleSort(int* array, int start, int end, bool ascending) {
	for (int pass = start; pass < end - 1; pass++) {
		bool sorted = true;
		
		for (int currIndex = start; currIndex < end - pass; currIndex++) {
			if (ascending) {
			    if (array[currIndex] > array[currIndex + 1]) {
			        swap(&array[currIndex], &array[currIndex + 1]);
		        	sorted = false;
		     	}
			} else {
                 if (array[currIndex]  < array[currIndex + 1]) {
			        swap(&array[currIndex], &array[currIndex + 1]);
		        	sorted = false;
		     	}
			}
		}
		if (sorted) return;
	}
}

int getMoneySpent(int keyboards_count, int *keyboards, int drives_count, int *drives, int b) {
	bubbleSort(keyboards, 0, keyboards_count - 1, false);
	bubbleSort(drives, 0, drives_count - 1, true);

	int max = -1;
	for (int i = 0, j = 0; i < keyboards_count; i++) {
		for (; j < drives_count; j++) {
			int sum = keyboards[i] + drives[j];
			if (sum > b)
				break;
			else if (sum == b)
			    return sum;
			else if (sum > max)
				max = sum;
		}
	}
	return max;
}

int main() {
	int keyboards[] = {50, 60, 40};
	int drives[] = {3, 8, 5};

	printf("%d", getMoneySpent(3, keyboards, 3, drives, 60));
	return 0;
}
