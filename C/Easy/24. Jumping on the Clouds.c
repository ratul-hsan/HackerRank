#include <stdio.h>

#define problemUrl "https://www.hackerrank.com/challenges/jumping-on-the-clouds-revisited "

int jumpingOnClouds(int c_count, int* c) {
	int totalMoves = 0, i = 0;
	
	while (i < c_count) {
		if (i + 2 < c_count && c[i + 2] != 1)
			i += 2;
		else
			i++;
		totalMoves++;
	}
	
	return totalMoves - 1;
}

int main(int argc, char *argv[]) {
	int c[] = {0, 0, 0, 0, 1, 0};
	int length = sizeof(c) / sizeof(c[0]);
	
	printf("\n%d", jumpingOnClouds(length,  c));
	return 0;
}