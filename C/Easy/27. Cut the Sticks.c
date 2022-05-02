#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define problemUrl "https://www.hackerrank.com/challenges/cut-the-sticks"

void printArray(int size, int *arr) {
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void swap(int *x, int *y) {
	*y += *x;
	*x = *y - *x;
	*y = *y - *x;
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

int trim(int size, int *array, int value) {
	int modified = 0;
	
	for (int i = 0; i < size; i++) {
		if (array[i] == 0)
			continue;
		if (array[i] - value >= 0)
			array[i] -= value, modified++;
	}
	return modified;
}

int* cutTheSticks(int arr_count, int* arr, int* result_count) {
	int *result = malloc(arr_count * sizeof(int));
	*result_count = 0;
	bubbleSort(arr, 0, arr_count - 1, true);
	
	for (int i = 0; i < arr_count; i++) {
		if (arr[i] == 0)
			continue;
		result[*result_count] = trim(arr_count, arr, arr[i]);
		*result_count += 1;
	}
	return result;
}

int main(int argc, char *argv[]) {
	int result_count = 0;
	int arr[] = {5,4,4,2,2,8};
	int length = sizeof(arr) / sizeof(arr[0]);
	int *result = cutTheSticks(length, arr, &result_count);
	
	for (int i = 0; i < result_count; i++) {
		printf("%d\n", result[i]);
	}
	return 0;
}