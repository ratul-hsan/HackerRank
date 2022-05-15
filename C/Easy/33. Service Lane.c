#include <stdio.h>
#include <stdlib.h>

#define problemUrl "https://www.hackerrank.com/challenges/service-lane"

int min(int *array, int start, int end) {
    int min = array[start];
    
    while (start++ < end)
        if (array[start] < min)
            min = array[start];
    return min;
}

int* serviceLane(int *widths, int totalCases, int** cases) {
    int *result = malloc(totalCases * sizeof(int));

    for (int i = 0; i < totalCases; i++)
        result[i] = min(widths, cases[i][0], cases[i][1]);

    return result;
}

int main(int argc, char *argv[]) {
	int width[] = {2, 3, 1, 2, 3, 2, 3, 3};
	int cases[][2] = {{0, 3}, {4, 6}, {6, 7}, {3, 5}, {0, 7}};
	
	int *result = serviceLane(width, 5, cases);
	
	for (int i = 0; i < 5; i++)
	    printf("%d\n", result[i]);
	return 0;
}