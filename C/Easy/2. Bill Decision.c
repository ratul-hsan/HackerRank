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

#define problemUrl "https://www.hackerrank.com/challenges/bon-appetit"

void bonAppetit(int bill_count, int *bill, int k, int b) {
	int sum = 0;
	
	bill[k] = 0;
	for (int i = 0; i < bill_count; i++)
		sum += bill[i];
	if (b == sum/2)
	    printf("Bon Appetit");
	else
	    printf("%d", abs(sum/2 - b));
}

int main() {
	int bill[] = {3, 10, 2, 9};
	bonAppetit(4, bill, 1, 12);
	return 0;
}