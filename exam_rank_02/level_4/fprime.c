/*
Assignment name  : fprime
Expected files   : fprime.c
Allowed functions: printf, atoi
--------------------------------------------------------------------------------

Write a program that takes a positive int and displays its prime factors on the
standard output, followed by a newline.

Factors must be displayed in ascending order and separated by '*', so that
the expression in the output gives the right result.

If the number of parameters is not 1, simply display a newline.

The input, when there is one, will be valid.

Examples:

$> ./fprime 225225 | cat -e
3*3*5*5*7*11*13$
$> ./fprime 8333325 | cat -e
3*3*5*5*7*11*13*37$
$> ./fprime 9539 | cat -e
9539$
$> ./fprime 804577 | cat -e
804577$
$> ./fprime 42 | cat -e
2*3*7$
$> ./fprime 1 | cat -e
1$
$> ./fprime | cat -e
$
$> ./fprime 42 21 | cat -e
$
*/

#include <stdio.h>
#include <stdlib.h>

void	fprime(int n) //Define a function that displays the prime factors of a number
{
	int		i = 2; //Start with the first prime number

	if (n == 1) //If input is `1`, print it
		printf("%d", n);
	while (n > 1) //Loop until n == 1
	{
		if (n % i == 0) //If there are no remainders, a prime factor is found in `i`
		{
			printf("%d", i);
			n /= i; 
			if (n > 1) //If after `n /= i`, n is greater than 1, it implies another prime factor is to be found
				printf("*");
		}
		else
			i++; //Increment if needed, to find the next prime factor where there are no remainders
	}
}

int		main(int argc, char **argv)
{
	int		n;

	if (argc == 2)
	{
		n = atoi(argv[1]);
		if (n > 0)
			fprime(n);
	}
	printf("\n");
	return (0);
}