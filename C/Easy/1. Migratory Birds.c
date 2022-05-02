#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define problemUrl "https://www.hackerrank.com/challenges/migratory-birds"
 
// We will create a bird structure to simplify the code
struct bird {
	int type;
	int count;
};

// This solution returns output in O(n) time complexity
int migratoryBirds(int arr_count, int* arr) {
	// We will make an array of bird structure with length 5
	// Because it was specified in the problem's description that only 5 types of bird will be given as input
	struct bird* birds = (struct bird*)malloc(5*sizeof(struct bird));
	struct bird highestSeen = {}; // Here initialization is necessary to allocate a space for our variable
	// We will run a loop to initialize all the bird structures in our array
	for (int i=0; i<arr_count; i++) {
		// Array is indexed from 0 but bird types are indexed from 1. Thus we will substract 1 from the current bird type
        // so that we can save its info in correct location in our array
		int index = arr[i]-1;
		birds[index].type = arr[i];
		birds[index].count++;
	}
	// Now we will run a loop again to find that bird which fullfills all of our demands
	for (int i=0; i<5; i++) {
		struct bird current = birds[i];
		if (highestSeen.count < current.count)
		    highestSeen = current;
		else if (highestSeen.count == current.count)
		    if (highestSeen.type > current.type)
		        highestSeen = current;
	}
	return highestSeen.type;
}

int main() {
	// In this array 3 is available for 5 times which is the highest number
	int array_one[] = {3, 2, 2, 3, 3, 2, 3, 3, 4, 5};
	printf("Output of array_one is %d\n", migratoryBirds(10, array_one));
	
	// In this array 2 & 1 is available for 2 times but 1 < 2 so the output should be 1 
	int array_two[] = {2, 5, 1, 1, 3, 2, 4};
	printf ("Output of array_two is %d\n", migratoryBirds(7, array_two));
	
	return 0;
}