#include <stdio.h>

#define problemUrl "https://www.hackerrank.com/challenges/hackerrank-in-a-string"

char *array = NULL;

int find(char item, int start) {
    if (start == -1)
        return start;
    for (int i = start; array[i] != '\0'; i++)
        if (array[i] == item)
            return i + 1;
    return -1;
}

char* hackerrankInString(char* s) {
    array = s;
    if (find('k',
        find('n',
        find('a', 
        find('r',
        find('r',
        find('e',
        find('k',
        find('c',
        find('a',
        find('h', 0)))))))))) != -1)
        return "YES";
    else
        return "NO";
}

int main(int argc, char *argv[]) {
	printf("%s", hackerrankInString("hackerank"));
	return 0;
}