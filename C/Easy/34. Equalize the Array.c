#include <stdio.h>

int equalizeArray(int arr_count, int *arr) {
    int map[100], deletion;
    
    for (int i = 0; i < arr_count; i++) {
        int index = arr[i];
        if (map[index] < 0 || map[index] > arr_count)
            map[index] = 1;
        else
            map[index]++;
        deletion = arr_count - map[index];
    }
    
    return deletion;
}


int main(int argc, char *argv[]) {
	int arr[] = {3, 3, 2, 1, 3};
	int length = sizeof(arr) / sizeof(*arr);
	printf("minimum deletion is %d", equalizeArray(length, arr));
	return 0;
}