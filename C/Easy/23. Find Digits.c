#include <stdio.h>

#define problemUrl "https://www.hackerrank.com/challenges/migratory-birds"
 
 int findDigits(int n) {
 	int result = 0;
 	
 	for (int clone = n; clone > 0; clone /= 10) {
 		int current = clone % 10;
 		if (current != 0)
 			result += n % current == 0 ? 1 : 0;
 	}
 	return result;
 }
 
int main(int argc, char *argv[]) {
	printf("%d", findDigits(10));
	return 0;
}