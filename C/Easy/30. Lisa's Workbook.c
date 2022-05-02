#include <stdio.h>

#define problemUrl "https://www.hackerrank.com/challenges/lisa-workbook"

// n = chapters
// k = problems per page
int workbook(int n, int k, int arr_count, int *arr) {
	int specials = 0, currentPage = 1;
	
	// Loop for chapters
	for (int chapter = 0; chapter < n; chapter++) {
		// Loop for problems
		for (int problem = 1; problem <= arr[chapter]; problem += k) {
			int lastProblem = problem + k - 1;
			if (lastProblem > arr[chapter])
				lastProblem = problem + (arr[chapter] - problem);
			
			if (problem <= currentPage && currentPage <= lastProblem)
				specials++;
			currentPage++;
		}
	}
	return specials;
}

int main(int argc, char *argv[]) {
	int arr[] = {4, 2, 6, 1, 10};
	int len =	sizeof(arr) / sizeof(arr[0]);
	
	printf("%d", workbook(5, 3, len, arr));
	return 0;
}