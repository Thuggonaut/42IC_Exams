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

int		ft_strlen(char *s)
{
	char	*start = s;

	while (*s++)
		;
	return (s - start - 1);
}

/*void	rostring(char *s)
{
	char	*start;
	
	while (*s == ' ' || *s == '\t')
		s++;
	start = s; //start to point to the start of the first word
	while (*s != ' ' && *s != '\t' && *s != '\0') //Skip through the first word
		s++;
	write(1, s, ft_strlen(s)); //Write the remaining string
	write(1, " ", 1);
	write(1, start, s - start); //Write the first word last
}*/

void	rostring(char *s)
{
	char	*start;
	char	*end;
	
	while (*s == ' ' || *s == '\t')
		s++;

	start = s; //start to point to the start of the first word
	while (*s != ' ' && *s != '\t' && *s != '\0') //Skip through the first word
		s++;

	end = s - 1; //end to point to the end of the first word. `s - 1` because previously `s++` skipped the end
	while (*s) //Write the remaining string, excluding spaces before '\0'
	{
		if (*s != ' ' && *s != '\t') //If the current character is not a space, meaning we're inside a word
			write(1, s, 1);
		else if (*(s + 1) != ' ' && *(s + 1) != '\t' && *(s + 1) != '\0') //If the current character is a space but the next is not, meaning there's another word
			write(1, " ", 1);
		s++;
	}
	write(1, " ", 1);
	write(1, start, end - start + 1); //Write the first word
}

int		main(int argc, char **argv)
{
	if (argc >= 2)
		rostring(argv[1]);
	write(1, "\n", 1);
	return (0);
}