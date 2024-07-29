/*
Assignment name  : ft_rrange
Expected files   : ft_rrange.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_rrange(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at end and end at start (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 3, 2 and 1
- With (-1, 2) you will return an array containing 2, 1, 0 and -1.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing -3, -2, -1 and 0.

***SIMILAR TO ft_range.c BUT IN REVERSE***
*/ 

#include <stdlib.h>

int *ft_rrange(int start, int end) {
	int len = abs(end - start) + 1;
	int *arr = (int *)malloc(len * sizeof(int));
	int *tmp = arr;

	if (end >= start) {
		while (len-- > 0)
			*tmp++ = end--;
	}
	else if (end <= start) {
		while (len-- > 0)
			*tmp++ = end++;
	}
	return (arr);
}

#include <stdio.h>

int main() {
	int *arr = ft_rrange(0, -3);
	int len = 4;

	while (len-- > 0) {
		printf("%d\n", *arr++);
	}
	return (0);
}