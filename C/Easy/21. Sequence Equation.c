#include <stdio.h>
#include <stdlib.h>

#define problemUrl "https://www.hackerrank.com/challenges/permutation-equation"

int* map = NULL;

int indexOf(int item) {
	return map[item];
}

int* permutationEquation(int p_count, int* p, int* result_count) {
	int* result = malloc((*result_count = p_count) * sizeof(int));
	map = malloc(51 * sizeof(int));
	
	for (int i = 0; i < p_count; i++) {
		map[p[i]] = i;
	}
	
	for (int x = 1; x <= p_count; x++) {
		int x_index = indexOf(x) + 1;
		int y_index = indexOf(x_index) + 1;
		result[x - 1] = y_index;
	}
	return result;
}

int main(int argc, char *argv[]) {
	int result_count;
	int p[] = {5, 2,1,3,4};
	int length = sizeof(p) / sizeof(p[0]);
	
	int* result = permutationEquation(length, p, &result_count);
	for (int i = 0; i < result_count; i++)
		fprintf(stdout, "%d\n", result[i]);
	return 0;
}