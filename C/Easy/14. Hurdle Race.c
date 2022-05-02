#include <stdio.h>

#define problemUrl "https://www.hackerrank.com/challenges/the-hurdle-race"

int hurdleRace(int k, int height_count, int* height) {
	int max = *height;
	
	for (int i = 1; i < height_count; i++)
		if (height[i] > max)
			max = height[i];
	return k >= max ? 0 : max - k;
}

int main(int argc, char *argv[]) {
	int initialPower = 5;
	int array[] = {5, 6, 3, 2, 7};
	int length = sizeof(array) / sizeof(array[0]);
	
	printf("%d", hurdleRace (initialPower, length, array));
	return 0;
}