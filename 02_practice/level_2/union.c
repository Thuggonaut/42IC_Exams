/*
Assignment name  : union
Expected files   : union.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in either one of the strings.

The display will be in the order characters appear in the command line, and
will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Example:

$>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
zpadintoqefwjy$
$>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6vewg4thras$
$>./union "rien" "cette phrase ne cache rien" | cat -e
rienct phas$
$>./union | cat -e
$
$>
$>./union "rien" | cat -e
$
$>
*/ 

#include <unistd.h>

void ft(char *s1, char *s2) {
	char *found[256] = {0};

	while (*s1) {
		if (!found[*s1]) {
			write(1, s1, 1);
			found[*s1]++;
		}
		s1++;
	}
	while (*s2) {
		if (!found[*s2]) {
			write(1, s2, 1);
			found[*s2]++;
		}
		s2++;
	}
}

int main(int ac, char **av)
{
	if (ac == 3)
		ft(av[1], av[2]);
	write(1, "\n", 1);
	return (0);
}