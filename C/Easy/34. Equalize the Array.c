#include <stdio.h>

#define problemUrl "https://www.hackerrank.com/challenges/equality-in-a-array"

int equalizeArray(int arr_count, int *arr) {
    int map[101], deletion = 0, singleElement = 1;
    
    for (int i = 0; i < arr_count; i++) {
            map[arr[i]] = 0;
        if (*arr != arr[i])
            singleElement = 0;
    }
    
    if (!singleElement) {
        for (int i = 0; i < arr_count; i++)
            map[arr[i]]++;
        
        deletion = arr_count - map[arr[0]];
        for (int i = 1; i < arr_count; i++) {
            int currentDeletion = arr_count - map[arr[i]];
            if (currentDeletion < deletion)
                deletion = currentDeletion;
        }
    }
    
    return deletion;
}

int main(int argc, char *argv[]) {
	int arr[] = {1, 2, 3, 4, 5, 6, 1};
	int length = sizeof(arr) / sizeof(*arr);
	printf("minimum deletion is %d", equalizeArray(length, arr));
	return 0;
}