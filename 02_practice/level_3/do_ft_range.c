/*
Assignment name  : ft_range
Expected files   : ft_range.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int	 *ft_range(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at start and end at end (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 1, 2 and 3.
- With (-1, 2) you will return an array containing -1, 0, 1 and 2.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing 0, -1, -2 and -3.
*/ 

#include <stdlib.h>

int	 *ft_range(int start, int end) {
	int len = abs(end - start) + 1;
	int *arr = (int *)malloc(len * sizeof(int));
	int *tmp = arr;

	if (start > end) {
		while (len-- > 0)
			*tmp++ = start--;
	}
	else if (start < end) {
		while (len-- > 0)
			*tmp++ = start++;
	}
	return (arr);
}

#include <stdio.h>

int main() {
	int *arr = ft_range(-6, -3);
	int len = 4;

	while (len-- > 0) {
		printf("%d\n", *arr++);
	}
	return (0);
}

/*
abs()
*/