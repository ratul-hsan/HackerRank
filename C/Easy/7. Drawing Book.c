#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>q
#include <stdlib.h>
#include <string.h>

#define problemUrl "https://www.hackerrank.com/challenges/drawing-book"

int pageCount(int n, int p){
	int startResult = abs(1-p);
	int endResult = abs(n-p);
	if(startResult>endResult){
	    //we should start from end
	    if(p%2==0)
	        return endResult;
	    return endResult-1;
	}
	else{
	    //we should start from front
	    if(p%2==0)
	        return startResult;
	    return startResult-1;
	}
}

int main(int argc, char *argv[]) {
	printf("%d\n", pageCount(5, 5));
	return 0;
}