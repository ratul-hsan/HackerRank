#include <stdio.h>

#define problemUrl "https://www.hackerrank.com/challenges/designer-pdf-viewer"

int positionOf(char alphabet) {
	// Returns the 0 based index of the given alphabet from 26 alphabets in English Dictionary
	// The trick is to see the difference between the ascii value of first alphabet and the given alphabet
	return (alphabet + 0) - ('a' + 0);
}

int designerPdfViewer(int h_count, int* h, char* word) {
	int max = h[positionOf(*word)], length = 0;
	
	while (*word++ != '\0') {
		if (h[positionOf(*word)] > max)
			max = h[positionOf(*word)];
		length++;
	}
	return length * max;
}

int main(int argc, char *argv[]) {
	char word[] = "zaba";
	int array[] = {1, 3, 1, 3, 1, 4, 1, 3, 2, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 7};
	int length = sizeof(array) / sizeof(array[0]);
	
	printf("%d", designerPdfViewer(length, array, word));
	return 0;
}