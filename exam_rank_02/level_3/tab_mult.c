/*
Assignment name  : tab_mult
Expected files   : tab_mult.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that displays a number's multiplication table.

The parameter will always be a strictly positive number that fits in an int,
and said number times 9 will also fit in an int.

If there are no parameters, the program displays \n.

Examples:

$>./tab_mult 9
1 x 9 = 9
2 x 9 = 18
3 x 9 = 27
4 x 9 = 36
5 x 9 = 45
6 x 9 = 54
7 x 9 = 63
8 x 9 = 72
9 x 9 = 81
$>./tab_mult 19
1 x 19 = 19
2 x 19 = 38
3 x 19 = 57
4 x 19 = 76
5 x 19 = 95
6 x 19 = 114
7 x 19 = 133
8 x 19 = 152
9 x 19 = 171
$>
$>./tab_mult | cat -e
$
$>
*/

#include <unistd.h>

void	ft_putnbr(unsigned int n) //Define a function that takes an integer. The return type is `void` because the function will print the character `res` to the STDOUT
{
	char digit; //Declare a character variable to store the converted result from integer to character representation of that integer
		
	if (n > 9) //Checks if `n` consists of more than `1` digit
		ft_putnbr(n / 10); //If so, it calls itself recursively with `n / 10`, effectively removing the last digit of `n`, then passing the remaining digits to the next recursive call
	digit = (n % 10) + '0'; //Calculates the remainder of `n / 10`, effectively giving us the last digit of `n`, then add the ASCII value of `0`, effectively giving us the character representation of the digit, before assigning it to `res`
	write(1, &digit, 1); //Writes the character to the STDOUT
}

int		ft_atoi(char *s)
{
	int		res = 0;

	while (*s == ' ' || *s == '+' || (*s >= 9 && *s <= 13))
		s++;
	while (*s)
	{
		if (*s >= '0' && *s <= '9')
			res = (res * 10) + (*s++ - '0');
		else 
			return (0);
	}
	return (res);
}

void		tab_mult(int n)
{
	int		iter = 0;
	int		res;

	if (n > (2147483647 / 9))
		return ;
	while (iter++ < 9)
	{
		res = iter * n;
		ft_putnbr(iter);
		write(1, " x ", 3);
		ft_putnbr(n);
		write(1, " = ", 3);
		ft_putnbr(res);
		write(1, "\n", 1);
	}
}

int		main(int argc, char **argv)
{
	int		n;
	
	if (argc == 2)
	{
		n = ft_atoi(argv[1]);
		if (n > 0)
			tab_mult(n);
	}
	write(1, "\n", 1);
	return (0);
}