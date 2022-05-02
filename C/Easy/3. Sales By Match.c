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

#define problemUrl "https://www.hackerrank.com/challenges/sock-merchant"

typedef struct {
	int value;
} node;
node* map;

bool containsKey(int key) {
	return !(map[key].value == 0);
}

void put(int key, int value) {
	map[key].value = value;
}

int sockMerchant(int n, int ar_count, int *ar) {
	int pairs = 0;
    map = (node*) malloc(101*sizeof(node));
    
	for (int i = 0; i < n; i++) {
		if (containsKey(ar[i])) {
		    pairs++;
		    put(ar[i], 0);
		} else
		    put(ar[i], 1);
	}
	free(map);
	return pairs;
}

int main() {
	int socks[] = {1, 1, 3, 1, 2, 1, 3, 3, 3, 3};
	printf("%d", sockMerchant(10, 10, socks));
	return 0;
}