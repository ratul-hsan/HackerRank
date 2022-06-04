#include <stdio.h>
#include <stdlib.h>

#define problemUrl "https://www.hackerrank.com/challenges/alternating-characters"

int alternatingCharacters(char* s) {
    int deletions, A, B;
    deletions = A = B = 0;
    
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == 'A') {
            if (B > 1)
                deletions += B - 1;
            A++, B = 0;
        } else {
            if (A > 1)
                deletions += A - 1;
            B++, A = 0;
        }
    }
    if (A > 1)
        deletions += A - 1;
    else if (B > 1)
         deletions += B - 1;
        
    return deletions;
}

int main(int argc, char *argv[]) {
	printf("%d", alternatingCharacters("BAB"));
	return 0;
}