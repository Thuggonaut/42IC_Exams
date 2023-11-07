/*
Assignment name  : paramsum
Expected files   : paramsum.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that displays the number of arguments passed to it, followed by
a newline.

If there are no arguments, just display a 0 followed by a newline.

Example:

$>./paramsum 1 2 3 5 7 24
6
$>./paramsum 6 12 24 | cat -e
3$
$>./paramsum | cat -e
0$
$>
*/

#include <unistd.h>

void	ft_putnbr(int n) //Define a function that converts the integer into its character representation
{
	char	nbr; //To store the char representation of the integer value

	if (n > 9) //Check if the number is more than one digit
		ft_putnbr(n / 10); //The recursion removes the rightmost digit in every iteration until n < 10
	nbr = (n % 10) + '0'; //Convert the single digit into a character
	write(1, &nbr, 1); //Print the character. If called in recursion, at base case, it will print n starting from the leftmost digit, towards the right until all digits are printed
}

int	main(int argc, char **argv)
{
	ft_putnbr(argc - 1); //-1 to account for the executable name
	write(1, "\n", 1);
	return (0);
}