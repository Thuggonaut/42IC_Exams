/*
Assignment name  : pgcd
Expected files   : pgcd.c
Allowed functions: printf, atoi, malloc, free
--------------------------------------------------------------------------------

Write a program that takes two strings representing two strictly positive
integers that fit in an int.

Display their highest common denominator followed by a newline (It's always a
strictly positive integer).

If the number of parameters is not 2, display a newline.

Examples:

$> ./pgcd 42 10 | cat -e
2$
$> ./pgcd 42 12 | cat -e
6$
$> ./pgcd 14 77 | cat -e
7$
$> ./pgcd 17 3 | cat -e
1$
$> ./pgcd | cat -e
$
*/ 

/*
swap with *tmp
loop b != 0
a%b
return a
*/

#include <stdio.h>
#include <stdlib.h>

int pgcd(int a, int b) {
	int tmp;

	while (b != 0) {
		tmp = b;
		b = a % b;
		a = tmp;
	}
	return (a);
}

int main(int ac, char **av) {
	if (ac == 3)
		printf("%d", pgcd(atoi(av[1]), atoi(av[2])));
	printf("\n");
}