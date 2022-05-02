#include <stdio.h>

#define problemUrl "https://www.hackerrank.com/challenges/printing-pattern-2"

void printArray(int size, int array[]) {
	for (int i = 0; i < size; i++)
	    printf("%d ", array[i]);
	printf("\n");
}

void makeLastHalf(int totalBlocks, int base, int size, int firstHalf[]) {
	int begin = base-1;
	int end = base+1;
	int current = firstHalf[begin]+1;
	
	firstHalf[base]++;
	printArray(totalBlocks, firstHalf);
	for (int i = 1; i < size-1; i++) {
		for (int j = begin; j <= end; j++)
			firstHalf[j] = current;
		current++, end++, begin--;
		printArray(totalBlocks, firstHalf);
	}
}

void makeFirstHalf(int size) {
	int totalBlocks = size+(size-1);
	int current = size;
	int begin = 0;
	int end = totalBlocks- 1;
	int integers[totalBlocks];
	
	for (int i = 0; i < totalBlocks; i++)
		integers[i] = size;
	
	printArray(totalBlocks, integers);
	for (int i = 0; i < size-1; i++) {
		for (int j = begin+1; j < end; j++)
			integers[j] = current-1;
		current--, begin++, end--;
		printArray(totalBlocks, integers);
	}
	makeLastHalf(totalBlocks, begin, size, integers);
}

void makeBox(int start) {
	if (start < 2) {
		printf("Invalid number %d", start);
		return;
	}
	makeFirstHalf(start);
}

int main(int argc, char *argv[]) {
	int boxStartPoint = 5;
	makeBox(boxStartPoint);
	return 0;
}