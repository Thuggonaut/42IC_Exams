/*
Assignment name  : first_word
Expected files   : first_word.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays its first word, followed by a
newline.

A word is a section of string delimited by spaces/tabs or by the start/end of
the string.

If the number of parameters is not 1, or if there are no words, simply display
a newline.

Examples:

$> ./first_word "FOR PONY" | cat -e
FOR$
$> ./first_word "this	    ...    is sparta, then again, maybe    not" | cat -e
this$
$> ./first_word "   " | cat -e
$
$> ./first_word "a" "b" | cat -e
$
$> ./first_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$>
*/

#include <unistd.h> // To call write()

void	first_word(char *s) //Define a function that takes a pointer to a string. Type `void` because it performs an operation and does not return a value
{
	while ((*s == ' ') || (*s == '\t')) //Checks for a space character (ASCII '32'), or a tab (ASCII 9)
		s++;
	while (*s && (*s != ' ' && *s != '\t')) //Checks if current character is neither `space` or `tab`, and has not reached the end of the string
		write(1, s++, 1); //writes the current character to the standard output
}

int main(int argc, char **argv) //`argv` is a pointer to an array of strings. By using a `double pointer` `char **argv`, the program can access and retrieve each individual argument as a null-terminated string
{
	if (argc == 2) //Perform operations only if argc is `two`, meaning there is only `one` argument in addition to the program name 
		first_word(argv[1]);
	write(1, "\n", 1);
	return (0);
}
