#include <stdio.h>

#define peoblemUrl "https://www.hackerrank.com/challenges/angry-professor"

char* angryProfessor(int k, int a_count, int* a) {
	int attendance = 0;
	
	for (int i = 0; i < a_count; i++)
		if (a[i] <= 0)
			attendance++;

	if (attendance < k)
		return "YES";
	else
		return "NO";
}

int main(int argc, char *argv[]) {
	int k = 4;
	int array[] = {-2, -1, 0, 1, 2};
	int length = sizeof(array) / sizeof(array[0]);
	
	printf("%s", angryProfessor(k, length, array));
	return 0;
}