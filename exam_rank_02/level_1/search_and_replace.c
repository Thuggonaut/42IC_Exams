/*
Assignment name  : search_and_replace
Expected files   : search_and_replace.c
Allowed functions: write, exit
--------------------------------------------------------------------------------

Write a program called search_and_replace that takes 3 arguments, the first
arguments is a string in which to replace a letter (2nd argument) by
another one (3rd argument).

If the number of arguments is not 3, just display a newline.

If the second argument is not contained in the first one (the string)
then the program simply rewrites the string followed by a newline.

Examples:
$>./search_and_replace "Papache est un sabre" "a" "o"
Popoche est un sobre
$>./search_and_replace "zaz" "art" "zul" | cat -e
$
$>./search_and_replace "zaz" "r" "u" | cat -e
zaz$
$>./search_and_replace "jacob" "a" "b" "c" "e" | cat -e
$
$>./search_and_replace "ZoZ eT Dovid oiME le METol." "o" "a" | cat -e
ZaZ eT David aiME le METal.$
$>./search_and_replace c| cat -e
eNcOre Un ExEmPle Pas Facile a Ecrire $
*/

#include <unistd.h> //To call write()

void	search_and_replace(char *s, char search, char replace) //Define a function takes three arguments: a string, a substring, and a replacement substring. The function searches for all occurrences of the `search` character in `str` and replaces them with the `replace` character
{								   
	while (*s) //Loop until the end of the first string is reached
	{
		if (*s == search) //Search for the letter from the 2nd argument in the first string. When found, asign this letter to the current character of the string
			*s = replace; //Replace the letter from the 2nd argument, with the letter from the third argument
		write(1, s++, 1); //Write the current character to the standard output before incrememnting to the nexrt
	}
}

int main(int argc, char **argv) //argv is a pointer to an array of strings. By using a double pointer char **argv, the program can access and retrieve each individual argument as a null-terminated string
{
	if (argc == 4 && !argv[2][1] & !argv[3][1]) //Perform operations only if argc is four, meaning there are exactly three arguments in addition to the program name && if the 2nd and 3rd arguments are single characters
		search_and_replace(argv[1], argv[2][0], argv[3][0]);	   //e.g `argv[2][1]` gets evaluated first, before the `!` is applied, and in effect, negates or 'flips' the result. If `argv[2]` is a single character, then `argv[2][1]` will be '0' representing '\0'. The result of `argv[2][1]` then, is '0', or 'false' (Similarly, the expression `while (*str)` is 'true' until the '\0' is reached). The `!` is then applied, making `argv[2][1]` from 'false' to 'true', and from '0' to '1'. The bitwise operation `&` means, both sides of `&` must equate to '1', for it to be 'true', else it will be 'false', deeming the while loop conditions not met
	write(1, "\n", 1);
	return (0);
}
