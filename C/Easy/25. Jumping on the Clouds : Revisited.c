#include <stdio.h>

#define problemUrl "https://www.hackerrank.com/challenges/jumping-on-the-clouds-revisited "

int jumpingOnClouds(int c_count, int* c, int k) {
	int totalCost = 0, index = 0;
	
	do {
		totalCost += c[index % c_count] == 1 ? 3 : 1;
		index = (index + k) % c_count;
	}
	while (index != 0);
	
	return 100 - totalCost;
}

int main(int argc, char *argv[]) {
	int c[] = {1,1,1,0,1,1,0,0,0,0};
	int length = sizeof(c) / sizeof(c[0]);
	
	printf("\n%d", jumpingOnClouds(length,  c, 3));
	return 0;
}