/*
Assignment name  : hidenp
Expected files   : hidenp.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program named hidenp that takes two strings and displays 1
followed by a newline if the first string is hidden in the second one,
otherwise displays 0 followed by a newline.

Let s1 and s2 be strings. We say that s1 is hidden in s2 if it's possible to
find each character from s1 in s2, in the same order as they appear in s1.
Also, the empty string is hidden in any string.

If the number of parameters is not 2, the program displays a newline.

Examples :

$>./hidenp "fgex.;" "tyf34gdgf;'ektufjhgdgex.;.;rtjynur6" | cat -e
1$
$>./hidenp "abc" "2altrb53c.sse" | cat -e
1$
$>./hidenp "abc" "btarc" | cat -e
0$
$>./hidenp | cat -e
$
$>
*/

#include <unistd.h>

void	hidenp(char *s1, char *s2) 
{
	while (*s2) 
	{
		if (*s1 == *s2) 
		{
			s1++; // Move to the next character in s1
			if (*s1 == '\0') 
			{
				write(1, "1", 1); // If end of s1 is reached, all characters have been found in order
				return ;
			}
		}
		s2++; // Always move to the next character in s2
	}
	write(1, "0", 1); // If the loop ends, s1 is not fully found in s2 in order
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		hidenp(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}

/*
MY 2ND ATTEMPT WHICH I PREFER:

void	hidenp(char *s1, char *s2)
{
	int	 found = 0;

	while (*s1 && *s2)
	{
		if (*s1 == *s2)
		{
			found = 1;
			s1++;
			s2++;
		}
		else
		{
			found = 0;
			s2++;
		}
	}
	if (found == 1)
		write(1, "1", 1);
	else
		write(1, "0", 1);
}
*/