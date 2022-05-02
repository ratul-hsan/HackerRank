#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define problemUrl "https://www.hackerrank.com/challenges/time-conversion"

char* timeConversion(char *s) {
	int hour = ((s[0] - '0') * 10) + (s[1] - '0');
	if (s[8] == 'P') {
		hour += 12;
		if (hour == 24) {
			s[0] = '1';
			s[1] = '2';
		}
		else {
			s[1] = hour % 10 + '0';
			s[0] = hour / 10 + '0';
		}
	}
	else {
		if (hour == 12)
			s[0] = s[1] = '0';
	}
	s[8] = s[9] = '\0';
	return s;
}

int main() {
	char time[] = "07:05:45PM";
	printf("%s", timeConversion(time));
	return 0;
}