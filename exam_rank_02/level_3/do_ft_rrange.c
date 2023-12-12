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
	int		len = abs(start - end) + 1; //Store absoloute value, incase `end` is a negative value
	int		*array = (int *)malloc(len * sizeof(int)); //Allocate memory 
	int 	*tmp = array; //Used to iterate through the array whil preserving pointer to begining of `array`

	if (!array) //Check if allocation successfull
		return (NULL);
	if (start <= end) //Check if the range increases from `start`
	{
		while (len-- > 0)
			*tmp++ = end--; //Assign to `tmp`, `end` and increasing `end` value
	}
	else //If the range decreases from `start`
	{
		while (len-- > 0)
			*tmp++ = end++; //Assign to `tmp`, `end` and decreasing `end` value
	}
	return (array); //Return the pointer to the begining of the array
}

/*
#include <stdio.h>

int	main(void)
{
	int		*array;
	size_t	len; 

	array = ft_rrange(0, -3);
	if (array)
	{
		len = 4;
		while (len-- > 0)
			printf("%d\n", *array++);
	}
	return (0);
}*/