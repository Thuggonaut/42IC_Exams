/*
Assignment name  : str_capitalizer
Expected files   : str_capitalizer.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes one or several strings and, for each argument,
capitalizes the first character of each word (If it's a letter, obviously),
puts the rest in lowercase, and displays the result on the standard output,
followed by a \n.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string. If a word only has one letter, it must be
capitalized.

If there are no arguments, the progam must display \n.

Example:

$> ./str_capitalizer | cat -e
$
$> ./str_capitalizer "a FiRSt LiTTlE TESt" | cat -e
A First Little Test$
$> ./str_capitalizer "__SecONd teST A LITtle BiT   Moar comPLEX" "   But... This iS not THAT COMPLEX" "	 Okay, this is the last 1239809147801 but not	the least	t" | cat -e
__second Test A Little Bit   Moar Complex$
   But... This Is Not That Complex$
	 Okay, This Is The Last 1239809147801 But Not	The Least	T$
$>
*/

//Second attempt
#include <unistd.h>
#include <stdbool.h>

bool	ws(char c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

void *str_capitalizer(char *s)
{
	if (*s >= 'a' && *s <= 'z')
		*s -= 32;
	write(1, s++, 1);

	while (*s)
	{
		if ((ws(*(s - 1))) && ((*s >= 'a' && *s <= 'z') || *(s + 1) == '\0'))
			*s -= 32;
		else if ((!ws(*(s - 1))) && (*s >= 'A' && *s <= 'Z'))
			*s += 32;
		write(1, s++, 1);
	}
}

int	 main(int ac, char **av)
{
	if (ac >= 2)
	{
		int i = 0;

		while (++i < ac)
		{
			str_capitalizer(av[i]);
			write(1, "\n", 1);
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}

/*#include <unistd.h> //To call write()

void	str_capitalizer(char *s) //Define a function that will capitalise the first letter of every word in a string
{
	if (*s >= 'a' && *s <= 'z') //Check if the first character is a LC
		*s -= 32; //If so, replace with UC
	write(1, s++, 1); //Print it. (If already UC, print it as is)
	while (*s) //Loop until the end of the string is reached
	{
		if ((*s >= 'a' && *s <= 'z') && (*(s - 1) == ' ' || *(s - 1) == '\t')) //Check if the first letter of a word is LC
			*s -= 32; //If so, replace with UC
		else if ((*s >= 'A' && *s <= 'Z') && (*(s - 1) == ' ' || *(s - 1) == '\t')) //Check if the first letter of a word is already UC
			; //If so, move to the next execution
		else if ((*s >= 'A' && *s <= 'Z') && (*(s - 1) != ' ' || *(s - 1) != '\t')) //Check for UC letters within a word
			*s += 32; //If so, replace with a LC
		write(1, s++, 1); //Print the current character before moving to the next 
	}
	write(1, "\n", 1);
}

int	 main(int argc, char **argv) //Define a program that will return for each argument, a string with each first letter of a word capitalised
{
	int	 i = 1; //To store the index of the argument array. [0] would account for the executable name

	if (argc < 2) //Check if the argument is only one
		write(1, "\n", 1);
	while (argc >= 2) //Loop through all the command line arguments
	{
		str_capitalizer(argv[i]);
		argc--;
		i++;
	}
	return (0);
}*/