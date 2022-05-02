#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define problemUrl "https://www.hackerrank.com/challenges/cats-and-a-mouse"

char* catAndMouse(int catA, int catB, int mouse) {
	int diff1 = abs(catA - mouse);
	int diff2 = abs(catB - mouse);
	
	if (diff1 > diff2)
	    return "Cat B";
	if (diff2 > diff1)
	    return "Cat A";
	return "Mouse C";
}

int main() {
	printf("%s", catAndMouse(1, 3, 2));
	return 0;
}
