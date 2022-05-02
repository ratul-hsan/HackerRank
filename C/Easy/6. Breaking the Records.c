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

int* breakingRecords(int scores_count, int* scores, int* result_count) {
	int highestScore = scores[0], lowestScore = scores[0];
	int* result = (int*)calloc (*result_count = 2, sizeof(int));
	for (int i=1; i<scores_count; i++) {
		if (scores[i] > highestScore) {
		    result[0]++;
		    highestScore = scores[i];
		}
		else if (scores[i] < lowestScore) {
            result[1]++;
            lowestScore = scores[i];
		}
	}
	return result;
}

int main() {
	int* results = (int*) calloc(2, sizeof(int));
	int scores[] = {10, 5, 20, 20, 4, 5, 2, 25, 1}; 
	int* output = breakingRecords(9, scores, results);
	printf("%d %d", output[0], output[1]);
	return 0;
}