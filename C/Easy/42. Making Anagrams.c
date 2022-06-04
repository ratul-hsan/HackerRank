#include <stdio.h>
#include <stdlib.h>

#define problemUrl "https://www.hackerrank.com/challenges/making-anagrams"

int makingAnagrams(char *s1, char *s2) {
    int totalDeletions = 0,
        chars1[26] = {0}, chars2[26] = {0};
    
    for (int i = 0; s1[i] != '\0'; i++)
        chars1[s1[i] - 'a']++;
    for (int i = 0; s2[i] != '\0'; i++)
        chars2[s2[i] - 'a']++;
        
    for (int i = 0; i < 26; i++)
        totalDeletions += abs(chars1[i] - chars2[i]);
    return totalDeletions;
}

int main(int argc, char *argv[]) {
	printf("%d", makingAnagrams("abc", "abcc"));
	return 0;
}