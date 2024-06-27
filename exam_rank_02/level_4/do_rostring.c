/*
Assignment name  : rostring
Expected files   : rostring.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string and displays this string after rotating it
one word to the left.

Thus, the first word becomes the last, and others stay in the same order.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

Words will be separated by only one space in the output.

If there's less than one argument, the program displays \n.

Example:

$>./rostring "abc   " | cat -e
abc$
$>
$>./rostring "Que la	  lumiere soit et la lumiere fut"
la lumiere soit et la lumiere fut Que
$>
$>./rostring "	 AkjhZ zLKIJz , 23y"
zLKIJz , 23y AkjhZ
$>
$>./rostring "first" "2" "11000000"
first
$>
$>./rostring | cat -e
$
$>
*/

#include <unistd.h>
#include <stdlib.h> 

void	rostring(char *str)
{
	int		len = 0; //To store length of first word
	char	*first; //Extract and duplicate the first word
	char	*temp; //Needed to preserve pointer to the begining of first word for printing
	char	*s = str; //Needed to preserve the original pointers where needed. Without this, original string will be skipped and non accessible. Consider `s` is used to iterate, and `str` is for when we need to access its values 

	//Skip leading whitespace, for both original and secondary pointers - this is like, "discarding" what we dont need
	while (*s == ' ' || *s == '\t')
	{
		s++; 
		str++;
	}
	//Check for printable characters, which will be the first word
	while (*s && (*s != ' ' && *s != '\t'))
	{
		len++; //Track the length for malloc
		s++; //Skip as we won't need, because we have `str` for duplicating the first word later on
	}
	//Extract the first word and cpoy
	first = (char *)malloc((len + 1) * sizeof(char)); 
	temp = first; 
	while (len > 0) //Caution, `len-- > 0` will be incorrect
	{
		*temp++ = *str++; //Copy the first word
		len--;
	}
	*temp = '\0'; //Proper null terminate
	//Iterate through the remaining of the string, and print the rest. Caution, the order of executions is important
	while (*s)
	{
		//Check for the end of a word, where we will print exactly 1 space. Don't forget the word at the end of the string
		if ((*s != ' ' && *s != '\t') && (*(s + 1) == ' ' || *(s + 1) == '\t' || (*(s + 1) == '\0')))
		{
			write(1, s, 1);
			write(1, " ", 1);
		}
		else if (*s != ' ' && *s != '\t') //If not the end of a word, print the character
			write(1, s, 1);
		s++; //Incrementing when conditions aren't met, also means we're skipping whitespaces
	}
	//Print the first word last
	while (*first)
		write(1, first++, 1);
}

int		main(int argc, char **argv)
{
	if (argc > 1)
		rostring(argv[1]);
	write(1, "\n", 1);
	return (0);
}

/* 2nd attempt
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

bool ws(char c)
{
    return (c == ' ' || c == '\0' || (c >= 9 && c <= 13));
}

void ft(char *str)
{
        int             len = 0;
        char    *first;
        char    *temp;
        char    *s = str;

        while (ws(*s))
        {
                s++;
                str++;
        }
        while (*s && !ws(*s))
        {
                len++;
                s++;
        }
        first = (char *)malloc((len + 1) * sizeof(char));
        temp = first;
        while (len > 0)
        {
                *temp++ = *str++;
                len--;
        }
        *temp = '\0';
        while (*s)
        {
                if (!ws(*s) && ws(*(s + 1)))
                {
                        write(1, s, 1);
                        write(1, " ", 1);
                }
                else if (!ws(*s))
                        write(1, s, 1);
                s++;
        }
        while (*first)
                write(1, first++, 1);
}

int main(int ac, char **av)
{
    if (ac >= 2)
        ft(av[1]);
        write(1, "0", 1);
    write(1, "\n", 1);
    return (0);
}
*/