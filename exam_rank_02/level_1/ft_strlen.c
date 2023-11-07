/*
Assignment name  : ft_strlen
Expected files   : ft_strlen.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that returns the length of a string.

Your function must be declared as follows:

int	ft_strlen(char *str);
*/

#include <stdlib.h> //That defines `size_t` variable type

size_t ft_strlen(const char *s) //Define a function that takes a pointer to a string, and returns its number of characters up to but not including the null character ('\0')
{
    const char *start; //Declare a pointer variable that will store a pointer pointing to the start of `s` 

    start = s; //Assign to `start` the pointer pointing to `s`
    while (*s++) //This while loop does not need to have any executions inside `{}` brackets. It will loop until the end of `s` is reached, and in each iteration it post-increments the pointer to the next character
        ;
    return (s - start - 1); //`s` is now pointing to the last index of `s`. The resulting length of `s` is calulated by subtracting the final position of `start` of the string (index `0`) from the position of `s`. The `-1` is to account for the extra increment for the `\0`
}

/*
#include <stdio.h>

int	main(void)
{
	char	*s;
	int		len;

	s = "123456";
	len = ft_strlen(s);
	printf("%d\n", len);
	return (0);
}
*/