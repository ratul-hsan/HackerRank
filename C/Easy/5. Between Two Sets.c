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

#define problemUrl "https://www.hackerrank.com/challenges/between-two-sets"

int partition(int input[], int start, int end) {
	int temp = 0;
	int pivot = input[start];
	int i = start + 1;
	int j = end - 1;
	//Running a loop until i becomes greater than j
	do {
		//Searching for an element, greater than pivot
		while (input[i] < pivot)
			i++;
		//Searching for an element, lower than pivot
		while (input[j] > pivot)
			j--;
		if (i < j) {
			//Swaping i number element with j number element in order to partition
			temp = input[j];
			input[j] = input[i];
			input[i] = temp;
		}
	} while (i < j);
	//Swaping pivot with j number element of array
	temp = input[start];
	input[start] = input[j];
	input[j] = temp;
	return j;
}

void quickSort(int input[], int start, int end) {
	//Index of pivot after partitioning the array
	int partitionIndex = 0;
	if (start < end) {
		//This will divide the main array into two sub arrays
		partitionIndex = partition(input, start, end);
		//Sorting first sub array
		quickSort(input, start, partitionIndex - 1);
		//Sorting second sub array
		quickSort(input, partitionIndex + 1, end);
	}
}

//Greatest common divisor
int gcd(int a, int b) {
	if (a == 0)
		return b;
	return gcd(b % a, a);
}

int lcm(int len, int *arr) {
	int common = arr[0];
	for (int i = 1; i < len; i++) {
		common = (common /
				  gcd(common, arr[i])) *
				 arr[i];
	}
	return common;
}

int modifyTotalX(int len, int *a, int mVal, int lcm, int totalX) {
	if (mVal > a[0])
		return totalX;
	for (int i = 0; i < len; i++)
		if (a[i] % mVal != 0)
			return modifyTotalX(len, a, mVal + lcm, lcm, totalX);
	totalX += 1;
	return modifyTotalX(len, a, mVal + lcm, lcm, totalX);
}

int getTotalX(int a_count, int *a, int b_count, int *b) {
	int common = lcm(a_count, a);
	quickSort(b, 0, b_count);
	return modifyTotalX(b_count, b, common, common, 0);
}

int main(int argc, char *argv[]) {
	int a[] = {2, 6};
	int b[] = {24, 36};
	int total = getTotalX(2, a, 2, b);
	printf("TotalX is %d", total);
	return 0;
}