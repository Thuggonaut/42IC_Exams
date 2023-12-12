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

#include <stdio.h>
#include <stdlib.h>

unsigned int	gcd(unsigned int a, unsigned int b) //Define a function calculates the Highest Common Factor (HCF) or Greatest Common Divisor (GCD) of two numbers using the Euclidean algorithm
{
	unsigned int	temp;

	while (b != 0) //The Euclidean algorithm is used to find the HCF, which is the largest number that divides both a and b
	{
		//Calculate the remainder of a divided by b and swaps the values of a and b in each iteration until b becomes 0. At that point, a contains the HCF
		temp = b;
		b = a % b;
		a = temp;
	}
	return (a);
}

int main(int argc, char **argv) 
{
	if (argc != 3)
	{
		printf("\n");
		return (1);
	}

	unsigned int n1 = atoi(argv[1]);
	unsigned int n2 = atoi(argv[2]);
	unsigned int res = gcd(n1, n2);

	printf("%d\n", res);
	return (0);
}