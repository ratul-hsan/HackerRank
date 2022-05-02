#include <stdio.h>

#define problemUrl "https://www.hackerrank.com/challenges/strange-advertising"

int viralAdvertising(int n) {
	int cumulatives, liked;
	cumulatives = liked = 2;
	
	for (int day = 2; day <= n; day++) {
		int shared = liked * 3;
		liked = shared / 2;
		cumulatives += liked;
	}
	return cumulatives;
}

int main(int argc, char *argv[]) {
	printf("%d", viralAdvertising(5));
	return 0;
}