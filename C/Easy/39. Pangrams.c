#include <stdio.h>

#define problemUrl "https://www.hackerrank.com/challenges/pangrams"

int getIndexInAlphabets(char input) {
	if (input > 64 && input < 91)
		return input - 65;
	else if (input > 96 && input < 123)
		return input - 97;
	return -1;
}

char* pangrams(char* s) {
    int alphabet[26] = {00000000000000000000000000};
    
    for (int i = 0; s[i] != '\0'; s++) {
        if (s[i] == ' ') continue;
        int index = getIndexInAlphabets(s[i]);
        alphabet[index]++;
    }
    
    for (int i = 0; i < 26; i++)
        if (alphabet[i] == 0)
            return "not pangram";
    return "pangram";
}

int main(int argc, char *argv[]) {
	printf("%s", pangrams("abcd efghi jklmno pqrstuv wxyz"));
	return 0;
}