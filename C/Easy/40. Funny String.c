#include <stdio.h>
#include <stdlib.h>

#define problemUrl "https://www.hackerrank.com/challenges/funny-string"

char* funnyString(char* s) {
    int size;
    for (size = 0; s[size] != '\0'; size++);
    
    for (int i = 0, k = size - 1; i < size && k > 0; i++, k--) {
        int a = abs(s[i] - s[i + 1]);
        int b = abs(s[k] - s[k - 1]);
        
        if (a != b)
            return "Not Funny";
    }
    return "Funny";
}

int main(int argc, char *argv[]) {
	printf("%s", funnyString("bcxz"));
	return 0;
}