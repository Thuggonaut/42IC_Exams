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

int	*ft_rrange(int start, int end)
{
	int		*array;
	int 	*current;
	size_t	len;

	len = (end - start + 1);
	array = (int *)malloc(len * sizeof(int));
	if (!array)
		return (NULL);
	current = array;
	while (len-- > 0)
		*current++ = end--;
	return (array);
}

/*
#include <stdio.h>

int	main(void)
{
	int		*array;
	size_t	len; 

	array = ft_rrange(-3, 10);
	if (array)
	{
		len = 14;
		while (len-- > 0)
			printf("%d\n", *array++);
	}
	return (0);
}*/