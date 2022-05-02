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

#define problemUrl "https://www.hackerrank.com/challenges/day-of-the-programmer"

//According to Russia
int isLeapYear(int year){
	if (year%4==0||year%400==0){
		if (year > 1917){
			if(year%100!=0)
			    return 1;
		}
		else{
			return 1;
		}
    }
	return 0;
}

char* fillArray(int year, int leapYear){
	char* arr = (char*) calloc(10, sizeof(char));
	// Day
	arr[0]='1';
	if(leapYear)
		arr[1]='2';
	else
		arr[1]='3';
	arr[2]='.';
	//Month
	arr[3]='0';
	arr[4]='9';
	arr[5]='.';
	//Year
	for(int i=9;i>5;i--){
		char s = year%10+'0';
		arr[i]=s;
		year/=10;
	}
	return arr;
}

char* fill1918(){
	char* arr = (char*) calloc(10, sizeof(char));
	int year = 1918;
	//Day
	arr[0]='2';
	arr[1]='6';
	arr[2]='.';
	//Month
	arr[3]='0';
	arr[4]='9';
	arr[5]='.';
	//Year
	for(int i=9;i>5;i--){
		char s = year%10+'0';
		arr[i]=s;
		year/=10;
	}
	return arr;
}

char* dayOfProgrammer(int year){
	if(year!=1918)
	    return fillArray(year, isLeapYear(year));
	else
	    return fill1918();
}

int main(int argc, char *argv[])
{
	puts(dayOfProgrammer(2016));
	return 0;
}