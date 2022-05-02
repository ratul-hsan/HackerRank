#include <stdio.h>

#define problemUrl "https://www.hackerrank.com/challenges/beautiful-days-at-the-movies"

int reverse(int i) {
	int reversed = 0, clone = i;
	
	while (clone != 0) {
		reversed = reversed * 10 + clone % 10;
		clone /= 10;
	}
	return reversed;
}

int beautifulDays(int i, int j, int k) {
	int totalDays = 0;
	
	while (i <= j) {
		if ((i - reverse(i)) % k == 0)
			totalDays++;
		i++;
	}
	return totalDays;
}

int main(int argc, char *argv[]) {
	printf("%d", beautifulDays(20, 23, 6));
	return 0;
}