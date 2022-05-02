#include <stdio.h>
#include <stdlib.h>

#define problemUrl "https://www.hackerrank.com/challenges/circular-array-rotation"

/**** My approach - Time O(n), Space O(n) ****
int* circularArrayRotation(int a_count, int* a, int k, int queries_count, int* queries, int* result_count) {
	int* clone = malloc(a_count * sizeof(int));
	int* result = malloc((*result_count = queries_count) * sizeof(int));
	
	// We will divide rotation amount with array size and use the remainder as total rotation amount
	// Because after array_size amount of rotation array will be at the same state as 0th rotation
	k %= a_count;
	
	for (int i = 0; i < a_count; i++) {
		int index = i + k;
		if (index > a_count - 1)
			index -= a_count;
		clone[index] = a[i];
	}
	
	for (int i = 0; i < queries_count; i++)
		result[i] = clone[queries[i]];
	free(clone);
	return result;
}
******/

/*** Better approach - Time O(n), Space O(1) ***
void reverse(int* arr, int low, int high) {
	while (low < high) {
		int temp = arr[high];
		arr[high] = arr[low], arr[low] = temp;
		low++, high--;
	}
}

int* circularArrayRotation(int a_count, int* a, int k, int queries_count, int* queries, int* result_count) {
	int* result = malloc((*result_count = queries_count) * sizeof(int));
	k %= a_count;
	
	reverse(a, 0, a_count - k - 1);
	reverse(a, a_count - k, a_count - 1);
	reverse(a, 0, a_count - 1);
	
	for (int i = 0; i < queries_count; i++)
		result[i] = a[queries[i]];
	return result;
}
*****/

/*** My Brother's Best Approach - Time O(queries), Space O(1) ****/
int* circularArrayRotation(int a_count, int* a, int k, int queries_count, int* queries, int* result_count) {
	int* result = malloc((*result_count = queries_count) * sizeof(int));
	k %= a_count;
	int head = k == 0 ? 0 : a_count - k;
	
	for (int i = 0; i < queries_count; i++) {
		int position = (head + queries[i]) % a_count;
		result[i] = a[position];
	}
	return result;
}

int main(int argc, char *argv[]) {
	int result_count;
	int k = 4;
	int a[] = {7, 1, 3, 5, 2};
	int queries[] = {3, 4};
	int q_length = sizeof(queries) / sizeof(queries[0]);
	int a_length = sizeof(a) / sizeof(a[0]);
	
	int* result = circularArrayRotation(a_length, a, k, q_length, queries, &result_count);
	for (int i = 0; i < result_count; i++)
		fprintf(stdout, "%d\n", result[i]);
	return 0;
}