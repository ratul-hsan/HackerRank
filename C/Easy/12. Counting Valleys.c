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

#define problemUrl "https://www.hackerrank.com/challenges/counting-valleys"

int countingValleys(int steps, char *path) {
	int altitude = 0, valley = 0;

	for (int i=0; i<steps; i++) {
		if (path[i] == 'D')
			altitude--;
		else if (path[i] == 'U')
		    if (++altitude == 0)
	    	    valley++;
	}
	return valley;
}

int main() {
	char path[] = "UDDDUDUU";
	fprintf(stdout, "%d", countingValleys(8, path));
	fclose(stdout);
	return 0;
}