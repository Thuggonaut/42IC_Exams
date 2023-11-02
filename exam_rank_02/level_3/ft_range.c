/*
Assignment name  : ft_range
Expected files   : ft_range.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_range(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at start and end at end (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 1, 2 and 3.
- With (-1, 2) you will return an array containing -1, 0, 1 and 2.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing 0, -1, -2 and -3.
*/

#include <stdlib.h> //To call malloc()

int     *ft_range(int start, int end)
{
	size_t	len;
	int	*array;
	int	*current;

	len = (end - start + 1);
	array = (int *)malloc(len * sizeof(int));
	if (!array)
		return (NULL);
	current = array;
	while (len-- > 0)
		*current++ = start++;
	return (array);
}

/*
#include <stdio.h>

int main(void)
{
	int *array;
	size_t len;

	array = ft_range(-3, 10);
	if (array)
	{
		len = 14;
		while (len-- > 0)
			printf("%d\n", *array++);
	}
	return (0);
}
*/