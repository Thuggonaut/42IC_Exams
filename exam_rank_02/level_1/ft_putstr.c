/*
Assignment name  : ft_putstr
Expected files   : ft_putstr.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a function that displays a string on the standard output.

The pointer passed to the function contains the address of the string's first
character.

Your function must be declared as follows:

void	ft_putstr(char *str);
*/

#include <unistd.h> //To call write()

void    ft_putstr(char *s) //Define a function that takes a pointer to a string. Type `void` because it performs an operation and does not return a value
{
    while (*s) //Loop until the end of the string is reached
    {
        write(1, s, 1); //Write the current character to the standard output
        s++; //Move to the next character for processing
    }
}
