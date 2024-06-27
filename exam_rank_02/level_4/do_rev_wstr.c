/*
Assignment name  : rev_wstr
Expected files   : rev_wstr.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string as a parameter, and prints its words in
reverse order.

A "word" is a part of the string bounded by spaces and/or tabs, or the
begin/end of the string.

If the number of parameters is different from 1, the program will display
'\n'.

In the parameters that are going to be tested, there won't be any "additional"
spaces (meaning that there won't be additionnal spaces at the beginning or at
the end of the string, and words will always be separated by exactly one space).

Examples:

$> ./rev_wstr "You hate people! But I love gatherings. Isn't it ironic?" | cat -e
ironic? it Isn't gatherings. love I But people! hate You$
$>./rev_wstr "abcdefghijklm"
abcdefghijklm
$> ./rev_wstr "Wingardium Leviosa" | cat -e
Leviosa Wingardium$
$> ./rev_wstr | cat -e
$
$>
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

bool	ws(char c)
{
	return (c == ' ' || c == '\0' || (c >= 9 && c <= 13));
}

int		ft_strlen(char *s)
{
	char	*start = s;
	
	while (*s++)
		;
	return (s - start - 1);
}

void	rev_wstr(char *s)
{
	int		len = ft_strlen(s); //Store the length of the string
	int		end; //Store the index of the last character of a word
	int		start; //Store the index of the first character of a word
	int		flag; //Store the index of the `start`. This is needed to keep track of the final word, to not print the " " afterward, if `start` is `0`

	while (len >= 0) //Iterate through the string from the end to the start of the string
	{
		while (len >= 0 && ws(s[len])) //Skip spaces/tabs and the \0 from the end of the string
			len--;

		end = len; //Save the end index of the current word
		while (len >= 0 && !ws(s[len])) //Move to the beginning of the current word
			len--;

		start = len + 1; //Initialize the start index for printing characters from the current word. `len + 1` because we did `len--` earlier to check for a space
		flag = start; //Keep track of the completion of a word. `0` implies the end of a string
		while (start <= end) //Loop until the end of the current word, as long as start is lesser or equal to end
		{
			write(1, &s[start], 1); //Write thr current character
			start++;
		}
		if (flag) //If there are more words to print
			write(1, " ", 1);
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		rev_wstr(argv[1]);
	write(1, "\n", 1);
	return (0);
}