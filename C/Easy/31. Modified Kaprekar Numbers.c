#include <stdio.h>
#include <math.h>

#define problemUrl "https://www.hackerrank.com/challenges/kaprekar-numbers/problem?isFullScreen=false"

void kaprekarNumbers(int p, int q) {
	int invalidRange = 1;

	for (int current = p; current <= q; current++) {
		long long
			square = (long long) current * current,
			digits = floor(log10(current)) + 1,
			divisor = pow(10, digits),
			left = square / divisor,
			right = square % divisor;

		if (left + right == current) {
			invalidRange = 0;
			printf("%u ", current);
		}
	}

	if (invalidRange)
		printf("INVALID RANGE");
}

int main(int argc, char *argv[]) {
	kaprekarNumbers(1, 99999);
	return 0;
}