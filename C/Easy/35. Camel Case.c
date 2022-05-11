#include <stdio.h>

#define problemUrl "https://www.hackerrank.com/challenges/camelcase"

int camelcase(char *s) {
    int totalWords = 1;
    
    /* This solution also works
    while (*s++ != '\0')
        if (*s < 'a')
            totalWords++;
    */
    for (int i = 1; s[i] != '\0'; i++)
        if (s[i] < 'a')
            // It's an uppercase letter
            totalWords++;
    return totalWords;
}

int main(int argc, char *argv[]) {
	printf("%d", camelcase("helloH"));
	return 0;
}