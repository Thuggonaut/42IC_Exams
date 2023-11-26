/*
Assignment name  : last_word
Expected files   : last_word.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays its last word followed by a \n.

A word is a section of string delimited by spaces/tabs or by the start/end of
the string.

If the number of parameters is not 1, or there are no words, display a newline.

Example:

$> ./last_word "FOR PONY" | cat -e
PONY$
$> ./last_word "this		...	   is sparta, then again, maybe	not" | cat -e
not$
$> ./last_word "   " | cat -e
$
$> ./last_word "a" "b" | cat -e
$
$> ./last_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$>
*/

#include <unistd.h> //To call write()

void	last_word(char *s) //Define a function that takes a pointer to a string, and prints the last word of the string
{
	char	*word = s; //Initialized to point to the beginning of the input string

	while (*s) //Loop until the end of the string is reached
	{
		if ((*s == ' ' || *s == '\t') && (*(s + 1) != ' ' && *(s + 1) != '\t' && *(s + 1) != '\0')) //Check if the current character is a space/tab && the character following it is not
			word = s + 1; //Set the pointer to point to the last word so far
		s++;
	}
	while (*word && *word != ' ' && *word != '\t') //Loop to the end of the last word is reached
		write(1, word++, 1); //Print it
}

int main(int argc, char **argv) //`argv` is a pointer to an array of strings. By using a double pointer `char **argv`, the program can access and retrieve each individual argument as a null-terminated string
{
	if (argc == 2) //Perform operations only if argc is `two`, meaning there is only `one` argument in addition to the program name 
		last_word(argv[1]);
	write(1, "\n", 1);
	return (0);
}

/*
#1  Initializing `last_space` to `0` (null) is a way to represent an empty or uninitialized state for the pointer. 
		- This initialization is essential because, later in the code, the `if (last_space)` condition checks if `last_space` is not `null`, meaning that 
		  at least one `space` or `tab` character has been found in the input string.
		- By initializing `last_space` to `0`, we ensure that the condition in the second while loop will only execute if a `space` or `tab` character has 
		  been found. If no space or tab character is found in the string, the second loop will not execute, and the function will not print anything.
*/

