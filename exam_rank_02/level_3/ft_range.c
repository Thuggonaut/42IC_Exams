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

#include <stdlib.h> //To call malloc()

int		*ft_range(int start, int end) //Define a function that returns an array of integers from start to end values
{
	int		len = abs(end - start) + 1; //Store absoloute value, incase `end` is a negative value. See #1
	int		*array = (int *)malloc(len * sizeof(int)); //Allocate memory 
	int		*tmp; //Used to iterate through the array whil preserving pointer to begining of `array`

	if (!array) //Check if allocation successfull
		return (NULL);
	tmp = array; //If sucessfull, assign the `tmp` pointer to point to `array`
	if (start <= end) //Check if the range increases from `start`
	{
		while (len-- > 0)
			*tmp++ = start++; //Assign to `tmp`, `start` and increasing `start` value
	}
	else //If the range decreases from `start`
	{
		while (len-- > 0)
			*tmp++ = start--; //Assign to `tmp`, `start` and decreasing `start` value
	}
	return (array); //Return the pointer to the begining of the array
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

/*
#1	The abs() function is a standard library function in C, defined in the <stdlib.h> header. 
		- It is used to calculate the absolute value of an integer. 
		- The absolute value of a number is its distance from zero on the number line, irrespective of its sign.
*/