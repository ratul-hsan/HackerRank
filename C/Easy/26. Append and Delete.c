#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define problemUrl "https://www.hackerrank.com/challenges/append-and-delete"

void printString(char *result){
	while (*result != '\0') {
		printf("%c", *result++);
	}
	printf("\n");
}

void printInt(int i) {
	printf("%d\n", i);
}

int min(int a, int b) {
	return a > b ? a : b;
}

int len(char *str) {
	int length = 0;
	
	while (*str != '\0')
		length++, *str++;
	return length;
}

char *appendAndDelete(char *s, char *t, int k) {
	int s_length = len(s),
		t_length = len(t),
		commonLength = 0;

	for (int i = 0; i < min(s_length, t_length); i++) {
		if (s[i] == t[i])
			commonLength++;
		else
			break;
	}
	printInt(s_length + t_length - 2 * commonLength);
	// Case A
	if ((s_length + t_length - 2 * commonLength) > k)
		return "No";
	//CASE B
	else if ((s_length + t_length - 2 * commonLength) % 2 == k % 2)
		return "Yes";
	//CASE C
	else if ((s_length + t_length - k) < 0)
		return "Yes";
	return "No";
}

int main(int argc, char *argv[]) {
	char s[] = "rank"; // 4
	char g[] = "rough"; // 5
	char *result = appendAndDelete(s, g, 7);

	printString(result);
	return 0;
}