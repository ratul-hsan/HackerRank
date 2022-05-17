#include <stdio.h>

#define peoblemUrl "https://www.hackerrank.com/challenges/mars-exploration"

int marsExploration(char* s) {
    int altered = 0;
    char sos[] = "SOS";
    
    for(int i = 0; s[i] != '\0'; i++)
        if (s[i] != sos[i % 3])
            altered++;
    return altered;
}

int main(int argc, char *argv[]) {
	printf("%d", marsExploration("SOSSPSSQSSOR"));
	return 0;
}