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
#include <limits.h> //To use the INT_MAX macro

void	ft_putnbr(unsigned int n) //Define a function that takes an integer. The return type is `void` because the function will print the character `res` to the STDOUT
{
	char digit; //Declare a character variable to store the converted result from integer to character representation of that integer
		
	if (n > 9) //Checks if `n` consists of more than `1` digit
		ft_putnbr(n / 10); //If so, it calls itself recursively with `n / 10`, effectively removing the last digit of `n`, then passing the remaining digits to the next recursive call
	digit = (n % 10) + '0'; //Calculates the remainder of `n / 10`, effectively giving us the last digit of `n`, then add the ASCII value of `0`, effectively giving us the character representation of the digit, before assigning it to `res`
	write(1, &digit, 1); //Writes the character to the STDOUT
}

int		ft_atoi(const char *str) //Define a function that takes a string representation of an integer, and converts it into an actual integer value. `const char *` type because we are not modifying the content of the string
{
	int	 sign; //To store the sign of the integer value, and account for the `-` sign if the number is negative
	int	 res; //To store the integer value that will be processed and converted from the input string

	sign = 1; //Initialised to `1` because the number is assumed to be `positive` until a negative sign is encounted in the input string
	res = 0; //Initialised to `0` because the conversion starts from th leftmost digit and accumulates the value as it processess each digit in the string. See #1
	if (*str == ' ' || *str == '+' || (*str >= 9 && *str <= 13)) //Skips whitespace characters from the begining of the string, until a non-whitespace character is found, including the '+' as positive values do not need this
		str++; //Move the the next character to search for a non-whitespace character
	if (*str == '-') //Indicates a number is negative
	{
		sign = -1;
		str++;
	}
	while(*str && (*str >= '0' && *str <= '9')) //Check if the character is a digit 0-9
		res = (res * 10) + (*str++ - '0'); //Assign to `res` the converted string representation of an integer into an actual integer value. See #2
	return (res * sign); //If conversion successful, return the result
}

void	tab_mult(int n) //Define a function that will display the mult table
{
	int		iter = 0; //To keep track of the iterations, we need 9
	int		res; //To store the sult results

	if (n > (INT_MAX / 9)) //Check for int overflow, e.g., if `n * 9` is greater than the max int value. So, if n > 238609294 (max allowable number for n * 9), it will cause an overflow
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
		if (n >= 0) //0 is still considered as a poitive number
			tab_mult(n);
	}
	else
		write(1, "\n", 1);
	return (0);
}