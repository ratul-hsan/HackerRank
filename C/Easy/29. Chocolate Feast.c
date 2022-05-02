#include <stdio.h>

#define problemUrl "https://www.hackerrank.com/challenges/chocolate-feast"

// n = budget
// c = chocolate price
// m = total wrappers amount for 1 chocolate
int chocolateFeast(int n, int c, int m) {
	int totalBars, wrappers, w_bars = 0;
	totalBars = wrappers = n / c;
	
	while (wrappers >= m) {
		totalBars += w_bars = wrappers / m;
		wrappers = (wrappers % m) + w_bars;
	}
	return totalBars;
}

int main(int argc, char *argv[]) {
	printf("%d", chocolateFeast(43203, 60, 5));
	return 0;
}