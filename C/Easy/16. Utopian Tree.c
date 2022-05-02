#include <stdio.h>

#define peoblemUrl "https://www.hackerrank.com/challenges/utopian-tree"

int utopianTree(int n) {
	int height = 1;
	
	for (int i = 1; i <= n; i++)
		if (i % 2 == 0)
			height++;
		else
			height *= 2;
	return height;
}

int main(int argc, char *argv[]) {
	printf("%d", utopianTree(1));
	return 0;
}