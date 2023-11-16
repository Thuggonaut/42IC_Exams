/*
Assignment name  : epur_str
Expected files   : epur_str.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string, and displays this string with exactly one
space between words, with no spaces or tabs either at the beginning or the end,
followed by a \n.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

If the number of arguments is not 1, or if there are no words to display, the
program displays \n.

Example:

$> ./epur_str "See? It's easy to print the same thing" | cat -e
See? It's easy to print the same thing$
$> ./epur_str " this        time it      will     be    more complex  . " | cat -e
this time it will be more complex .$
$> ./epur_str "No S*** Sherlock..." "nAw S*** ShErLaWQ..." | cat -e
$
$> ./epur_str "" | cat -e
$
$>
*/

#include <unistd.h> //To call write()

void    epur_str(char *s) //Define a function that takes in a string, writes the words contained in the string with one space between them. Returns void because it performs an operation and does not return a value
{
	if (*s == ' ' || *s == '\t') //Check for initial whitespace
		s++; //Skip if so
	while (*s) //Loop until the end of the string is reached
	{
		if (*s != ' ' && *s != '\t') //Check if the current character is not a whitespace
		{
			write(1, s, 1); //Print the character
				if (*(s + 2) != '\0' && (*(s + 1) == ' ' || *(s + 1) == '\t')) //Check if the last character if the string is not a whitespace, and if the next character is a whitespace, implying the end of a word
					write(1, " ", 1); //Print a space
		}
		s++; //Move to the next character for processing
	}
}

int main(int argc, char **argv) //`argv` is a pointer to an array of strings. By using a double pointer `char **argv`, the program can access and retrieve each individual argument as a null-terminated string
{
	if (argc == 2) //Perform operations only if argc is `two`, meaning there is only `one` argument in addition to the program name 
		epur_str(argv[1]);
	write(1, "\n", 1);
	return (0);
}